#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

unordered_map <string,ll>mp;
string word,sen; ll n;

ll word_break(string str,ll i,ll dp[])
{
    
    if(i==n)   
        return (str=="")?1:0;
        
    if(str=="" && dp[i]!=-1)
        return dp[i];

    if(mp.find(str+sen[i])==mp.end())
        return  dp[i] = word_break(str+sen[i],i+1,dp);
    else  
        return dp[i] = word_break("",i+1,dp); 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,dp[1005];
    cin>>t;
	
    while(t--)
    {
       cin>>n;  
       for(i=0;i<n;i++)
       {
           cin>>word;
           mp[word]=1;
       }
       cin>>sen;
       memset(dp,-1,sizeof(dp));
       n=sen.length();
       word_break("",0,dp);
       cout<<dp[n-1]<<"\n";
       mp.clear();
    }
    
    return 0;
}