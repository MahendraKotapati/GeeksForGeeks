#include<bits/stdc++.h>
typedef long int li;
using namespace std;


li minimum(li a,li b,li c)
{
    return min(min(a,b),c);
}

li minimum_edit_distance(string str1,string str2)
{    
    li i,j,p=str1.length(),q=str2.length();
    li dp[p+1][q+1];

    for(i=0;i<=p;i++)   dp[i][0]=i;   // base conditions 
    for(i=0;i<=q;i++)   dp[0][i]=i;
  
     for(i=1;i<=p;i++)
     {
         for(j=1;j<=q;j++) 
         {
             if(str1[i-1]==str2[j-1])  
                dp[i][j]=dp[i-1][j-1];
             else if(str1[i-1]!=str2[j-1])  
                dp[i][j]=minimum(dp[i][j-1],dp[i-1][j-1],dp[i-1][j])+1;
         }
     }

    return dp[p][q];
}

int main()
{

    ios_base::sync_with_stdio(false);
    
    li t,p,q;   string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>p>>q;
        cin>>str1>>str2;
      
        cout<<minimum_edit_distance(str1,str2)<<"\n";

    }
    return 0;
}