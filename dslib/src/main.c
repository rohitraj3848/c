#include <graph.h>
#include <linkedlist.h>

int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);

   ListNode* head = NULL;
	insertFirst(10, head);
   insertFirst(20, head);
   insertFirst(30, head);
   insertFirst(1, head);
   insertFirst(540, head);
   insertFirst(56, head); 

   printf("Original List: "); 
	
   //print list
   printList(head);

   while(!isEmpty(head)) {            
      ListNode *temp = deleteFirst(head);
      printf("\nDeleted value:");
      printf("(%d) ",temp->data);
   }  
	
   printf("\nList after deleting all items: ");
   printList(head);
   insertFirst(10, head);
   insertFirst(20, head);
   insertFirst(30, head);
   insertFirst(1, head);
   insertFirst(540, head);
   insertFirst(56, head); 
   
   printf("\nRestored List: ");
   printList(head);
   printf("\n");  

   ListNode *foundLink = find(4, head);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d) ",foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4, head);
   printf("List after deleting an item: ");
   printList(head);
   printf("\n");
   foundLink = find(4, head);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d) ",foundLink->data);
      printf("\n");
   } else {
      printf("node Element not found.");
   }
	
   printf("\n");
   sort(head);
	
   printf("List after sorting the data: ");
   printList(head);
	
   reverse(&head);
   printf("\nList after reversing the data: ");
   printList(head);

	return 0;

}