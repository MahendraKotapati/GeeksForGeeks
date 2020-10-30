#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[101];

int solve(string str,ll i)
{
    if(i==str.length())
        return 1;
    
    if(dp[i]!=-1)  // memoization
        return dp[i];

    ll j,ans=0,num;
    string curr_code = "";
    
    if(str[i]=='0')
        return 0;
        
    int len;
    
    for(j=i,len=0;j<str.length() && len<2;j++,len++)   // only consider next two chars because 1-26 is only are possible values 
    {
        curr_code += str[j];
        num = stol(curr_code);

        if(num>0 && num<=26)
            ans+=solve(str,j+1);
    }   
    return dp[i] = ans; 
}

int main()
{
    ll t,n,i;

    cin>>t;
    while(t--)
    {   
        memset(dp,-1,sizeof(dp));
        cin>>n;
        string str;
        cin>>str;
        cout<<solve(str,0)<<"\n";
    }
}


/*   */