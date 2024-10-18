#include <iostream>
#include <string>   

using namespace std;

// Bin Tree Node
struct Node{
    string name;
    int weight;

    Node* left;
    Node* right;

    Node(string name, int weight) : name(name), weight(weight), left(nullptr), right(nullptr) {}

};

// Binary Search Tree
class BST{
    private:
    Node* root;

    // Helper method for recursive insertion
    Node* insert(Node* node, const string& name, int weight) {
        if (node == nullptr) {
            // Create a new node if the correct position is found
            return new Node(name, weight);
        }
        if (name < node->name) {
            // Insert in the left subtree
            node->left = insert(node->left, name, weight);
        } else if (name > node->name) {
            // Insert in the right subtree
            node->right = insert(node->right, name, weight);
        }
        // If the name is the same, do not insert it again (keep names unique)
        return node;
    }

    // Preorder: Root, Left, Right
    void preorder(Node* node){
        if(node){
            cout << node->name << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Inorder: Left, Root, Right
    void inorder(Node* node){
        if(node){
            inorder(node->left);
            cout << node->name << " ";
            inorder(node->right);
        }

    }

    // Postorder: Left, Right, Root
    void postorder(Node* node){
        if(node){
            postorder(node->left);
            postorder(node->right);
            cout << node->name << " ";
        }
    }

    // Print height
    int printHeight(Node* node){
        if(!node){
            return -1; // Empty tree
        }

        int leftHeight = printHeight(node->left);
        int rightHeight = printHeight(node->right);

        return 1 + max(leftHeight, rightHeight); // Return the max height
    }

    // Number of leaves
    int numLeaves(Node* node){
        if(!node){
            return 0; // Empty tree
        }

        if(!node->left && !node->right){
            return 1; // Just one leaf
        }else{
            return numLeaves(node->left) + numLeaves(node->right); // Recursion
        }
    }

    // Search for a name and return the weight
    Node* search(Node* node, string name){
        if(!node){
            return nullptr;
        } 

        if(node->name == name){
            return node;
        }

        if(node->name < name){
            return search(node->right, name); // Search right first if name is greater
        }else{
            return search(node->left, name); // Search left first if name is less
        }
    }

    // Get the lowest weight in the BST, return name and weight
    Node* getLowestWeight(Node* node){
        if(!node){
            return nullptr;
        }

        Node* minNode = node;
        Node* leftMin = getLowestWeight(node->left);
        Node* rightMin = getLowestWeight(node->right);

        if(leftMin && leftMin->weight < minNode->weight){ // Compare left
            minNode = leftMin;
        }

        if(rightMin && rightMin->weight < minNode->weight){ // Compare right
            minNode = rightMin;
        }

        return minNode;

    }

    // Get the first name in the alphabet
    Node* firstNameInAlphabet(Node* node){
        if(!node){
            return nullptr;
        }

        if(!node->left){
            return node;
        }else{
            return firstNameInAlphabet(node->left);
        }
    }

    public:

    // Public constructor
    BST() : root(nullptr) {}
    
    // Public insert
    void insert(const string& name, int weight){
        root = insert(root, name, weight);
    }

    // Public preorder
    void preorder(){
        preorder(root);
    }

    // Public inorder
    void inorder(){
        inorder(root);
    }

    // Public postorder
    void postorder(){
        postorder(root);
    }

    // Public printHeight
    int printHeight(){
        return printHeight(root);
    }

    // Public numLeaves
    int numLeaves(){
        return numLeaves(root);
    }

    // Public search
    Node* search(string name){
        return search(root, name);
    }

    // Public getLowestWeight
    Node* getLowestWeight(){
        return getLowestWeight(root);
    }

    // Public firstNameInAlphabet
    Node* firstNameInAlphabet(){
        return firstNameInAlphabet(root);
    }

};


int main(void){
    BST bst;

    // TEST 1
    bst.insert("Mike", 220);
    bst.insert("Brianna", 120);
    
    bst.insert("Stephanie", 130);
    bst.insert("Karl", 109);

    bst.insert("Roger", 199);
    bst.insert("Zelda", 145);
    bst.insert("Chuck", 145);

    cout << "Preorder: ";
    bst.preorder();
    cout << endl;

    cout << "Inorder: ";
    bst.inorder();
    cout << endl;

    cout << "Postorder: ";
    bst.postorder();
    cout << endl;

    cout << "Height: " << bst.printHeight() << endl;

    cout << "Number of leaves: " << bst.numLeaves() << endl;
    
    cout << "Lightest: " << bst.getLowestWeight()->name << endl;

    cout << "First name in alphabet: " << bst.firstNameInAlphabet()->name << endl;
    
    return 0;
    
}

// Output:

// TEST 1
// Preorder: Mike Brianna 
// Inorder: Brianna Mike
// Postorder: Brianna Mike
// Height: 1
// Number of leaves: 1
// Lightest: Brianna
// First name in alphabet: Brianna

// TEST 2
// Preorder: Mike Brianna Karl Stephanie 
// Inorder: Brianna Karl Mike Stephanie
// Postorder: Karl Brianna Stephanie Mike
// Height: 2
// Number of leaves: 2
// Lightest: Karl
// First name in alphabet: Brianna

// TEST 3
// Preorder: Mike Brianna Karl Chuck Stephanie Roger Zelda 
// Inorder: Brianna Chuck Karl Mike Roger Stephanie Zelda
// Postorder: Chuck Karl Brianna Roger Zelda Stephanie Mike
// Height: 3
// Number of leaves: 3
// Lightest: Karl
