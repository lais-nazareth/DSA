#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dado;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

Node* Insert(Node* root, int x){
    if (root == NULL)
    {
        Node* elem = (Node*)malloc(sizeof(Node));
        elem->dado = x;
        elem->left = NULL;
        elem->right = NULL;
        root = elem;
    }
    else if (x <= root->dado){
        root->left = Insert(root->left, x);
    }
    else{
        root->right = Insert(root->right, x);
    }
    return root;
}

int Search(Node* root, int x){
    if (root == NULL){
        return 0;
    }
    else if (root->dado == x){
        return 1;
    }
    else if (x <= root->dado){
        return Search(root->left, x);
    }
    else{
        return Search(root->right, x);
    }
}

int main(void){
    Node* BstNode;
    BstNode = Insert(BstNode, 15);
    BstNode = Insert(BstNode, 10);
    BstNode = Insert(BstNode, 20);
    BstNode = Insert(BstNode, 25);
    Search(BstNode, 10);
    Search(BstNode, 22);
}   