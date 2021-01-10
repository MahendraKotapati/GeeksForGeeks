// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x) {
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements

bool is_vowel(char ch)
{
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

struct Node* arrange(Node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
        
    Node *curr,*vowel_node,*new_head,*v_last;
   
    v_last = NULL; 
    new_head = curr = head;
    
    while(head!=NULL && is_vowel(head->data))
    { 
        v_last = head;
        head = head->next;
    }
    
    curr = head;
    
    if(curr==NULL)  // if all vowels in string 
        return new_head;
        
    while(curr->next!=NULL)
    {
        if(is_vowel(curr->next->data))
        {
            vowel_node = curr->next;
            curr->next = curr->next->next;
            
            if(v_last)
            {
                vowel_node->next = v_last->next;
                v_last->next = vowel_node;
                
                v_last = v_last->next; // updating latest vowel
            }
            else // if it is a first vowel
            {
                new_head = vowel_node;
                new_head->next = head;
                v_last = new_head;
            }
            
            // we don't need to make curr = curr->next;  since, we are updating the curr->next above, and we are also checking condition on curr->next
        }
        else   // important 
            curr = curr->next; 
        
    }
    
    return new_head;
    
}
