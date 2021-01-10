#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
    top down approach code: https://youtu.be/EzQ_YEmR598?t=1392
    string c should interleave string a and string b
    string c should only contain letters from a and b and their order in individual strings should be preserved  

    dp[i][j] represent a[0:i] and b[0:j] is interleave with c[0:i+j] or not

*/

bool Interleave(string a,string b,string c)
{
    ll i,j,len1,len2;
    len1=a.length();len2=b.length();
    ll dp[105][105]={0};

    if(len1+len2!=c.length())
        return false;

    dp[0][0] = true;

    for(i=1;i<=len2;i++)   // filling 0th row
        if(b[i-1]==c[i-1])
            dp[0][i] = dp[0][i-1]; 


    for(i=1;i<=len1;i++)  // filling 0th column
        if(a[i-1]==c[i-1])
            dp[i][0] = dp[i-1][0];
    
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {   
           if(a[i-1]==b[j-1] && a[i-1]==c[i+j-1])
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else if(a[i-1]==c[i+j-1])
                dp[i][j] = dp[i-1][j];
            else if(b[j-1]==c[i+j-1])
                dp[i][j] = dp[i][j-1];
             
        }
    }

    return dp[len1][len2];
    
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
        cout<<Interleave(a,b,c)<<"\n";
    }
    
    return 0;
}



/*

//C++ CODE
class Solution {

    unordered_map<string,bool> mem;
    bool check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3)
    {
        if(p3==len3)
            return (p1==len1 and p2==len2)?true:false;
        
        string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(mem.find(key)!=mem.end())
            return mem[key];
        
        if(p1==len1)
            return mem[key] = s2[p2]==s3[p3]? check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1):false;
        if(p2==len2)
            return mem[key] = s1[p1]==s3[p3]? check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1):false;
        
        bool one = false,two = false;
        if(s1[p1]==s3[p3])
            one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])
            two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        
        return mem[key] = one or two;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len3 != len1+len2)
            return false;
        
        return check(s1,s2,s3,len1,len2,len3,0,0,0);
    }
};


*/