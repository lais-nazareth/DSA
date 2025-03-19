#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dado;
    struct Node* left;
    struct Node* right;
} Node;

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
}

Node* DFS(Node* root, int x){
    if (root == NULL){
        return;
    }
    root->left = DFS(root->left, x);
    if (root->dado == x){
    }
    root->right = DFS(root->right, x);
}

Node* Min(Node* root){
    if (root == NULL){
        return;
    }
    else if (root->left == NULL){
            return root;
        }
    return Min(root->left);
}

Node* Delete(Node* root, int x){
    root = DFS(root, x);
    //case 1: no child
    if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    //case 2: one child
    else if (root->left = NULL){
        Node* elem = root;
        root = root->right;
        free(elem);
    }
    else if (root->right = NULL){
        Node* elem = root;
        root = root->left;
        free(elem);
    }
    //case 3:
    else{
        Node* temp = Min(root->right);
        root->dado = temp->dado;
        root->right = Delete(root->right, temp->dado);
    }

    return root;
}