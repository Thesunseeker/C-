#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Node
{
  int value;
  struct Node *next;
  struct Node *prev;
}Node;

void DListInit(Node **p)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node ->next = node;
  node->prev = node;
  *p = node;
}

void DListPushFront(Node *node ,Node *head )
{
  node ->next = head->next;
  node->prev = head;
  head->next->prev = node;
  head->next = node;
}

void DListPushBack(Node *node , Node *head)
{
  node ->next = head;
  node ->prev = head->prev;
  head->prev->next = node ;
  head->prev = node;
}

void DListInsertAfter(Node *pos , Node *node)
{
  node ->next = pos ->next;
  node->prev = pos;
  pos->next->prev = node;
  pos->next = node ;
}

void DListInsertBefor(Node *pos , Node *node)
{
  node->next = pos;
  node->prev = pos->prev;
  pos->prev->next = node;
  pos->prev = node;
}
