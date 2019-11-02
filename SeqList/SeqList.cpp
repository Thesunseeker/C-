#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

static void CheckCapacity(SeqList *ps)
{
  if(ps->_size < ps->_capacity)
  {
    return;
  }
  //空间不足需扩容
  int newCpacity = ps->_capacity * 2;
  int *newArray = (int *)malloc(sizeof(int)* newCpacity);
  assert(newArray != NULL);

  //搬数据
  for(int i = 0 ; i < ps->_size ; i++)
  {
    newArray[i] = ps->array[i];
  }
  //释放老空间
  free(ps->array);
  ps->array = newArray;
  ps->_capacity = newCpacity;
}

void SeqListInit(SeqList *ps , int capacity)
{
  assert(ps != NULL); 
  ps->array = (int *)malloc(sizeof(int) * capacity);
  assert(ps->array != NULL);
  ps->_size = 0;
  ps->_capacity = capacity;
}

void SeqListDestory(SeqList *ps)
{
  assert(ps != NULL);
  assert(ps->array != NULL);

  //释放array的空间
  free(ps->array);

  ps->array = NULL;
  ps->_size = 0;
  ps->_capacity = 0;
}

void SeqListPushBack(SeqList *ps , int v)
{
  CheckCapacity(ps);
  ps->array[ps->_size] = v;
  ps->_size++;
}

void SeqListPushFront(SeqList *ps , int v)
{
  CheckCapacity(ps);
  for(int i = ps->_size; i>= 1 ; i--)
  {
    ps->array[i] = ps->array[i - 1];
  }

  ps->array[0] = v;
  ps->_size++;
}

void SeqListInsert(SeqList *ps , int pos , int v)
{
  CheckCapacity(ps);
  assert(pos >= 0 && pos <= ps->_size);
  
  for(int i = ps->_size-1 ; i >= pos ; i--)
  {
    ps->array[i+1] = ps->array[i];
  }
  ps->array[pos] = v;
  ps->_size++;
}

void SeqListPopBack(SeqList *ps)
{
  assert(ps->_size > 0);
  ps->_size--;
}

void SeqListPopFront(SeqList *ps)
{
  assert(ps->_size > 0);
  for(int i = 0 ; i <= ps->_size - 2 ;i++)
  {
    ps->array[i] = ps->array[i + 1];
  }
  ps->_size--;
}

void SeqListErase(SeqList *ps ,int pos )
{
  assert(ps !=NULL);
  assert(pos >= 0 && pos < ps->_size);
  for(int i = pos + 1; i < ps->_size ; i++)
  {
    ps->array[i - 1] = ps->array[i];
  }
  ps->_size--;
}

int SeqListFind(SeqList *ps , int v)
{
  for(int i = 0 ; i< ps->_size ; i++)
  {
    if (ps->array[i] == v)
      return i;
  }
  return -1;
}

int SeqListModify(SeqList *ps , int pos , int v)
{
  assert(pos >= 0 && pos <ps->_size);
  ps->array[pos] = v;
  return ps->array[pos];
}

void SeqListRemove(SeqList *ps ,int v)
{
  int pos = SeqListFind(ps ,v);
  if(pos == -1)
  {
    return;
  }
  SeqListErase(ps , v);
}

