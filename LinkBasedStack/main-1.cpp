#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = 0){
        this->data = data;
        this->next = next;
    }
};

class Stack
{
private:
    Node *head;
    int count = 0;
public:

    Stack()
    {
        head = 0;
    }
    
    void push(int data)
    {
        Node *temp = new Node(data);
        if(isEmpty()){
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }

        count++;
    }

    int pop()
    {
        if(isEmpty())
        {
            return -999;
        } else {
            int returnData = head->data;
            Node *temp = head;

            head = head->next;
            count--;

            delete temp;

            return returnData;
        }
    }

    void print()
    {
        cout << "The stack: ";

        for (Node *temp = head; temp != 0; temp = temp->next)
        {
            cout << temp->data << " ";
        }

        cout << endl;
    }

    bool isEmpty()
    {
        return count == 0;
    };

};

int main(){
    Stack stack;

    cout << "Is Empty: " << stack.isEmpty() << endl;

    stack.push(10);
    stack.print();

    stack.push(25);
    stack.push(30);
    stack.push(35);
    stack.print();

    cout << "Popping: " << stack.pop() << endl;
    stack.print();
    
    return 0;
}