/* https://www.youtube.com/watch?v=WRXCwgdni90&feature=youtu.be  */
#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

ll dp[2][105][105];  // turn 1 means user(me)

ll optimal_strategy(ll l,ll r,ll turn,vector <ll>&arr)
{

    if(l==r)
    {   
        if(turn)
            return  dp[turn][l][r]= arr[l];
        else 
            dp[turn][l][r] = 0;
    }    

    if(dp[turn][l][r]!=-1)
        return dp[turn][l][r];
    
    
    ll a = arr[r]*turn+optimal_strategy(l,r-1,!turn,arr);
    ll b = arr[l]*turn+optimal_strategy(l+1,r,!turn,arr);

    if(turn)
        dp[turn][l][r] = max(a,b);
    else    // if turn is oppenent then he minimizes amount of money he give to user(me)
        dp[turn][l][r] = min(a,b);
   
    return dp[turn][l][r];

}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);

        for(i=0;i<n;i++)
            cin>>arr[i];

        memset(dp,-1,sizeof(dp));   // dp array stores max sum for user (me) 

        cout<<optimal_strategy(0,n-1,1,arr)<<"\n";
    }
    
    return 0;
}

/*

2
4
5 3 7 10
4
8 15 3 7


*/