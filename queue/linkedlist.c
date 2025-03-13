#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dado;
    struct Node* prox;
};
typedef struct Node Node;

Node* inicio = NULL;
Node* final = NULL;

void Enqueue(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> dado = x;
    temp -> prox = NULL;
    if (inicio = NULL && final == NULL)
    {
        final = temp;
        inicio = temp;
        return;
    }
    final -> prox = temp;
    final = temp;
}

void Dequeue(){
    Node* temp;
    if (inicio == NULL)
    {
        return;
    }
    if (inicio == final)
    {
        inicio = NULL;
        final = NULL;
    }
    else
    {
        temp = inicio;
        inicio = inicio -> prox;
    }
    free(temp);
}

void Peek(){
    printf("\n%d\n", inicio->dado);
}