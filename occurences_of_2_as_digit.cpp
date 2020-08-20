#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

vector <ll>num;
ll len,dp[20][2][100005];

vector <ll> to_array(ll n)
{
    vector <ll>res;
    while(n>0)
    {
        res.pb(n%10);
        n/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

ll solve(ll idx,ll tight,ll cnt)
{
    if(idx==len)
        return cnt;
    
    if(dp[idx][tight][cnt]!=-1)
        return dp[idx][tight][cnt];

    ll limit,new_tight,ans=0,i;

    limit = (tight)? num[idx] : 9;

    for(i=0;i<=limit;i++)
    {   
        new_tight = (i==limit) ? tight : 0;
        if(i==2)
            ans+=solve(idx+1,new_tight,cnt+1);
        else   
            ans+=solve(idx+1,new_tight,cnt);
    }
    return dp[idx][tight][cnt]=ans;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n;
    cin>>t;
	
    while(t--)
    {
       cin>>n; 
       num = to_array(n); 
       len = num.size();

       memset(dp,-1,sizeof(dp)); 
       cout<<solve(0,1,0)<<"\n";
    }
    
    return 0;
}