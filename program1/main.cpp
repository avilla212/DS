#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

struct DoubleLL{
    Node* head;
    Node* tail;
    int count = 0;

    DoubleLL(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push(int number){
        Node* newNode = new Node(number);
        if (this->head == nullptr){
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->count++;
    }

    int pop(){
        if (this->tail == nullptr) return -1; // error case, stack underflow

        int data = this->tail->data;
        Node* temp = this->tail;
        this->tail = this->tail->prev;
        if (this->tail) this->tail->next = nullptr;
        else this->head = nullptr;
        delete temp;
        this->count--;
        return data;
    }

    void evaluatePostfix(){
        string input;
        cout << "Enter postfix expression (or 'exit' to quit): ";
        getline(cin, input);

        while(input != "exit"){
            stringstream ss(input);
            string token;
            while (ss >> token) {
                stringstream convert(token);
                int number;
                if (convert >> number) {
                    push(number);
                } else if (token == "+" || token == "-" || token == "*" || token == "/") {
                    int right = pop();
                    int left = pop();
                    switch (token[0]) {
                        case '+': push(left + right); break;
                        case '-': push(left - right); break;
                        case '*': push(left * right); break;
                        case '/': if (right != 0) push(left / right); break; // handle division by zero
                    }
                }
            }

            cout << "Result: " << pop() << endl;
            cout << "Enter postfix expression (or 'exit' to quit): ";
            getline(cin, input);
        }
    }

    void print(){
        Node* current = this->head;
        cout << "Stack elements: ";
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(void){
    DoubleLL list;
    list.evaluatePostfix();
    return 0;
}
