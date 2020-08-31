// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class LRUCache
{
    private:
     unordered_map< int,pair<list<int>::iterator,int> >mp;
     list<int>dq;
     int n;
public:
    LRUCache(int cap)
    {   
        n = cap;
        //dq = list<int>();   // least recent used item in front
        //mp = unordered_map< int,pair<list<int>::iterator,int> >();
        mp.clear();
        dq.clear();
    }
    
    int get(int key)
    {
        if(mp.find(key)==mp.end())
            return -1;

        auto itr = mp[key];
        int value = itr.second;
        dq.erase(itr.first);
        mp.erase(key);
        dq.push_back(key);
        mp[key] = {--dq.end(),value};

        return value;
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if(mp.find(key)!=mp.end())
        {  
            mp[key].second = value; 
            get(key); 
            return ; 
            
        }
        
        if(dq.size()==n)
        {
            //delete lru item
            int lru_key = dq.front();
            dq.pop_front();
            mp.erase(lru_key);
        }
          
        dq.push_back(key);
        mp[key] = {--dq.end(),value};   
        
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
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends