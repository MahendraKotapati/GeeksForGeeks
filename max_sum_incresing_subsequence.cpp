#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector<ll>arr(n),dp(n);    
        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=0;i<n;i++)
        {   
            dp[i]=arr[i];
            for(j=0;j<i;j++)
                if(arr[i]>=arr[j] && dp[i]<dp[j]+arr[i])
                    dp[i] = dp[j]+arr[i];
        }
        cout<<*max_element(dp.begin(),dp.end())<<"\n";
    }
    
    return 0;
}