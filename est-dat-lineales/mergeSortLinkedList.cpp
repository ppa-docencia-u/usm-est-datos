#include <iostream>

using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr) {}

    /*
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    ~Node() {
        cout << "Deleting node with data: " << this->data << endl;
    }

    void print() {
        cout << this->data << " ";
    } 
    */

};

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right){
    // Base case
    if (left == nullptr) 
        return right;
    
    if (right == nullptr) 
        return left;

    // Pick either a or b, and recur
    Node* merged = nullptr;
    if (left->data <= right->data) {
        merged = left;
        merged->next = merge(left->next, right);
    } else {
        merged = right;
        merged->next = merge(left, right->next);
    }

    return merged;
}

// Function to split the linked list into two halves using the fast/slow pointer strategy
void split(Node* head, Node** left, Node** right) {
    if (head == nullptr || head->next == nullptr) {
        *left = head;
        *right = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = nullptr;
}

// Merge Sort function for linked list
void mergeSort(Node** headRef) {
    // Base case
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* left = nullptr;
    Node* right = nullptr;

    // Split the list into two halves
    split(head, &left, &right);

    // Recursively sort the two halves
    mergeSort(&left);
    mergeSort(&right);

    // Merge the two sorted halves
    *headRef = merge(left, right);
}

// Function to insert a node at the beginning of the singly linked list
void insert(Node** headRef, int data) {
    Node* newNode = new Node(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Funtion to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    Node* head = nullptr;

    // 85,24,63,45,31,96,50, 25,8,11,9,19,10,2
    insert(&head, 85);
    insert(&head, 24);
    insert(&head, 63);
    insert(&head, 45);
    insert(&head, 31);
    insert(&head, 96);
    insert(&head, 50);
    insert(&head, 25);
    insert(&head, 8);
    insert(&head, 11);
    insert(&head, 9);
    insert(&head, 19);
    insert(&head, 10);
    insert(&head, 2);

    cout << "List original: ";
    printList(head);

    mergeSort(&head);

    cout << "List ordenada: ";
    printList(head);

    return 0;
}