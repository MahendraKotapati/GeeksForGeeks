#include<bits/stdc++.h>
#define F first
#define S second
#define inf 1000000
typedef long long ll;
using namespace std;

unordered_map <string,ll>mp,dp;

bool is_prefix(string str)
{
    if(mp.find(str)!=mp.end())
        return true;
    return false;
}

ll min_moves(string curr,string str)
{
    if(curr==str)
        return 0;

    if(dp.find(curr)!=mp.end())
        return dp[curr];

    ll a=inf,b=inf;

    if(is_prefix(curr+curr))
       a=1+min_moves(curr+curr,str);

     b=1+min_moves(curr+str[curr.length()],str);

    return dp[curr]=min(a,b);
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,len;
    string str,pre,curr;
    cin>>t;
	
    while(t--)
    {
        cin>>str;pre="";
        curr=str[0];
        len=str.length();

        for(i=0;i<len;i++)
        {
            pre+=str[i];
            mp[pre]=1;
        }    
        cout<<min_moves(curr,str)+1<<"\n";
         
        mp.clear();
        dp.clear();
    }
    
    return 0;
}

/*

3
aaaaaaaa
aaaaaa
abcabca

*/