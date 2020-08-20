#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll dp[55][55]; // dp[dices][sum];
ll m;

ll get_ways(ll n,ll x)
{
    if(n<0||x<0)  return 0;
    if(n==0 && x==0)   return 1;

    if(dp[n][x]!=-1)
        return dp[n][x];

    ll i,ans=0;
    for(i=1;i<=m;i++)
        ans+=get_ways(n-1,x-i);
    
    return dp[n][x] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,n,x,ans;
    cin>>t;
	
    while(t--)
    {
       cin>>m>>n>>x;

        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;  

        for(i=1;i<=n;i++)
        {
           for(j=1;j<=x;j++)
           {    
                for(k=1;k<=m;k++)
                    if(j-k>=0)
                        dp[i][j]+=dp[i-1][j-k];
           }
        }
      cout<<dp[n][x]<<"\n";
       
    }
    
    return 0;
}