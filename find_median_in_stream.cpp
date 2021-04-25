#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,min_heap_size,max_heap_size,data,min_top,max_top,count=0,ans;
	priority_queue <ll>max_heap; // for lower half
    priority_queue <ll,vector <ll>,greater<ll>>min_heap; // for upper half it stores extra element in case of odd 

    cin>>t;

    while(t--)
    {
        cin>>data;count++;

        if(min_heap.size()==0 || data>=min_heap.top())
            min_heap.push(data);
        else  
            max_heap.push(data);
        
        min_heap_size = min_heap.size(); max_heap_size = max_heap.size();

        if(min_heap_size>max_heap_size)
        {
            if(min_heap_size-max_heap_size>1)
            {
                min_top = min_heap.top();
                min_heap.pop();
                max_heap.push(min_top);    
            }   
        }
        else if(max_heap_size>min_heap_size)
        {
            max_top = max_heap.top();
            max_heap.pop();
            min_heap.push(max_top);
        }

        if(count&1)
            ans = min_heap.top();   
        else 
            ans = (min_heap.top()+max_heap.top())/2.0; 

        cout<<ans<<"\n";      
    }

    return 0;
}