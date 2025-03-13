#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int num){
    if (top == MAX_SIZE -1){
        printf("Error: Stack Overflow \n");
        return;
    }
    A[++top] = num;
}

void Pop(){
    if (top == -1){
        printf("No element to pop\n");
        return;
    }
    top--;
}

void Print(int A[]){
    int aux = 0;
    while (A[aux] != NULL){
        printf(" %d", A[aux]);
        aux++;
    }
    printf("\n");
}

int main(void){
    Push(10);
    Push(4);
    Push(8);
    Pop();
    Push(7);
    Print(A);
    return 0;
}