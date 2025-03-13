#include <stdio.h>

int A[10];
int N = 10;
int inicio = -1;
int final = -1;

int IsEmpty(){
    if (inicio == -1 && final == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(){
    if ((final+1)%N == inicio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(int x){
    if (IsEmpty())
    {
        inicio = 0;
        final = 0;
        A[0] = x;
    }
    else if (IsFull())
    {
        return;
    }
    else
    {
        final = ++final % N;
        A[final] = x;
    }
}

void Dequeue(){
    if (IsEmpty())
    {
        return;
    }
    else if (inicio == final)
    {
        inicio = -1;
        final = -1;
    }
    else
    {
        inicio++;
    }
}

void Peek(){
    printf("\n%d", A[inicio]);
}

void Print(){
    int i = inicio;

    if (IsEmpty())
    {
        printf("\nThis queue is empty\n");
    }
    else if (inicio == final)
    {
        printf("%d\n", A[inicio]);
    }
    else
    {
        while (i != (final+1))
        {
            printf("%d ", A[i]);
            i = (i+1) % N;
        }
        printf("\n");
    }
}

int main(void){
    Enqueue(2);
    Enqueue(5);
    Enqueue(7);
    Dequeue();
    Enqueue(4);
    Print();
}