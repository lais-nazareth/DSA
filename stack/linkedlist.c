#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dado;
    struct Node* prox;
};
typedef struct Node Node;

void Push(Node** L, int num){
    Node *elem;
    elem = (Node*)malloc(sizeof(Node));
    elem -> dado = num;
    elem -> prox = (*L);
    (*L) = elem;
}

void Pop(Node** L){
    if ((*L) == NULL){
        printf("No element to pop\n");
        return;
    }
    Node* temp = *L;
    *L = (*L) -> prox;
    free(temp);
}

void Print(Node* L){
    Node* aux;
    aux = L;
    while (aux != NULL){
        printf(" %d", aux->dado);
        aux = aux -> prox;
    }
    printf("\n");
}

int main(void){
    Node* L;
    L = NULL;

    Push(&L, 10);
    Push(&L, 4);
    Push(&L, 8);
    Pop(&L);
    Push(&L, 7);
    Print(L);
    return 0;
}