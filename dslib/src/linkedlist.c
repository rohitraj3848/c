#include <linkedlist.h>



void printList(ListNode* head) {
   ListNode *ptr = head;
   printf("\n[ ");
	
   while(ptr != NULL) {
      printf("%d ->",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}


void insertFirst(int data, ListNode* head) {
   ListNode *link = (ListNode*) malloc(sizeof(ListNode));
	
   link->data = data;
   link->next = head;
   head = link;
}

void insertlast(int data, ListNode* head) {
   ListNode *link = (ListNode*) malloc(sizeof(ListNode));
   ListNode *current = head;
   if(current == NULL)
   {
      link->data = data;
      head = link;
   }
   else
   {
      while(current->next != NULL)
      {
         current = current->next;
      }
      current->next = link;
   }
}

ListNode* deleteFirst(ListNode* head) {

   ListNode *tempLink = head;
   head = head->next;
   return tempLink;
}

ListNode* deletelast(ListNode* head) {

   ListNode* current = head;
   ListNode* previous = NULL;
   
   if(head == NULL) {
      return NULL;
   }

   while(current->next !=NULL) {
      current = current->next;
      previous = current;
   }

   previous->next = NULL;
   return current;
}

bool isEmpty(ListNode* head) {
   return head == NULL;
}

int length(ListNode* head) {
   int length = 0;
   ListNode *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

ListNode* find(int data, ListNode* head) {

   ListNode* current = head;
   if(head == NULL) {
      return NULL;
   }
   while(current->data != data) {
	
      if(current->next == NULL) {
         return NULL;
      } else {
         current = current->next;
      }
   }      
   return current;
}

ListNode* delete(int data, ListNode* head) {

   ListNode* current = head;
   ListNode* previous = NULL;
	
   if(head == NULL) {
      return NULL;
   }

   while(current->data != data) {

      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }
   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }    
	
   return current;
}

void sort(ListNode* head) {

   int i, j, k, tempData;
   ListNode *current;
   ListNode *next;
	
   int size = length(head);
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(ListNode** head_ref) {
   ListNode* prev   = NULL;
   ListNode* current = *head_ref;
   ListNode* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}