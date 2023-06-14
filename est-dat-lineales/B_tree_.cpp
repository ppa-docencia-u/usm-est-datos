#include <iostream>
using namespace std;

// B-tree node
class BTreeNode {
    int *keys;
    int t;  // Minimum degree (defines the range for number of keys)
    BTreeNode **childPointers;
    int numKeys;
    bool isLeaf;

public:
    BTreeNode(int t1, bool isLeaf1);

    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();

    friend class BTree;
};

// B-tree
class BTree {
    BTreeNode *root;
    int t;  // Minimum degree (defines the range for number of keys)

public:
    BTree(int t1) {
        root = nullptr;
        t = t1;
    }

    void insert(int k);
    void traverse();
};

// BTreeNode Constructor
BTreeNode::BTreeNode(int t1, bool isLeaf1) {
    t = t1;
    isLeaf = isLeaf1;
    keys = new int[2 * t - 1];
    childPointers = new BTreeNode *[2 * t];
    numKeys = 0;
}

// Insert a key into the B-tree
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->numKeys = 1;
    } else {
        if (root->numKeys == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->childPointers[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            s->childPointers[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

// Traverse the B-tree
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf)
            childPointers[i]->traverse();
        cout << " " << keys[i];
    }

    if (!isLeaf)
        childPointers[i]->traverse();
}

// Insert a key into a non-full B-tree node
void BTreeNode::insertNonFull(int k) {
    int i = numKeys - 1;

    if (isLeaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > k) {
            i--;
        }

        if (childPointers[i + 1]->numKeys == 2 * t - 1) {
            splitChild(i + 1, childPointers[i + 1]);

            if (keys[i + 1] < k) {
                i++;
            }
        }
        childPointers[i + 1]->insertNonFull(k);
    }
}

// Split the child of a B-tree node
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->isLeaf);
    z->numKeys = t - 1;

    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }

    if (!y->isLeaf) {
        for (int j = 0; j < t; j++) {
            z->childPointers[j] = y->childPointers[j + t];
        }
    }

    y->numKeys = t - 1;

    for (int j = numKeys; j > i + 1; j--) {
        childPointers[j + 1] = childPointers[j];
    }

    childPointers[i + 1] = z;

    for (int j = numKeys - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }

    keys[i] = y->keys[t - 1];
    numKeys++;
}
