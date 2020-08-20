Node* copyList( Node *head)
{
     Node *dup_head=( Node*)malloc(sizeof( Node));
    dup_head=create_linkedlist(head);  
     Node *temp=( Node*)malloc(sizeof( Node));
     Node *itr=( Node*)malloc(sizeof( Node));
     itr=dup_head;
    while( itr!=NULL)
    {
        temp=head->next;  
        head=itr;
        itr= itr->next;
        head=temp;
    }
    return  dup_head;   

}


 Node * create_linkedlist( Node *head)
{

    if(head==NULL)   return NULL;
     Node *dup_head=( Node*)malloc(sizeof( Node));
     Node *temp=( Node*)malloc(sizeof( Node));
    temp=dup_head;
    while(head!=NULL)
    {
        temp->data=head->data;
        temp->random=head->random;
         Node *n=( Node*)malloc(sizeof( Node));
        temp->next=n;
        temp=n; 
        head=head->next;
    }
    return   dup_head;

}