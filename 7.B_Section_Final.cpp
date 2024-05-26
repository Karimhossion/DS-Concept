#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node* insert(int arr[], Node* root,int i, int n) {
    if ( i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;
        root->left = insert(arr, root->left, 2 * i + 1, n);
        root->right = insert(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int sumNode(Node* root, int threshold) {
    if (root == NULL) return 0;

    int sum = 0;
    if (root->data > threshold) {
        sum += root->data;
    }
    sum += sumNode(root->left, threshold);
    sum += sumNode(root->right, threshold);

    return sum;
}

int main() {
    int n, threshold;

    cout << "Enter the number of nodes: ";
    cin >> n;

    int value[n];
    cout << "Enter the node Value : ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter the threshold value: ";
    cin >> threshold;

    Node* root = insert(value, root, 0, n);

    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    int sum = sumNode(root, threshold);
    cout << "Sum of nodes threshold " << threshold << ": " << sum << endl;

    return 0;
}
