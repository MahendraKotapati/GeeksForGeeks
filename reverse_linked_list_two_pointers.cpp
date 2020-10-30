/*  https://stackoverflow.com/a/14474708 */

/*

a = a^b^c
b = a^b^c
c = a^b^c
a = a^b^c

solution in one line

c = a ^ b ^ c ^ (a=b) ^ (b=c)
b = a ^ b ^ c ^ (c=a) ^ (a=b)
a = a ^ b ^ c ^ (b=c) ^ (c=a)

*/
#include <bits/stdc++.h> 
using namespace std; 
//typedef uintptr_t ut; 
typedef uintptr_t ut; 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

 
void reverse(struct Node** head_ref) 
{ 
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 

	 
	while (current != NULL) {
		current = (struct Node*)((ut)prev ^ (ut)current ^ (ut)(current->next) ^ (ut)(current->next = prev) ^ (ut)(prev = current)); 
	} 

	*head_ref = prev; 
} 

/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(struct Node* head) 
{ 
	struct Node* temp = head; 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
}
 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 85); 

	printf("Given linked list\n"); 
	printList(head); 
	reverse(&head); 
	printf("\nReversed Linked list \n"); 
	printList(head); 
	return 0; 
} 
