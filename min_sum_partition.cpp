#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[10005][10005];

int main()
{


    ll arr[100],i,j,n,t,sum,mini;
    cin>>t;

    while(t--)
    {   
        memset(dp,0,sizeof(dp));
        //for(i=0;i<=100;i++)  
        //    for(j=0;j<=100;j++)  cout<<dp[i][j]<<" ";  
        cin>>n;  sum=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        //cout<<sum;
        for(i=0;i<=n;i++)
            dp[i][0]=1;  
        
        for(i=0;i<=sum;i++)  
           dp[0][i]=0;
        
        dp[0][0]=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
                if(j-arr[i-1]>=0) 
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-arr[i-1]];
                else   
                    dp[i][j]=dp[i-1][j];
        }

        mini=sum;

        for(i=1;i<sum;i++)
          if(dp[n][i])
          {
            mini=min(mini,abs(sum-i-i));
            //cout<<i<<" ";
          } 
        cout<<mini<<"\n";
    
    }

    return 0;
}