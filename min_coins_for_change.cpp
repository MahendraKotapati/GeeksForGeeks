#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 1000000
#define inf 1000000000
typedef long long ll;
using namespace std;

ll dp[100][maxn+1];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,amount;
    cin>>t;
	
    while(t--)
    {   
        cin>>amount>>n;
        vector<ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=0;i<=n;i++)
            dp[i][0]=0;        
        
        for(i=0;i<=amount;i++)
            dp[0][i]=inf;

        dp[0][0]=0;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=amount;j++)
                if(j<arr[i-1])  
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-arr[i-1]]);
        }


        if(dp[n][amount]>=inf)
            cout<<"-1"<<"\n";
        else  
            cout<<dp[n][amount]<<"\n";
    
    }
    
    return 0;
}