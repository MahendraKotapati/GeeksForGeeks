#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll lcs(string a,string b)
{
    ll i,j,len1,len2;
    len1=a.length();len2=b.length();
    ll dp[105][105]={0};

    
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

        }
    }

    if(dp[len1][len2]==len1)
        return true;
    return false;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i;
    string a,b,c;
    cin>>t;
	
    while(t--)
    {
         cin>>a>>b>>c;
         cout<<(lcs(a,c)&&lcs(b,c))<<"\n";
    }
    
    return 0;
}