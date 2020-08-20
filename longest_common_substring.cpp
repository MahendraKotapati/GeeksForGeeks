#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,len1,len2,max_len;
    string s1,s2;
    cin>>t;
	
    while(t--)
    {   
        cin>>len1>>len2;
        cin>>s1>>s2;
        //len1=s1.length();  len2=s2.length();
        ll dp[105][105]={0};
        max_len=0;

        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    max_len=max(dp[i][j],max_len);
                }    
                    
        }
        cout<<max_len<<"\n";

    }
    
    return 0;
}

/*

2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC



*/