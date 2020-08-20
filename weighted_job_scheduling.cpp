#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mod 1000000007
typedef long long ll;
using namespace std;

ll dp[100005];
struct Job
{
    ll start,end,profit;
};

ll cmp(Job j1,Job j2)
{
    return j1.end<j2.end;
}

ll binarySearch(Job arr[],ll n)
{
    ll low = 0,mid,high = n-1,ans=-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid].end<=arr[n].start)
            ans=mid,low=mid+1;
        else  
            high = mid-1;
    }
    return ans;
}

ll jobScheduling(vector<ll>& start, vector<ll>& end, vector<ll>& pro) 
{
    
    ll n = start.size(),i,max_profit,incl,excl,index;
    Job arr[n];

    for(i=0;i<n;i++)
        arr[i] = { start[i],end[i],pro[i] };
    
    sort(arr,arr+n,cmp);

    max_profit = dp[0] = arr[0].profit;

    for(i=1;i<n;i++)
    {   
        incl = arr[i].profit;
        index = binarySearch(arr,i);

        if(index!=-1)  
            incl+=dp[index] ; 
        dp[i] = max(incl,dp[i-1]);
    }

    return dp[n-1];

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n;
    
    cin>>n;
    vector <ll>start(n),end(n),pro(n);

    for(i=0;i<n;i++)
        cin>>start[i]>>end[i]>>pro[i];
    
    cout<<jobScheduling(start,end,pro)<<"\n";
    
    return 0;
}