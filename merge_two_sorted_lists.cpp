class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        ListNode *head=NULL,*tail=NULL;
        
        if(l1->val<l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else  
        {
            head = l2;
            l2 = l2->next;   
        }
        
        tail = head;
        
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else  
            {
                tail->next = l2;
                l2 = l2->next;
            }
            
            tail = tail->next;
            tail->next = NULL;   
        }
        
        if(l1)
            tail->next = l1;
        
        if(l2)
            tail->next = l2;
        
        return head;   
    }
};