#include<bits/stdc++.h>
#define F first
#define S second
#define maxn 10004
#define pb push_back
typedef long long ll;
using namespace std;

ll dp[maxn+1];

void ugly_numbers()
{
    ll i,j,p2,p3,p5;
    p2 = p3 = p5 = 0;
    dp[0] = 1;

    for(i=1;i<=maxn;i++)
    {   
        dp[i] = min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));

        if(dp[i]==2*dp[p2]) p2++;
        if(dp[i]==3*dp[p3]) p3++;
        if(dp[i]==5*dp[p5]) p5++;
    } 

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ugly_numbers();
    ll t,i,n;
    cin>>t;
	
    while(t--)
    {   
        cin>>n;
        cout<<dp[n-1]<<"\n";
    }
    
    return 0;
}