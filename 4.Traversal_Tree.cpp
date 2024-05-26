#include <iostream>
using namespace std;

struct Node
{
    char data;
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
    Node *root = NULL;
    root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');

    root->left->left = new Node('D');
    root->left->left->left = new Node('G');
    root->left->left->left->left = new Node('K');
    root->left->left->right = new Node('H');
    root->left->left->right->left = new Node('L');
    root->left->left->right->right = new Node('M');
    root->right->left = new Node('E');
    
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
