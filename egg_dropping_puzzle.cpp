#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll dp[100][100];  // dp[eggs][floors];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,e,n,j,k;
    cin>>t;
	
    while(t--)
    {
        cin>>e>>n;

        for(i=1;i<=n;i++)  // if one egg there then we have start from bottom floor till it break so no.of trails = no.of floors
            dp[1][i] = i;
        
        for(i=1;i<=e;i++)  // if there is only one floor it takes only one trail
            dp[i][1] = 1,dp[i][0]=0;
        
        for(i=2;i<=e;i++)
        {
            for(j=2;j<=n;j++) 
            {   
                dp[i][j] = INT_MAX;
                for(k=1;k<=j;k++)
                    dp[i][j] = min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
            }
        }

        cout<<dp[e][n]<<"\n";
    }
    
    return 0;
}