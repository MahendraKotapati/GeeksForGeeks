/*  using min_heap of k elements   */
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,k,n,data;
    cin>>t;
	
    while(t--)
    {
        cin>>k>>n;   
        priority_queue<ll,vector<ll>,greater<ll>>pq;  // min_heap

        for(i=0;i<n;i++)
        {
            cin>>data;
            if(pq.size()<k)
                pq.push(data);
            else    
            {
                pq.push(data);  // if element is greater that previous top (which is kth largest) then we can delete top,bacause kth largest has changed now,
                                // if element is lessthan that previous top (which is kth largest) then we can delete top,bacause kth largest has not changed , 
                                // top contains lowest element (present data) , we delete that because we have already klargest elements in heap. 
                pq.pop();
                
            }
            
            if(pq.size()==k)
                cout<<pq.top()<<" ";
            else    
                cout<<"-1"<<" ";
        } 
        cout<<"\n";
    }
    
    return 0;
}