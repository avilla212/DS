#include <iostream>
#include <string>

using namespace std;

class HashTable {

    private:
    
    static const int TABLESIZE = 27;
    int arr[TABLESIZE];

    public:
    HashTable() {
        for (int i = 0; i < TABLESIZE; i++) {
            arr[i] = 0;
        }
    }

    int hash(int key){
        return key % TABLESIZE;
    }

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

    void display(){
        for (int i = 0; i < TABLESIZE; i++){
            cout << i << " -> " << arr[i] << endl;
        }
    }

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
    ht.display();

    ht.find(1);
    ht.find(2);
    ht.find(3);
    ht.find(4);

    return 0;
}