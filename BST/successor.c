#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* GetNewNode(int data){
    Node* elem = (Node*)malloc(sizeof(Node));
    elem->data = data;
    elem->left = NULL;
    elem->right = NULL;
    return elem;
}

Node* Insert(Node* root, int data){
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if (data <= root->left){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

Node* DFS(Node* root, int data){
    while (root->data != data){
        if (root == NULL){
            return;
        }
        else if (data < root->data){
            root->left = DFS(root->left, data);
        }
        else{
            root->right = DFS(root->right, data);
        }
        return root;
    }
    return root;
}

Node* Successor(Node* root, int data){
    //Search for current node
    Node* current = DFS(root, data);
    if (current == NULL){
        return NULL;
    }
    //Case 1: Has right subtree -> transverse to leftmost node on right subtree
    if (current->right != NULL){
        Node* temp = current->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    //Case 2: Has no right subtrees
    else{
        Node* successor = NULL;
        Node* ancestor = root;
        while (ancestor != current){
            if (current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}