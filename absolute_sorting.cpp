// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    Node* next;
    int data;
};
void sortList(Node** head);
// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout<<endl;
}


// Driver code
int main()
{

int t=0;
int n = 0;
cin>>t;
while(t--)
{
 Node* head = NULL;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
       // push(&head, a);
    }
    for(int i=n-1;i>=0;i--)
    {
        push(&head, arr[i]);
    }
   // printList(head);

    sortList(&head);

    printList(head);

}
    return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

 



void sortList(Node** head) 
{
    if(*head==NULL)
        return ;
        
    Node *temp,*neg_node;
    temp = *head;

    /*  traverse linked list from start , if next_node is -ve remove it (by breaking the link) and append in the start   */ 
    
    while(temp!=NULL)
    {
        if(temp->next!=NULL && temp->next->data<0)   
        {
            neg_node  = temp->next;
            temp->next = temp->next->next;  // imp we are changing the next node here , so we don't need   temp = temp->next below
            neg_node->next = *head;
            *head = neg_node;
        }
        else  // if next_node is +ve we don't need to break link for next node 
            temp  = temp->next;   
    }

}