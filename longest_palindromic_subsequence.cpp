#include<bits/stdc++.h>
typedef long int li;
using namespace std;


string maximum(string s1,string s2)
{
    if(s1.length()>s2.length())  
        return s1;
    else 
        return s2;
}

string  longest_palindromic_subsequence(string str)
{

    li len=str.length(),i,j;  
    string dp[len+1][len+1];
    string rev=str;
    reverse(rev.begin(),rev.end());
    
    for(i=0;i<=len;i++)  dp[i][0]="";
    for(i=0;i<=len;i++)  dp[0][i]="";    

    for(i=1;i<=len;i++)
    {
        for(j=1;j<=len;j++)
        {
            if(str[i-1]==rev[j-1]) 
                dp[i][j]=dp[i-1][j-1]+str[i-1];
            else 
                dp[i][j]=maximum(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[len][len];

}

int main()
{

    li t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<longest_palindromic_subsequence(str)<<"\n";
    }


      return 0;
}
