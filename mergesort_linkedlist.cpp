// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
   
void partition(Node *head,Node **a,Node **b)
{   
    Node *slow,*fast;   
    slow = fast = head;

    while(slow!=NULL && fast!=NULL && fast->next)
    {
        if(fast->next->next==NULL)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
    
}


Node *merge(Node *a,Node *b)
{
    Node *ans=NULL;
    ans = (Node*)malloc(sizeof(Node));
    if(a==NULL) return b;
    if(b==NULL) return a;

    if(a->data<=b->data) {
        ans->data = a->data; ans->next = merge(a->next,b);
    }
    else {
        ans->data = b->data; ans->next = merge(a,b->next);
    }
    return ans;
}

void merge_sort(Node **head)
{
    if(*head==NULL|| (*head)->next==NULL)
        return ;
    
    Node *a,*b;
    partition(*head,&a,&b); // like finding mid 
   
    merge_sort(&a);
    merge_sort(&b);
    *head = merge(a,b);
}
   
Node* mergeSort(Node* head) {
    
    merge_sort(&head);
    return head;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}   