#include <iostream>
using namespace std;
struct Node
{
    int data;     
    Node *left;     
    Node *right;    

    Node(char value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void printtree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printtree(root->left);
    printtree(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void insert(Node *&root, char value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return;
    }
    if (value < root->data)
        insert(root->left, value);
    else
        insert(root->right, value);
}

int main()
{

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        insert(root,arr[i]);
    }
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    
    return 0;
}