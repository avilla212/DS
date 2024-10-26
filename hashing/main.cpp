// Hash table that use chaining for collision resolution
// use an int for the key and string for the value

// Three components of hashing

/*


Key: 
- fed as input for the hash function and determines the index for storage 

Hash Function: 
- The hash function receives the input key and returns the index of an element in the array

- Integer universe assumption
    - keys are integers within a certain range so we can use basic hashing operations like  multiplication and division

- Hashing by division
    - uses keys remaining values after dividing it by the arrays size as the index. Performs best when an array size is a prime number

- Hashing by multiplication:
    - multiplies the key by a constant between 0 and 1 before the fractional portion of the outcome



Hash Table:
- maps key values to using a special function



Collision:
- hashing process that generates a small number for a big key so there is a possibility that two keys coudl produce hte same value.

Collison Resolution:
- Open addressing: 
    - looking for the following empty space in the table. if the first slot is taken, the hash function is applied to subsequent slots 
    until one is left empty

- Chaining:
    - uses a linked list of objecs that hash to each slow in the table.two keys are included in the linked list if they hash to the same slot 
    this is very good
*/

#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
    int key;
    string value;
    Node* next;

    Node(int key, string value) : key(key), value(value), next(nullptr) {}
};

class LinkedList
{
    public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void const insert(int key, string value){ 
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    };

    string const find(int key){
        Node* curr = head;

        while(curr){
            if (curr->key == key){
                return curr->value;
            }
            curr = curr->next;
        }

        return "Not Found";
    }

    bool remove(int key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr){
            if (curr->key == key){
                if (prev == nullptr){
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }

        return false;
    }

    void const print(){
        Node* curr = head;
        while (curr){
            cout << curr->key << ":" << curr->value << "->";
            curr = curr->next;
        }

    }
};

class HashTable
{
    private:
        LinkedList* table;
        int size;

        int hash(int key){
            return key % size;
        }

    public:
        HashTable(int size) : size(size) {
            table = new LinkedList[size];
        }

        void const insert(int key, string value){
            int index = hash(key);
            table[index].insert(key,value);
        }

        string const find(int key){
            int index = hash(key);

            return table[index].find(key);
        }

        bool remove(int key){
            int index = hash(key);
            return table[index].remove(key);
        }

        void const print(){
            for (int i = 0; i < size; i++){
                cout << "Bucket " << i << ": ";
                table[i].print();
            }
        }


};

int main(void){
    HashTable ht(10);
    
    int key;
    string value;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add (Key, Value)\n";
        cout << "2. Lookup (Key)\n";
        cout << "3. Delete (Key)\n";
        cout << "4. Print Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                ht.insert(key, value);
                break;
            case '2':
                cout << "Enter key: ";
                cin >> key;
                cout << "Lookup result: " << ht.find(key) << endl;
                break;
            case '3':
                cout << "Enter key: ";
                cin >> key;
                if (ht.remove(key)) {
                    cout << "Key " << key << " deleted successfully." << endl;
                } else {
                    cout << "Key " << key << " not found." << endl;
                }
                break;
            case '4':
                ht.print();
                break;
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');
}