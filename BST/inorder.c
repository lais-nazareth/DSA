#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dado;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

Node* GetNewNode(int x){
    Node* elem = (Node*)malloc(sizeof(Node));
    elem->dado = x;
    elem->left = NULL;
    elem->right = NULL;
    return elem;
}

Node* Insert(Node* root, int x){
    if (root == NULL){
        root = GetNewNode(x);
    }
    else if (x <= root->dado){
        root->left = Insert(root->left, x);
    }
    else{
        root->right = Insert(root->right, x);
    }
    return root;
}

Node* DepthFirst(Node* root){
    if (root == NULL){
        return;
    }
    
    root->left = DepthFirst(root->left);
    printf("%d ", root->dado);
    root->right = DepthFirst(root->right);
    return root;
}

int main(void){
    Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 25);
    DepthFirst(root);
}