#include<bits/stdc++.h>
#define maxn 10004
typedef long long ll;
using namespace std;
ll dp[10][10005];

ll solve(ll n,ll c)
{
    if(n<0) return 0;
    if(n==0) return 1;
    //if(dp[n][c]!=-1)
    //    return dp[n][c];

    if(n<=3)
        return dp[n][c] = solve(n-3,3)+solve(n-5,5)+solve(n-10,10);
    else if(n==5)
        return dp[n][c] =  solve(n-5,5)+solve(n-10,10);
    else  
        return dp[n][c] =  solve(n-10,10);
    return 0;
}


int main()
{
    ll t,n,i,j,arr[]={3,5,10};
    cin>>t;
        
    while(t--)
    {
        cin>>n;

        for(i=0;i<=3;i++)
            dp[i][0]=1;

        for(i=0;i<=n;i++)
            dp[0][i]=0;

        dp[0][0]=1;

        for(i=1;i<=3;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j<arr[i-1]) 
                    dp[i][j]=dp[i-1][j];
                else   
                    dp[i][j] = dp[i-1][j]+dp[i][j-arr[i-1]];
            }
        }
        cout<<dp[3][n]<<" ";
    }
}