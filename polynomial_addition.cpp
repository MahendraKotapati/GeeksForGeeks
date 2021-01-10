// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        
        Node *sum = addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
// } Driver Code Ends


/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
Node* addPolynomial(Node *p1, Node *p2)
{
    Node *head=NULL,*node,*last;
    
    while(p1!=NULL || p2!=NULL)
    {
        if(p1 && p2 && p1->pow==p2->pow)
        {
            node = new Node(p1->coeff+p2->coeff,p1->pow);
            p1 = p1->next; p2 = p2->next;
        }
        else if( (p2==NULL)  || (p1->pow>p2->pow))
        {
            node = new Node(p1->coeff,p1->pow);
            p1 = p1->next;
        }
        else   // p2 has greater power or p1 is null
        {
            node = new Node(p2->coeff,p2->pow);
            p2 = p2->next;
        }
        
        if(head==NULL)
        {
            head = node; 
            last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
    }
    
    return head;
}


/*

O(1) space

Node* addPolynomial(Node *p1, Node *p2)
{
    if(p1==NULL) return p2;
    if(p2==NULL) return p1;
    
    Node *last=NULL,*head=NULL;
   
   
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->pow == p2->pow)
        {
            p1->coeff = p1->coeff+p2->coeff;
            
            if(last==NULL) {
                last = p1; head=p1;
            }
            else  {  
                last->next = p1;
                last = last->next;
            }
            p1 = p1->next; p2 = p2->next;
        }
        else if(p1->pow>p2->pow)
        {   
            if(last==NULL) {
                last = p1;head=p1;
            }
            else { 
                last->next = p1;
                last = last->next;
            }
            p1 = p1->next;
        }
        else if(p1->pow<p2->pow)
        {   
            if(last==NULL) {    
                last = p2,head=p2;  
            }
            else {
                last->next = p2;
                last = last->next;
            }
            p2 = p2->next;
        }
    }
    
    if(p1!=NULL) last->next = p1;
    if(p2!=NULL) last->next = p2; 

    return head;
}


*/