#include <stdio.h>
#include <string.h>
char A[51];
int top = -1;

void Reverse(char A[], int l){
    char S[51];
    for (int i = 0; i < l; i++){
        S[++top] = A[i];
    }
    for (int i = 0; i < l; i++){
        A[i] = S[top];
        top--;
    }
}


int main(void){
    int l;
    printf("Digite a palavra: \n");
    scanf("%s", A);
    l = strlen(A);
    Reverse(A, l);
    printf("%s", A);
    return 0;
}