#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,len1,len2,j,dp[105][105];
    string str1,str2;
    cin>>t;
	
    while(t--)
    {   
        cin>>str1>>str2;
        len1=str1.length();
        len2=str2.length();
        memset(dp,0,sizeof(dp));

        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {   
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else  
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<(len1+len2-dp[len1][len2])<<"\n";
    }
    
    return 0;
}