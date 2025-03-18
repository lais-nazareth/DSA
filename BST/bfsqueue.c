#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Node{
    int dado;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

struct Queue{
    Node *items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};
typedef struct Queue Queue;

void Enqueue(Queue *q, Node* item){
    q->rear++;
    q->items[q->rear] = item;
}

Node* Dequeue(Queue *q){
    q->front++;
    return q->items[q->front];
}

int is_empty(Queue *q){
    return q->front == q->rear;
}

void bfs(Node* root){
    Queue* q;
    q->front = -1;
    q->rear = -1;

    Enqueue(q, root);
    while (!is_empty(q)){
        Node* current = Dequeue(q);
        printf("%d ", current->dado);
        
        if (current->left != NULL){
            Enqueue(q, current->left);
        }
        if (current->right != NULL){
            Enqueue(q, current->right);
        }
    }
}

int main ()
{
  Node *root = (Node *) malloc (sizeof (Node));
  root->dado = 1;

  Node *node1 = (Node *) malloc (sizeof (Node));
  node1->dado = 2;

  Node *node2 = (Node *) malloc (sizeof (Node));
  node2->dado = 3;

  Node *node3 = (Node *) malloc (sizeof (Node));
  node3->dado = 4;

  Node *node4 = (Node *) malloc (sizeof (Node));
  node4->dado = 5;

  Node *node5 = (Node *) malloc (sizeof (Node));
  node5->dado = 6;

  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node1->right = node4;
  node2->left = node5;
  node2->right = NULL;
  node3->left = NULL;
  node3->right = NULL;
  node4->left = NULL;
  node4->right = NULL;
  node5->left = NULL;
  node5->right = NULL;

  bfs (root);

  return 0;
}