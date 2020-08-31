#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    struct Node *prev;
    struct Node *next;
    Node(int k)
    {
        this->key = k;
        this->prev = this->next = NULL;
    }
}Node;

class LRUCache
{
    private:
        unordered_map< int,pair<Node*,int> >mp;
        Node *head,*tail;
        int n;

    public:
    LRUCache(int cap)
    {   
        n = cap;
        tail = head = NULL;
        mp.clear();
    }

    void delete_head()
    {   
        if(head==NULL)
            return ;
      
        head = head->next; 
        if(head!=NULL)
            head->prev = NULL;   
    }

    void insert_last(int key,int value)
    {   
        if(head==NULL)
        {
            head = new Node(key);
            tail = head;
            mp[key] = {head,value};
        }
        else  
        {
            Node *newNode = new Node(key);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; 
            mp[key] = {newNode,value};
        } 
    }
    
    int get(int key)
    {
        if(mp.find(key)==mp.end())
            return -1;

        auto itr = mp[key];
        int value = itr.second;

        Node *curr = itr.first;
        /* 
        if(curr==tail)  if node to be deleted is tail node we can simply ignore that 
            return value;
        */

        Node *prev =  curr->prev;

        if(prev==NULL)
            delete_head();
        else   
        {
            prev->next = prev->next->next;
            if(prev->next!=NULL)       
                prev->next->prev = prev;
            else    // we are deleting tail node so backward tail node  or inseted of this we simply ignore deletion when it already last element
                tail = tail->prev;   
        }

        mp.erase(key);
        insert_last(key,value);

        return value;
    }
    
    void set(int key, int value)
    {
        
        if(mp.find(key)!=mp.end())
        {  
            mp[key].second = value; 
            get(key); 
            return ;     
        }
        
        if(mp.size()==n)
        {
            //delete lru item
            int lru_key = head->key;
            mp.erase(lru_key);
            delete_head();    //dq.pop_front();
        }
        insert_last(key,value);

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << "\n";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends

/*  [ [2],
        [2],[2,6],[1],[1,5],[1,2],[1],[2]
    ] 

GET 2
SET 2 6
GET 1
SET 1 5
SET 1 2
GET 1
GET 2



[
    [2],[2,1],[3,2],[3],[2],[4,3],[2],[3],[4]
        [null,null,null,2,1,null,1,-1,3]
]


*/