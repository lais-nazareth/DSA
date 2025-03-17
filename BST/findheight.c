#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

struct Node{
    int dado;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

int FindHeight(Node* root){
    if (root == NULL){
        return -1;
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

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

int main(void){
    Node* root = NULL;
    int height;
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 5);
    root = Insert(root, 6);
    root = Insert(root, 25);
    height = FindHeight(root);
    printf("Height: %d\n", height);
    return 0;
}