#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,num,min1,min2,ans;
    cin>>t;
	
    while(t--)
    {
        cin>>n;  ans = 0;
        priority_queue<ll,vector<ll>,greater<ll>>min_heap;

        for(i=0;i<n;i++)
            cin>>num,min_heap.push(num);
        
        while(min_heap.size()>1)
        {
            min1 = min_heap.top(); min_heap.pop();
            min2 = min_heap.top(); min_heap.pop();
            min_heap.push(min1+min2);
            ans += min1+min2;
        }

        cout<<ans<<"\n";
    }
    
    return 0;
}