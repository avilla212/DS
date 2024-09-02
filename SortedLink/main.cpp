#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data = 0, Node* next = nullptr){
        this->data = data;
        this->next = next;
    }
};

// Singly linked list
struct LinkedList{
    Node* head;
    Node* tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        int count = 0;
    }   

    void push(){
        int data;
        
        while(data != -1 ){
            cout << "Enter a number: ";
            cin >> data;
            if(data == -1){
                break;
            }

            Node* newNode = new Node(data);

            if(head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            delete newNode;
        }
    }

    void print(){
        Node* curr = head;
        if(curr == nullptr){
            cout << "List is empty" << endl;
            return;
        }
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        delete curr;
    }

    void sort(){
        if(head == nullptr){
            cout << "List is empty, can't sort" << endl;
            return;
        }

        if(head->next == nullptr){
            cout << "List is already sorted" << endl;
            return;
        }
        // Vector to store node values, sort the vector and create a new linked list
        vector<int>* v = new vector<int>;
        Node* curr = head;

        while(curr != nullptr){
            v->push_back(curr->data);
            curr = curr->next;
        }

        int j = 0;
        int i = 0;
        int temp = 0;

        while(i < v->size()){
            j = i;
            while(j > 0 && v->at(j) < v->at(j - 1)){
                temp = v->at(j);
                v->at(j) = v->at(j - 1);
                v->at(j - 1) = temp;
                j--;
            }
            i++;
        }

        Node* newHead = new Node(v->at(0));
        Node* newTail = newHead;

        for(int i = 1; i < v->size(); i++){
            Node* newNode = new Node(v->at(i));
            newTail->next = newNode;
            newTail = newNode;
        }

        head = newHead;
        
    }

    ~LinkedList(){
        Node* curr = head;
        while(curr != nullptr){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};


int main(void){

    LinkedList list;
    cout << "Sort function: ";
    list.sort();

    cout << "Push function: ";
    list.push();

    cout << "After adding elements: ";
    list.print();

    cout << "Sort function: ";
    list.sort();
    list.print();

    return 0;
}