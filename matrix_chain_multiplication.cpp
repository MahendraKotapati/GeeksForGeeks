#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define inf (ll)1e9
typedef long long ll;
using namespace std;

ll arr[105],dp[105][105];

ll rec(ll l,ll r)
{   
    if(l==r)  return 0;

    if(dp[l][r]!=-1)
        return dp[l][r];

    ll i,ans=INT_MAX,temp;

    for(i=l;i<r;i++)
    {
        temp = rec(l,i) + rec(i+1,r)+
                    arr[l-1]*arr[i]*arr[r];
        if(temp<ans)  ans = temp;
    }
    
    return dp[l][r] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll t,i,j,k,n,len;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));

        for(i=0;i<n;i++)
            cin>>arr[i];

        // n-1 matrices are there 

        for(len=2;len<n;len++)   // taking len length matrices 
        {
            for(i=1;i+len-1<n;i++)
            {   
                j = i+len-1;    
                dp[i][j] = INT_MAX;   //  calculating solution for   dp[i][j]  

                for(k=i;k<j;k++)        // inserting brackets in between i to j  and taking minimum      
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
        }

        cout<<dp[1][n-1]<<"\n";
    }
    
    return 0;
}


/*

1
5
40 20 30 10 30

*/