#include<bits/stdc++.h>
typedef long int li;
#define inf 1000000007
using namespace std;

li minimum_distance(string str1,string str2,li cost_x,li cost_y)
{

    li i,j,len1=str1.length(),len2=str2.length(),cost=min(cost_x,cost_y);    
    li dp[len1+1][len2+1];  

    for(i=0;i<=len1;i++)   dp[i][0]=i*cost_x;        
    for(i=0;i<=len2;i++)   dp[0][i]=inf;            

    for(i=1;i<=len1;i++) 
    {
        for(j=1;j<=len2;j++)  
        {
             if(str1[i-1]==str2[j-1])  dp[i][j]=dp[i-1][j-1];  
             else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost; 
        }
    }
    return dp[len1][len2];
}

int main()
{

    li t,cost_x,cost_y,cost;
    string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>cost_x>>cost_y;
        cin>>str1>>str2;
        cout<<minimum_distance(str1,str2,cost_x,cost_y)<<"\n";
    }

    return 0;
}