#include <stdio.h>

//oid SListPushbackpractice(SList *slist , slistdatatype v){
//  Node *n = (node *)malloc(sizeof(Node));
// n->value = v;
// n -> next = null;
// if (slist -> first ==  null){
//
// }




//void SListopoBack(SList *s) {
// assert(s->first != NULL);//排除链表中一个节点都没有的情况
// Node *c;
// if (s->first = NULL){
//  return NULL;
// }
// for (c =  s ->first;  c->next->next != NULL;  c = c->next);
// free(c->next);
// c->next =NULL;
//}//链表代码的两个特点，往往需要找到这个节点上一个的节点（前驱节点）
//操作链表的第一个节点往往是特殊情况

//struct ListNode{
// int val;
// struct ListNode *next;
//} 

//binstruct  ListNode* reverseList(struct ListNode* head)  {
// struct ListNode *result = NULL;
// struct ListNode *c = head;
//    while(c != NULL){
//      struct ListNode *next = c->next;
//      c->next = result;
//      result = c;
//      c = next;
//}
//return result;
//}


//先确定第一个节点的值是不是V，如果是：头删
//如果不是继续往下走，拿一个指针遍历链表的节点，指针用来确认指针指向节点得下一个节点保存的值是不是V，     
//指针符号为C，【first ,倒数第二个】， 
//void SListRemove(SList *s,SListDataType v){
//  if(s ->first == v){
//    Node *second = s->first->next;
//    free (s->first);
//    s->first = second;
//  } else {
//    Noed *c = s->first;
//    while(c ->next != NULL){
//      if(c->next->value = v){
//        Node *next = c->next;
//        c->next = c->next->next;
//        free(next);
//        return;
//      }
//    c = c->next;
//    }
//  }

/*
struct ListNode *nergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
  struct ListNode *c1 = l1;
  struct ListNode *c2 
}
*/




