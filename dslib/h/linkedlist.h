#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct ListNode{
   int data;
   struct ListNode *next;
}ListNode;


void printList(ListNode* head);
void insertFirst(int data, ListNode* head);
void insertlast(int data, ListNode* head);
ListNode* deleteFirst(ListNode* head);
ListNode* deletelast(ListNode* head);
bool isEmpty(ListNode* head);
ListNode* find(int data, ListNode* head);
ListNode* delete(int data, ListNode* head);
void sort(ListNode* head);
void reverse(ListNode** head_ref);

#endif