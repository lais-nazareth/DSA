#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE -1;
#define MAX_VALUE 100;
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
    else if (x <= root->left){
        root->left = Insert(root->left, x);
    }
    else{
        root->right = Insert(root->right, x);
    }
    return root;
}

int valid(Node* root, int left, int right){
    if (root == NULL){
        return 1;
    }
    if (root->dado < right && root->dado > left){
        return 1;
    }
    else{
        return 0;
    }
    
}
int IsBinarySearchTree(Node* root){
    return (valid(root->left, 0, root->dado) && valid(root->right, root->dado, 100));
}

int main(void){
    Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 25);
    if (IsBinarySearchTree(root)){
        printf("Is BST");
    }
    return 0;
}