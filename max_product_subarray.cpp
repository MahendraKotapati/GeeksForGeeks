/*  
    https://www.youtube.com/watch?v=vtJvbRlHqTA 
    https://www.quora.com/How-do-I-solve-maximum-product-subarray-problems
*/
#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;

ll dp[10004][2];  // 0 - max_till_i, 1 - min_till_i; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,i,n,a,b,pro;
    cin>>t;

    while(t--)
    {
        cin>>n;    
        vector <ll>arr(n);

        for(i=0;i<n;i++)
             cin>>arr[i];   
        
        dp[0][0] = dp[0][1] = arr[0];  // we can avoid using this dp array ,by maintaining two variables 

        for(i=1;i<n;i++)
        {   
            a = (dp[i-1][0]*arr[i])%mod;
            b = (dp[i-1][1]*arr[i])%mod;

            dp[i][0] = max(max(a,b),arr[i]);
            dp[i][1] = min(min(a,b),arr[i]);
        }

        ll ans=-INT_MAX;
        
        for(i=0;i<n;i++)
            ans = max(max(dp[i][1],dp[i][0]),ans);
        cout<<ans<<"\n";
    }
    
    return 0;
}


/*

1
10
0 3 -5 -2 8 -7 -6 -2 -3 -9

*/