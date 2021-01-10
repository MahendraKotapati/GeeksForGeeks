#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

bool match(int i,int j,string s,string p) 
{
        
    int plen = p.length(),slen = s.length();

    if(dp[i][j]!=-1)
        return dp[i][j];
     
    bool ans = false;
        
    if(i==slen && j==plen)  // if both string and pattern is ended.
        ans =  true;
    
    else if(j==plen)  // if pattern is ended ,string not ended 
         ans = false;
    
    else if(i==slen)  // if string ended but pattern is there , this answer is true only if remaining pattern contains all *
        ans = (p[j]=='*') && match(i,j+1,s,p);
    
    else if( (s[i]==p[j]) || (p[j]=='?') )
        ans = match(i+1,j+1,s,p);
        
    else if(p[j]=='*')
        ans = match(i,j+1,s,p) || match(i+1,j,s,p);
    else 
        ans =  false;
         
    return dp[i][j] = ans;
        
}
    


int isMatch(string p,string s)
{
    memset(dp,-1,sizeof(dp));
    return match(0,0,s,p);
}


int main()
{
    int t,i,j,n,m;
    string p,s;
    cin>>t;
    
    while(t--)
    {
        cin>>p>>s;   
        memset(dp,-1,sizeof(dp));

        n = s.length(); m = p.length();

        for(i=0;i<=n;i++)
            dp[i][0] = false;  // empty pattern not match any string (length>0)

        dp[0][0] = true;  // empty string and empty pattern always match, this line should be placed before below loop (because it uses this)

        for(i=1;i<=m;i++)   // this for empty string and pattern has *
            dp[0][i] = (p[i-1]=='*') && dp[0][i-1];

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')  // s[i-1] && p[j-1] is  match
                    dp[i][j] = dp[i-1][j-1];

                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j]||dp[i][j-1]; // one character (s[i-1]) is matched for * || zero characters matched for *

                else   // s[i-1] && p[j-1] is not match
                    dp[i][j] = false;
            }   
        }

        cout<<dp[n][m]<<"\n";
        
    }
	return 0;
}