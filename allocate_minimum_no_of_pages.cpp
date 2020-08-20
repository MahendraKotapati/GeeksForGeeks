#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 1000006
#define inf 1000000009
typedef long long ll;
using namespace std;

ll arr[maxn+1],n,mini,dp[10004][10004];

ll rec(ll m,ll i)
{   

    if(m==0 && i==n) return 0;
    if(m<0||i>=n || (m==0 && i<n) ) return inf;
 
    if(dp[m][i]!=-1)
        return dp[m][i];
    
    ll k,sum=0,p,maxi=-1;
    for(k=i;k<n;k++)
    {
        sum+=arr[k];
        p = rec(m-1,k+1);

        if(p!=inf)
        {
            maxi =max(sum,p);
            if(i==0)
                mini =min(mini,maxi);
        }

    }
    
    return dp[m][i] = maxi;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,m;
    cin>>t;
	
    while(t--)
    {   
        cin>>n>>m;
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        //cin>>m;

        memset(dp,-1,sizeof(dp));
        mini = INT_MAX;
        if(m>n)
            cout<<"-1"<<"\n";
        else{
            rec(m,0);
            cout<<mini<<"\n";   
        }

        /*for(i=1;i<=m;i++)             
        {
            for(j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        */
            
    }
    
    return 0;
}