#include <iostream>

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree Class
class BinaryTree {
private:
    Node* root;

    // Private recursive function to insert a value into the tree
    Node* insertRecursive(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return new Node(value);
        }

        if (value < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, value);
        } else if (value > currentNode->data) {
            currentNode->right = insertRecursive(currentNode->right, value);
        }

        return currentNode;
    }

    // Private recursive function to display the tree in-order
    void displayInOrder(Node* currentNode) {
        if (currentNode != nullptr) {
            displayInOrder(currentNode->left);
            std::cout << currentNode->data << " ";
            displayInOrder(currentNode->right);
        }
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Public function to insert a value into the tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Public function to display the tree
    void display() {
        displayInOrder(root);
        std::cout << std::endl;
    }
};

// Main function
int main() {
    BinaryTree binaryTree;

    // Inserting values into the tree
    binaryTree.insert(5);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(4);
    binaryTree.insert(6);
    binaryTree.insert(8);

    // Displaying the tree
    std::cout << "Binary Tree: ";
    binaryTree.display();

    return 0;
}