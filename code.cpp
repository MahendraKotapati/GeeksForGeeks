#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(string str,ll i,ll n)
{
    if(i==str.length())
        return (n==0);
    
    if(dp[i][n]!=-1)  // memoization
        return dp[i][n];

    ll j,ans=0;
    string curr_code = "";

    for(j=i;j<str.length();j++)
    {
        curr_code += str[j];
        if(mp[curr_code]!=mp.end())
            ans+=solve(str,j+1,n-1);
    }   
    return dp[i][n] = ans; 
}

int main()
{
    ll n,i;
    string str;
    cin>>str;

    cout<<solve(str,0,str.length());
    
}


/*   */