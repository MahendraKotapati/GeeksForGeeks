// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}
// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

Node* reverseLL(Node *head)
{
    Node *prev,*curr,*next;
    prev = NULL;
    curr = head;
    
    while(curr)
    {   
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


Node *merge(Node *a,Node *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
        
    Node *ans;
    
    if(a->data<=b->data){ 
        ans = a; a->next = merge(a->next,b);
    }
    else{  
        ans = b; b->next = merge(a,b->next);
    }
    return ans;
}

void sort(Node **head)
{   
    /*
        Input : 1->7->2->6->3->5
        Output: 1->2->3->5->6->7

        separate incresing order list(L1) ,and decresing order list(L2) , reverse L2 ,
        now merge two sorted lists

        we can extract lists by pointing,
        temp->next = tem->next->next;
    */
    if(*head==NULL)
        return ;
        
    Node *temp = *head;
    Node *head2 = (*head)->next;  // L2 list
    
    Node *next;
    
    while(temp && temp->next)  // extracting lists
    {   
        next = temp->next;
        temp->next = temp->next->next;
        
        if(next && next->next)
            next->next = next->next->next;
            
        temp = temp->next;
    }
    
    head2 = reverseLL(head2);
    *head = merge(*head,head2);
    
}

