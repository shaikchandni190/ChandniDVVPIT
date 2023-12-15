#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Definition for a node in the expression tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    TreeNode* root;

public:
    ExpressionTree() : root(nullptr) {}

    // Function to check if a character is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    // Function to construct an expression tree from a postfix expression
    TreeNode* constructTree(string postfix) {
        stack<TreeNode*> st;

        for (char c : postfix) {
            if (isalnum(c)) {
                st.push(new TreeNode(c));
            } else if (isOperator(c)) {
                TreeNode* right = st.top();
                st.pop();
                TreeNode* left = st.top();
                st.pop();

                TreeNode* newNode = new TreeNode(c);
                newNode->left = left;
                newNode->right = right;

                st.push(newNode);
            }
        }

        root = st.top();
        return root;
    }

    // Recursive function for inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Recursive function for preorder traversal
    void preorderTraversal(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Recursive function for postorder traversal
    void postorderTraversal(TreeNode* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    // Public method to perform inorder traversal
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    // Public method to perform preorder traversal
    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    // Public method to perform postorder traversal
    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    ExpressionTree expTree;

    // Example postfix expression: "ab+c*"
    string postfixExpression = "ab+c*";

    // Construct the expression tree
    expTree.constructTree(postfixExpression);

    // Perform traversals
    cout << "Inorder traversal: ";
    expTree.inorder();

    cout << "Preorder traversal: ";
    expTree.preorder();

    cout << "Postorder traversal: ";
    expTree.postorder();

    return 0;
}