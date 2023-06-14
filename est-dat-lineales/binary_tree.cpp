#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary tree class
class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    // Insert a node into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Helper function to recursively insert a node
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Search for a value in the binary tree
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Helper function to recursively search for a value
    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // Perform an inorder traversal of the binary tree
    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    // Helper function to recursively perform an inorder traversal
    void inorderRecursive(Node* current) {
        if (current != nullptr) {
            inorderRecursive(current->left);
            cout << current->data << " ";
            inorderRecursive(current->right);
        }
    }

    // Perform a preorder traversal of the binary tree
    void preorderTraversal() {
        preorderRecursive(root);
        cout << endl;
    }

    // Helper function to recursively perform a preorder traversal
    void preorderRecursive(Node* current) {
        if (current != nullptr) {
            cout << current->data << " ";
            preorderRecursive(current->left);
            preorderRecursive(current->right);
        }
    }

    // Perform a postorder traversal of the binary tree
    void postorderTraversal() {
        postorderRecursive(root);
        cout << endl;
    }

    // Helper function to recursively perform a postorder traversal
    void postorderRecursive(Node* current) {
        if (current != nullptr) {
            postorderRecursive(current->left);
            postorderRecursive(current->right);
            cout << current->data << " ";
        }
    }

    // Perform a level order traversal of the binary tree
    void levelOrderTraversal() {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            cout << current->data << " ";
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        cout << endl;
    }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(70);
    binaryTree.insert(60);
    binaryTree.insert(80);

    cout << "Inorder Traversal: ";
    binaryTree.inorderTraversal();

    cout << "Preorder Traversal: ";
    binaryTree.preorderTraversal();

    cout << "Postorder Traversal: ";
    binaryTree.postorderTraversal();

    cout << "Level Order Traversal: ";
    binaryTree.levelOrderTraversal();

    int value = 40;
    cout << "Search " << value << ": " << (binaryTree.search(value) ? "Found" : "Not Found") << endl;

    value = 90;
    cout << "Search " << value << ": " << (binaryTree.search(value) ? "Found" : "Not Found") << endl;

    return 0;
}
