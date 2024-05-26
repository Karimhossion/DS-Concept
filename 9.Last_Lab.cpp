#include <iostream>
using namespace std;
struct Node
{
    int data;     
    Node *left;     
    Node *right;    

    Node(int value)
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
    int value;
    char choice;
    do
    {
        cin >> value;
        insert(root, value);

        cout << " (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
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