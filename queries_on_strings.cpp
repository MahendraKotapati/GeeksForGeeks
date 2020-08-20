#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,q,len,l,r,distinct;
    string str;
    cin>>t;
	
    while(t--)
    {
        cin>>str;   
        len = str.length();
        ll dp[10004][26];
        memset(dp,0,sizeof(dp));

        dp[0][str[0]-'a']++;

        for(i=1;i<len;i++)
        {
            for(j=0;j<26;j++)
                dp[i][j]=dp[i-1][j];
            dp[i][str[i]-'a']++;

            
        }

        cin>>q;
        while(q--)
        {
            cin>>l>>r;  distinct = 0;
            r--;l--;
            for(j=0;j<26;j++)
            {   
                
                if(l-1>=0)
                    if(dp[r][j]-dp[l-1][j]>0)
                        distinct++;

                else  
                    if(dp[r][j]>0)
                        distinct++;
                
            }
            cout<<distinct<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}


/*

1
abcbaed
3
1 4 2 4 1 7


*/