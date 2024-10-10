#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Graph {
private:
    int** adjMatrix;
    string* labels;
    int size;

public:
    Graph(int n) : size(n) {
        // Initialize the adjacency matrix
        adjMatrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            adjMatrix[i] = new int[n];
            fill(adjMatrix[i], adjMatrix[i] + n, 0);
        }

        // Initialize the labels array
        labels = new string[n];
    }

    ~Graph() {
        // Clean up dynamically allocated memory
        for (int i = 0; i < size; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] labels;
    }

    void setLabels() {
        cout << "Enter labels for the points (one label per line):" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> labels[i];
        }
    }

    void addEdge() {
        string from, to;
        cout << "Enter the labels of two points to connect (from to): ";
        cin >> from >> to;

        int fromIndex = find(labels, labels + size, from) - labels;
        int toIndex = find(labels, labels + size, to) - labels;

        if (fromIndex < size && toIndex < size) {
            adjMatrix[fromIndex][toIndex] = 1; // Assuming unidirectional for simplicity
            cout << "Edge added from " << from << " to " << to << "." << endl;
        } else {
            cout << "Invalid labels provided." << endl;
        }
    }

    void listEdges() {
        cout << "List of all edges in the graph:" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (adjMatrix[i][j] != 0) {
                    cout << labels[i] << " -> " << labels[j] << endl;
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of points in the graph: ";
    cin >> n;

    Graph g(n);
    g.setLabels();

    char continueAdding = 'y';
    do {
        g.addEdge();
        cout << "Add another edge? (y/n): ";
        cin >> continueAdding;
    } while (continueAdding == 'y' || continueAdding == 'Y');

    g.listEdges();

    return 0;
}
