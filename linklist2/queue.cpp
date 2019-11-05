#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
  int value ;
  struct Node *next;
}Node;

typedef struct Queue
{
  Node *head;
  Node *last;
}Queue;

void QInit(Queue *q)
{
  q->head = NULL;
  q->last = NULL;
}

void QPush(Queue *q , int v)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = v;
  node->next = NULL;
  if(q->head == NULL)
  {
    q->head = node;
    q->last = node;
  }
  q->last->next = node;
  q->last = node;
}

void QPop(Queue *q)
{
  assert(q != NULL);
  Node *head = q->head;
  q->head = q->head->next;
  free(head);
  if(q->head == NULL)
  {
    q->last = NULL;
  }
}

int QFront(Queue *q)
{
  return q->head->value;
}

int QSzie(Queue *q)
{
  int size = 0 ;
  for(Node *c = q->head ; c != NULL ; c = c->next)
  {
    size++;
  }
  return size;
}

bool QEmpty(Queue *q) {
    return q->head == NULL;
}
