#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// New node creation
struct Node* newNode(int data) {
    struct Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Traverse Preorder
void preorder(struct Node* temp) {
    if (temp != nullptr) {
        cout << " " << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}

// Traverse Inorder
void inorder(struct Node* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}

// Traverse Postorder
void postorder(struct Node* temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        cout << " " << temp->data;
    }
}
Node* insert(int arr[], Node* root, int i, int n) 
{
    if (i < n) {
        Node* temp = newNode(arr[i]);
        root = temp;
        root->left = insert(arr, root->left, 2 * i + 1, n);
        root->right = insert(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Node* root = insert(arr, root, 0, n);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << "\nInorder traversal: ";
    inorder(root);
    cout << "\nPostorder traversal: ";
    postorder(root);

    return 0;
}
