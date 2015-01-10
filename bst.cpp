#include <iostream>
#include <vector>

using namespace std;
typedef struct node {
    int value;
    node *left;
    node *right;
    public:
        node(int);
} node;

node::node(int v) {
    value = v;
    left = NULL;
    right = NULL;
}

void traverse(node *root) {
    if (root == NULL) return;
    traverse(root->left);
    cout << root->value << " ";
    traverse(root->right);
}

void inorderTraversalIntoVector(node *root, vector<int> *vec) {
    if (root == NULL) return;
    inorderTraversalIntoVector(root->left, vec);
    vec->push_back(root->value);
    inorderTraversalIntoVector(root->right, vec);
}

bool isBST(node *root) {
    vector<int> vec;
    inorderTraversalIntoVector(root, &vec);

    bool isSorted = true;
    for (int i = 1; i < vec.size(); i++)
        if (vec[i - 1] > vec[i])
            isSorted = false;
    return isSorted;
}

int main() {
    node *root = new node(8);
    
    node *l1 = new node(3);
    root->left = l1;
    
    node *l2 = new node(6)
    l1->right = l2;

    node *l3 = new node(1);
    l1->left = l3;

    node *l4 = new node(4);
    l2->left = l4;

    node *l5 = new node(7);
    l2->right = l5;

    node *r1 = new node(10);
    root->right = r1;

    node *r2 = new node(14);
    r1->right = r2;

    node *r3 = new node(13);
    r2->left = r3;

    cout << isBST(root) << endl;
}
