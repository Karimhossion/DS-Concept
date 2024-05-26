#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void printtree(Node *root) {
    if (root == NULL)
        return; 
    cout << root->data << " ";
    printtree(root->left);
    printtree(root->right);
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void insert(Node* &root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }
    if (value < root->data)
        insert(root->left, value);
    else
        insert(root->right, value);
}

int sumNode(Node* root, int threshold) {
    if (root == NULL)
        return 0;
    int sum = 0;
    if (root->data > threshold)
        sum += root->data;
    sum += sumNode(root->left, threshold);
    sum += sumNode(root->right, threshold);
    return sum;
}

int main() {
    int n, threshold;

    cout << "Enter the number of nodes: ";
    cin >> n;

    int value[n];
    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter the threshold value: ";
    cin >> threshold;

    Node* root = NULL;

    for (int i = 0; i < n; ++i)
        insert(root, value[i]);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Threshold: " << threshold << endl;

    int sum = sumNode(root, threshold);
    cout << "Sum of nodes exceeding threshold " << threshold << ": " << sum << endl;

    return 0;
}
