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

void const menu();

class Node {
public:
    int key;
    string value;
    Node* next;

    Node(int key, string value) : key(key), value(value), next(nullptr) {}
};


class LinkedList 
{
public:
    Node* head;

    LinkedList() : head(nullptr) {}
    
    void insert(int key, string value) { // Insert at beginning
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    string find(int key) { // Find by key
        Node* current = head;

        while (current) {
            if (current->key == key) { // Key found
                return current->value;
            }
            current = current->next;
        }
        return "Not found";
    }

    bool remove(int key) { // Remove by key
        Node* current = head;
        Node* previous = nullptr; // Keep track of prev node to update next pointer

        while (current) {
            if (current->key == key) {
                if (previous == nullptr) { // If key is in head node 
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current; // Free memory
                return true;
            }
            previous = current; // Update prev to stay one step behind
            current = current->next;
        }
        return false;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->key << ":" << current->value << " -> ";
            current = current->next;
        }
        cout << "None\n";
    }
};

class HashTable 
{
private:
    LinkedList* table;
    int size;

    int hashFunction(int key) {
        return key % size; // Modulus hash function
    }

public:
    HashTable(int size) : size(size) {
        table = new LinkedList[size];
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].insert(key, value); // Insert into linked list
    }

    string find(int key) {
        int index = hashFunction(key);
        return table[index].find(key); // Find in linked list
    }

    bool remove(int key) {
        int index = hashFunction(key);
        return table[index].remove(key); // Remove from linked list
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            table[i].print();
        }
    }
};

void const menu() {
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

int main(void) 
{
    menu();
}

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 1 
// Enter key: 1
// Enter value: alex

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 4
// Bucket 0: None
// Bucket 1: 1:alex -> None
// Bucket 2: None
// Bucket 3: None
// Bucket 4: None
// Bucket 5: None
// Bucket 6: None
// Bucket 7: None
// Bucket 8: None
// Bucket 9: None

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 1
// Enter key: 2
// Enter value: james

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 4
// Bucket 0: None
// Bucket 1: 1:alex -> None
// Bucket 2: 2:james -> None
// Bucket 3: None
// Bucket 4: None
// Bucket 5: None
// Bucket 6: None
// Bucket 7: None
// Bucket 8: None
// Bucket 9: None

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 2
// Enter key: 2
// Lookup result: james

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 3
// Enter key: 2
// Key 2 deleted successfully.

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 4
// Bucket 0: None
// Bucket 1: 1:alex -> None
// Bucket 2: None
// Bucket 3: None
// Bucket 4: None
// Bucket 5: None
// Bucket 6: None
// Bucket 7: None
// Bucket 8: None
// Bucket 9: None

// Menu:
// 1. Add (Key, Value)
// 2. Lookup (Key)
// 3. Delete (Key)
// 4. Print Hash Table
// 5. Exit
// Enter choice: 5