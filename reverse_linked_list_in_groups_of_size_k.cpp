// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;
     
     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;
         
         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }
        
        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);
    
     }
     
     return(0);

}

// } Driver Code Ends


/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node * _reverse(struct node *head,struct node *end)
{
    if(head==NULL)
        return head;
        
    struct node *forward,*pre=NULL,*curr=head;
    
    while(curr!=NULL && curr!=end)
    {
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
    }
    return pre;
}


struct node *reverse (struct node *head, int k)
{ 
    struct node *temp=head,*last_head=NULL,*end,*new_head,*start;
    int count = 0;
    
    
    while(temp!=NULL)
    {   
        count = 0; start = temp;
        while(count<k && (temp!=NULL))
        {
            temp = temp->next;
            end = temp;
            count++;
        }
        new_head = _reverse(start,end);
        
        if(last_head==NULL)
            head = new_head;
        else  
            last_head->next = new_head;
            
        last_head = start;
    }
    
    return head;
}
