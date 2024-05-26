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
    cout << root->data << ' ';
    printtree(root->left);
    printtree(root->right);
}

void insert(Node *&root, int value)
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
    char ch;
    int x;
    while(1){
        cout << "Enter C and E : ";
        cin >> ch;
        if(ch=='C'||ch=='c')
        {
            cout << "Enter element : ";
            cin >> x;
            insert(root, x);
        }
        else{
            break;
        }
    }
    cout << "tree  : ";
    printtree(root);
    return 0;
}
