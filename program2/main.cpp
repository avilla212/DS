#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int weight;
    Person* nextName;
    Person* nextWeight;

    Person(string name, int weight)
        : name(name), weight(weight), nextName(nullptr), nextWeight(nullptr) {}
};

class SortedList {
private:
    Person* headName;
    Person* headWeight;

public:
    SortedList() : headName(nullptr), headWeight(nullptr) {}

    // Insert a new person into the sorted list
    void insert(string name, int weight) {
        Person* newPerson = new Person(name, weight);
        insertSortedName(newPerson);
        insertSortedWeight(newPerson);
    }

    /// Insert a new person into the sorted list by name
    void insertSortedName(Person* newPerson) {

        // If the list is empty or the new person should be the first in the list
        if (!headName || newPerson->name < headName->name) {
            newPerson->nextName = headName;
            headName = newPerson;

        // Otherwise, find the correct position in the list
        } else {
            Person* current = headName;
            while (current->nextName && current->nextName->name < newPerson->name) {
                current = current->nextName;
            }
            newPerson->nextName = current->nextName;
            current->nextName = newPerson;
        }
    }

    // Insert a new person into the sorted list by weight
    void insertSortedWeight(Person* newPerson) {
        
        // If the list is empty or the new person should be the first in the list
        if (!headWeight || newPerson->weight < headWeight->weight) {
            newPerson->nextWeight = headWeight;
            headWeight = newPerson;
        // Otherwise, find the correct position in the list
        } else {
            Person* current = headWeight;
            while (current->nextWeight && current->nextWeight->weight < newPerson->weight) {
                current = current->nextWeight;
            }
            newPerson->nextWeight = current->nextWeight;
            current->nextWeight = newPerson;
        }
    }

    // Print the list sorted by name
    void printByName() {
        Person* current = headName;
        cout << "Names & weights sorted(ascending) by name: ";
        while (current) {
            cout << current->name << " - " << current->weight;
            if (current->nextName) {
                cout << ", ";
            }
            current = current->nextName;
        }
        cout << endl;
    }

    // Print the list sorted by weight
    void printByWeight() {
        Person* current = headWeight;
        cout << "Names & weights sorted(ascending) by weight: ";
        while (current) {
            cout << current->name << " - " << current->weight;
            if (current->nextWeight) {
                cout << ", ";
            }
            current = current->nextWeight;
        }
        cout << endl;
    }
};

int main() {
    SortedList list;
    string name;
    int weight;

    cout << "Enter data for 15 people (name and weight):" << endl;
    for (int i = 0; i < 15; i++) {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter weight: ";
        cin >> weight;
        cin.ignore();
        list.insert(name, weight);
    }

    list.printByName();
    list.printByWeight();

    return 0;
}
