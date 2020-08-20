#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll t,n,w,i,j,maxi,max_w;
    cin>>t;
    while(t--)
    {
        cin>>n>>max_w;
        vector <ll>v(n),w(n);
        memset(dp,0,sizeof(dp));

        for(i=0;i<n;i++)
            cin>>v[i];
        
        for(i=0;i<n;i++)
            cin>>w[i];
        
        for(i=0;i<=max_w;i++)
            dp[0][i]=0;
        
        for(i=0;i<=n;i++)
            dp[i][0]=0;

        //dp[0][0]=1;
        
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=max_w;j++)
                if(j>=w[i-1])
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
                else  
                    dp[i][j]=dp[i-1][j];
        }

        cout<<dp[n][max_w]<<"\n";
    }
    return 0;
}