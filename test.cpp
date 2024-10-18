#include <iostream>

using namespace std;

class Node{

    private:
    int data;
    Node* next;

    public:
    Node(int data) : data(data), next(nullptr) {}
        
};

class LL{

    private:
    Node* head;

    public:
    LL() : head(nullptr) {}
    Node* curr = head;

    void insert(int data){
        if(!head){
            head = new Node(data);
            curr = head;
        }else{
            curr->next = new Node(data);
            curr = curr->next;
        }
    }



}


int main(void){

}