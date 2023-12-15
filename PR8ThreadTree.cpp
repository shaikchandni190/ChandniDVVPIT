#include <iostream>

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded; // Indicates if the right pointer is a thread

    Node(int value) : data(value), left(nullptr), right(nullptr), isThreaded(false) {}
};

// Threaded Binary Tree Class
class ThreadedBinaryTree {
private:
    Node* root;

    // Helper function to perform in-order threading
    Node* threadedInOrder(Node* currentNode, Node* &prev) {
        if (currentNode == nullptr)
            return nullptr;

        currentNode->left = threadedInOrder(currentNode->left, prev);

        // If the right child is null, thread it to the successor
        if (currentNode->right == nullptr) {
            currentNode->right = prev;
            currentNode->isThreaded = true;
        }

        // Update the predecessor
        prev = currentNode;

        currentNode->right = threadedInOrder(currentNode->right, prev);

        return currentNode;
    }

public:
    // Constructor
    ThreadedBinaryTree() : root(nullptr) {}

    // Public function to perform in-order threading
    void threadInOrder() {
        Node* prev = nullptr;
        root = threadedInOrder(root, prev);
    }

    // Public function to perform in-order traversal using threads
    void inOrderTraversal() {
        Node* current = leftMost(root);
        while (current != nullptr) {
            std::cout << current->data << " ";

            // If the right child is a thread, move to the in-order successor
            if (current->isThreaded)
                current = current->right;
            else
                current = leftMost(current->right);
        }
        std::cout << std::endl;
    }

    // Helper function to find the leftmost node in the subtree
    Node* leftMost(Node* node) {
        while (node != nullptr && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Public function to insert a value into the tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Helper function to insert a value recursively
    Node* insertRecursive(Node* currentNode, int value) {
        if (currentNode == nullptr)
            return new Node(value);

        if (value < currentNode->data) {
            currentNode->left = insertRecursive(currentNode->left, value);
        } else if (value > currentNode->data) {
            currentNode->right = insertRecursive(currentNode->right, value);
        }

        return currentNode;
    }
};

// Main function
int main() {
    ThreadedBinaryTree threadedTree;

    // Inserting values into the threaded binary tree
    threadedTree.insert(5);
    threadedTree.insert(3);
    threadedTree.insert(7);
    threadedTree.insert(2);
    threadedTree.insert(4);
    threadedTree.insert(6);
    threadedTree.insert(8);

    // Threading the binary tree for in-order traversal
    threadedTree.threadInOrder();

    // Performing in-order traversal using threads
    std::cout << "In-order Traversal: ";
    threadedTree.inOrderTraversal();

    return 0;
}