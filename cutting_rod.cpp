#include<bits/stdc++.h>
typedef long int li;
using namespace std;

li max_profit(vector <li>&prices,li n,vector <li>&dp)    // memoization  
{

    li maxi=0,i;
    if(n<=0)   return 0;
    if(dp[n]!=-1)  return dp[n];       

    for(i=1;i<=n;i++)           
      maxi=max(maxi,prices[i]+max_profit(prices,n-i,dp) );        
    dp[n]=maxi;    
    return maxi;                                                
       
}



int main()
{

    li t,n,i,k;

    cin>>t;
    while(t--)  
    {
        cin>>n;  vector <li>prices(n+1),dp(n+1,-1);
        for(i=1;i<=n;i++)  cin>>prices[i];
        for(i=1;i<=n;i++) dp[i]=prices[i];  // for tabulation only..  

        dp[0]=0;  dp[1]=prices[1];      
        for(k=2;k<=n;k++)   
        {
            for(i=1;i<=k;i++)                    
                 dp[k]=max(dp[k],dp[i]+dp[k-i]);  
        }
          cout<<dp[n]<<"\n";      
    
          
        // cout<<max_profit(prices,n,dp)<<"\n";                  
    }

    return 0;
}
