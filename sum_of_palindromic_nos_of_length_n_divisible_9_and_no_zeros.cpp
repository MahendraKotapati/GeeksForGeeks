/* https://www.hackerrank.com/contests/pir3/challenges/so-many-palindromes/problem */

#include<bits/stdc++.h>
#define F first
#define S second
#define mod 1000000007
#define pb push_back
typedef long long ll;
using namespace std;

ll len,dp[100005][9][100]; // dp[idx][rem][sum]
ll arr[100005];

/* 
ll solve(ll idx,ll tight,ll sum,ll rem)
{
    if(idx>len/2)
        return (rem)? 0: sum;
    
    if(dp[idx][tight][sum]!=-1)
        return dp[idx][tight][sum];

    ll limit,i,curr_ans,new_tight,new_sum,ans=0;
    limit = (tight)? str[idx]-'0': 9;

    for(i=1;i<=limit;i++)
    {
        new_tight =  (i==limit)? tight : 0 ;

        if(idx==len/2 && (len&1))
            new_sum = sum + (str[idx]-'0')*pow(10,len/2);
        else   
            new_sum = sum+ (str[idx]-'0')*pow(10,len-1);

        ans += solve(idx+1,new_tight, new_sum);  
    }

    return dp[idx][tight][sum] = ans;
}

*/


ll power(ll base,ll exp)
{
    ll res = 1;

    while(exp>0)
    {
        if(exp&1) res = (res*base)%mod;
        base = (base*base)%mod;
        exp /=2;
    }

    return res;
}

ll solve(ll idx,ll rem,ll sum)
{
    if(idx>=len)
        return (rem)? 0: sum;
    
    if(dp[idx][rem][sum]!=-1)
        return dp[idx][rem][sum];

    ll limit,i,new_sum,ans=0;
    limit = 9;

    if(idx>=(len+1)/2)
    {
        arr[idx] = arr[len-1-idx];
        new_sum = (sum + arr[idx]*power(10,len-1-idx)) % mod;
        ans =  (ans + solve(idx+1, (rem+arr[idx])%9, new_sum)) % mod;  
    }
    else   
    {
        for(i=1;i<=limit;i++)
        {
            arr[idx] = i;
            new_sum = (sum + arr[idx]*power(10,len-1-idx)) % mod;
            ans =  (ans + solve(idx+1, (rem+arr[idx])%9, new_sum)) % mod;  
        }
    }

    return dp[idx][rem]= ans;
}


// 8 7 6 6 7 8
// 10^6

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll i;
    cin>>len;

    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0);

    return 0;
}