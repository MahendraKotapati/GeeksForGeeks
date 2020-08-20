#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll m;

ll painters(vector <ll>&arr,ll mid,ll n)
{
    ll count=0,i,sum=0;

    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
            count++,sum=arr[i];
    }
    count++;

    if(count<=m)
        return true;
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,low,high,mid,ans;
    cin>>t;
	
    while(t--)
    {   
        cin>>n>>m;  ans = INT_MAX;
        vector <ll>arr(n);

        for(i=0;i<n;i++)
            cin>>arr[i];
        
        low = *max_element(arr.begin(),arr.end());
        high = accumulate(arr.begin(),arr.end(),0);

        while(low<=high)
        {
            mid = (low+high)/2;

            if(painters(arr,mid,n))
                ans = min(ans,mid),high = mid-1;
            else   
                low = mid+1;
        }
        cout<<ans<<"\n";
         
    }
    
    return 0;
}