#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

typedef struct Llist 
{
  Node *first;
} Llist;

void LinklistInit(Llist *llist)
{
  llist->first = NULL;
}

void Linklistdestory(Llist *llist )
{
 assert(llist);
 Node *cur = llist->first;
 while  (cur != NULL)
 {
   Node *next = cur->next;
   free(cur);
   cur = next;
 }
}

void LinklistPushFront(Llist *llist , int v)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = v;

  node->next = llist->first;
  llist->first = node;
}

void LinklistPushBack(Llist *llist ,int v)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = v;
  node->next = NULL;
  if(llist->first == NULL)
  {
    llist->first = node;
  }
  else{
    Node *cur = llist->first;
    while(cur->next !=NULL)
    {
      cur = cur->next;
    }
    cur->next = node;
  }
}

void LinklistPopBack(Llist *s)
{
  assert(s->first != NULL);
  if(s->first->next == NULL)
  {
    free(s->first);
    s->first = NULL;
    return;
  }
  Node *c;
  for(c = s->first; c->next->next != NULL ; c = c->next );
  free(c->next);
  c->next = NULL;
}

void LinklistPopFront(Llist *s)
{
  assert(s);
  Node *c = s->first->next;
  free(s->first);
  s->first = c;
}

Node *LinklistFind(Llist *s , int v)
{
  for(Node *c = s->first ; c != NULL ; c = c->next)
  {
    if(c->value == v)
    {
      return c;
    }
  }
}

void LinklistInset(Node *pos , int v)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = v;
  node->next = pos->next;
  pos->next = node;
}

void LinklistErase(Node *pos)
{
  Node *next = pos->next->next;
  free(pos->next);
  pos->next = next;
}

void LinklistRemoveAll(Llist *s, int v)
{
  if(s->first == NULL)
  {
    return;
  }
  if(s->first->value == v)
  {  
    Node *c = s->first->next;
    s->first = c;
    free(s->first);
  }
  Node *c = s->first;
  while(c->next != NULL)
  {
    if(c->next->value == v)
    {
      Node *next = c->next;
      c->next = c->next->next;
      free(next);
    }
    else{
      c = c->next;
    }
  }
}
