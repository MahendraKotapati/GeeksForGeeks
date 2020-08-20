#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(string str,string sub)
{
    
    ll dp[105][105],i,j,k,len_str=str.length(),len_sub=sub.length(),temp,c=0;

    memset(dp,0,sizeof(dp));
    
    for(i=0;i<=len_sub;i++)
        dp[i][0] = 0;
    
    for(i=0;i<=len_str;i++)
        dp[0][i] = 1;

    for(i=1;i<=len_sub;i++)
    {
        for(j=1;j<=len_str;j++)
        {
             if(str[j-1]==sub[i-1])
                 dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
             else  
                dp[i][j] =dp[i][j-1]; 
        } 
    }

    return dp[len_sub][len_str];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);


    ll t,i,len;
    string str,sub;
    cin>>t;

    while(t--)
    {
         cin>>str>>sub;
         cout<<solve(str,sub)<<"\n";
    }
    
    return 0;
}