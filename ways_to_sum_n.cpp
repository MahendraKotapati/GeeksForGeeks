#include<iostream>
#include<vector>
typedef long int li;
#define mod 1000000009
using namespace std;



/*li rec(vector <li>&arr,li size1,li num,vector <li>&dp)
{   
    li i,sum=0;
    if(num<0)  return 0;
    if(num==0)  return 1;
    if(dp[num]!=-1)    return dp[num]; 

    for(i=0;i<size1;i++)
    {
        sum=(sum+(rec(arr,size1,num-arr[i],dp))%mod )%mod;
    }
    dp[num]=sum;
    return sum;
}
*/

int main()
{

    li t,num,size1,i,j;
    cin>>t;
    while(t--)
    {
        cin>>size1>>num;   vector <li>    arr(size1),dp(num+1,0);
        for(li &x:arr)  cin>>x;
        dp[0]=1;
        for(i=1;i<=num;i++)
        {
            for(j=0;j<size1;j++)
              if(i>=arr[j])  
                dp[i]+=dp[i-arr[j]];  
        }
        
        cout<<dp[num]<<"\n";   
    }
    


    return 0;
}
