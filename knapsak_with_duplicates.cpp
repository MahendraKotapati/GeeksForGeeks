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
        
        for(i=0;i<=n;i++)
            dp[0][i]=0;
        
        for(i=0;i<=max_w;i++)
            dp[i][0]=0;
 
        for(i=1;i<=max_w;i++)
        {
            for(j=1;j<=n;j++)
                if(i>=w[j-1])
                    dp[i][j]=max(dp[i][j-1],dp[i-w[j-1]][j]+v[j-1]);
                else  
                    dp[i][j]=dp[i][j-1];
        }

        cout<<dp[max_w][n]<<"\n";
    }
    return 0;
}