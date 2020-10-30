// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node *reverseLL(Node *head)
{
    Node *curr,*prev=NULL,*next;
    curr = head;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


void reorderList(Node* head1) {

    /*  
        split LL into two equal linked list (left more is length is odd) , then reverse second LL , now start from both linked list and arrange.
    */
    Node *temp,*slow,*fast,*head2,*next1,*next2,*temp1,*temp2;
    slow = fast  = head1;

    while(slow && fast && fast->next)  // finding middle of LL using two pointer approach
    {   
        if(fast->next->next==NULL)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    head2 = slow->next;
    slow->next = NULL;   // splitting LL into two linked list

    head2 = reverseLL(head2);  // reversing the second LL

    //temp2 = head2;
    //while(temp2!=NULL) { cout<<temp2->data<<" end"; temp2 = temp2->next; }

    temp1 = head1; temp2 = head2;

    while(temp1 && temp2)
    {
        next1 = temp1->next;
        temp1->next = temp2;  

        next2 = temp2->next;
        temp2->next = next1;  // important , this for after 1->6 it,should link to 2, like 1->6->2
        temp1 = next1; temp2 = next2;
    }

}