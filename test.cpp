#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

class LL
{
    private:
        Node* head;
        
        int size;
    public:
        LL() : size(0),head(nullptr) {}

        void insert(int val)
        {
            Node* newNode = new Node(val);
            Node* curr = head;

            if (size == 0){
                head = newNode;
            } else {
                while(curr->next){
                    curr = curr->next;
                } 
                curr->next = newNode;
            }
        }

        // reverse the linked list
        void reverse()
        {
            Node* curr = head;
            Node* prev = nullptr;

            while(curr){
                Node* temp = curr->next; //nullptr 1->2->3->4->5
                curr->next = prev; // nullptr <-1
                prev = curr;
                curr = temp;
            }
        }

        void print()
        {
            Node* curr = head;
            while(curr){
                cout << curr->val << " ";
                curr = curr->next;
            }
        }
};