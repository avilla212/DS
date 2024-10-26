#include <iostream>
#include <string>

using namespace std;

class HashTable {

    private:
    
    static const int TABLESIZE = 27;
    int arr[TABLESIZE];

    public:

    // Constructor
    HashTable() {
        for (int i = 0; i < TABLESIZE; i++) {
            arr[i] = 0;
        }
    }

    int hash(int key){
        return key % TABLESIZE;
    }

    // Linear probing to handle collisions
    int linearProbing(int key){
        int index = hash(key);
        int start = index;

        do {
            if(arr[index] == 0){
                return index;
            }
            index = (index + 1) % TABLESIZE; // Circular array
        } while (index != start); // If we reach the start again, then the array is full

        return -1;
    }

    // Insert key into the hash table
    int insert(int key){
        if (key == 0) {
            return -1;
        }

        int index = hash(key);

        if (arr[index] == 0){ // Empty
            arr[index] = key;
        } else { // Collision

            index = linearProbing(key);
            if (index == -1){
                return -1;
            }
            
            arr[index] = key; // Insert the key
        }

        return index;
    }

    // Find key in the hash table
    int find(int key){
        int index = hash(key);
        int start = index;

        do {
            if (arr[index] == key){
                cout << "Key " << key << " found at index " << index << endl;
                return index;
            }
            index = (index + 1) % TABLESIZE;
        } while (index != start);

        cout << "Key " << key << " not found in the table." << endl;
        return -1;
    }

    // Grab user input
    void grabUserInput(HashTable& ht){
        int key;
        cout << "Enter keys to insert into the hash table (-1 to stop): ";
        cin >> key;

        while (key != -1) {
            int result = ht.insert(key);
            if (result == -999) {
                cout << "The table is full. No more keys can be added." << endl;
                break;
            } else if (result != -1) {
                cout << "Key " << key << " inserted at index " << result << endl;
            }
            cout << "Enter next key (-1 to stop): ";
            cin >> key;
        }
    }

};

int main(void){
    HashTable ht;

    ht.grabUserInput(ht);

    ht.find(1);
    ht.find(2);
    ht.find(3);
    ht.find(4);

}


//  TEST 1

// Enter keys to insert into the hash table (-1 to stop): 1
// Key 1 inserted at index 1
// Enter next key (-1 to stop): 2
// Key 2 inserted at index 2
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 3
// Enter next key (-1 to stop): 1
// Key 1 inserted at index 4
// Enter next key (-1 to stop): 2
// Key 2 inserted at index 5
// Enter next key (-1 to stop): 3 
// Key 3 inserted at index 6
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 7
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 8
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 9
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 10
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 11
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 12
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 13
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 14
// Enter next key (-1 to stop): 33
// Key 33 inserted at index 15
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 16
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 17
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 18
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 19
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 20
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 21
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 22
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 23
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 24
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 25
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 26
// Enter next key (-1 to stop): 3
// Key 3 inserted at index 0
// Enter next key (-1 to stop): -1
// Key 1 found at index 1
// Key 2 found at index 2
// Key 3 found at index 3
// Key 4 not found in the table.