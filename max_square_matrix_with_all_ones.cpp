#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 100
typedef long long ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,m,max_len;
    ll grid[50][50],dp[50][50];
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m; max_len=0;

        for(i=0;i<n;i++) 
            for(j=0;j<m;j++)
                cin>>grid[i][j];
        
        memset(dp,0,sizeof(dp));

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(grid[i-1][j-1]==1)
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    
                max_len = max(max_len,dp[i][j]);
            }
        }
        cout<<max_len<<"\n";

    }
    
    return 0;
}

/*

1
5 6
0 1 0 1 0 1 
1 0 1 0 1 0 
0 1 1 1 1 0 
0 0 1 1 1 0 
1 1 1 1 1 1

*/