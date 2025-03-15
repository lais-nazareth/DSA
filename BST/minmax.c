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

int Max(Node* root){
    if (root == NULL){
        return -1;
    }
    else if (root->right == NULL){
            return root->dado;
        }
    return Max(root->right);
}

int Min(Node* root){
    if (root == NULL){
        return -1;
    }
    else if (root->left == NULL){
            return root->dado;
        }
    return Min(root->left);
}

int main(void){
    Node* root = NULL;
    int max, min;
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 7);
    max = Max(root);
    min = Min(root);
    printf("Max: %d\nMin: %d", max, min);
}