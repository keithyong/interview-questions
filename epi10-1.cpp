#include <iostream>

using namespace std;

class Node {
    public:
        Node(int);
        Node *left;
        Node *right;
        int data;
};

Node::Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    } else {
        cout << " n ";
    }
}

int height(Node *root) {
    if (root == NULL) {
        return -1;
    } else {
        int h = 0;
        h = max(height(root->left), height(root->right)) + 1;
        return h;
    }
}

bool isBalanced(Node *root) {
    if (root == NULL) {
        return true;
    } else {
        int dif = height(root->left) - height(root->right);

        if (dif > 1) {
            return false;
        }

        isBalanced(root->left);
        isBalanced(root->right);

        return true;
    }
}

int main() {
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *six = new Node(6);
    Node *seven = new Node(7);

    one->left = two;
    one->right = three;
    two->left = four;
    two->right = five;
    four->left = six;
    four->right = seven;

    /* one->left = two; */
    /* two->left = three; */
    /* three->left = four; */
    /* four->left = five; */
    /* five->left = six; */
    /* six->left = seven; */

    /* one->left = two; */
    /* one->right = three; */
    /* two->left = four; */
    /* two->right = five; */
    /* three->left = six; */
    /* three->right = seven; */

    inorder(one);
    cout << endl;
    cout << height(one);
    cout << isBalanced(one);
}
