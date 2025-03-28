#include <iostream>

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int root_val){
        val = root_val;
        left = nullptr;
        right = nullptr;
    }
};

void DeleteNodes(Node *node){
    if(node == nullptr){
        return;
    }
    DeleteNodes(node->left);
    DeleteNodes(node->right);
    delete node;
}

void PrintTree(Node *node){
    if(node == nullptr){
        return;
    }
    std::cout<<node->val<<'\n';
    PrintTree(node->left);
    PrintTree(node->right);
}

int main()
{
    Node *root = new Node(1);
    Node *originalRoot = root;

    root->left = new Node(2);
    root->left = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    PrintTree(root);

    DeleteNodes(originalRoot);
}