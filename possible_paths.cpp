#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,u,v,k,K;
    cin>>t;
	
    while(t--)
    {
        cin>>n;    
        int g[n][n];

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>g[i][j];
        
        cin>>u>>v>>K;
        int dp[n+1][K+1];

        memset(dp,0,sizeof(dp));

        for(i=0;i<n;i++)
            dp[i][0] = (i==v);
        

        for(k=1;k<=K;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    if(!g[i][j]) continue;
                    else  
                        dp[i][k] += dp[j][k-1];
            }
        } 
        cout<<dp[u][K]<<"\n";
    }
    
    return 0;
}