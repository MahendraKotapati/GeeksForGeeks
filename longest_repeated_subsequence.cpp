#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,len;
    string str;
    cin>>t;
	
    while(t--)
    {   
       cin>>len;
       cin>>str;
       vector <vector <ll>>dp(len+1,vector <ll>(len+1,0));

       for(i=1;i<=len;i++)
       {
           for(j=1;j<=len;j++)
            if(str[i-1]==str[j-1] && i!=j)
                dp[i][j]=dp[i-1][j-1]+1;
            else   
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

       }
       cout<<dp[len][len]<<"\n";

    }
    
    return 0;
}