#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 100
typedef long long ll;
using namespace std;

ll n,m,grid[100][100],dp[maxn+1][maxn+1][maxn+1][maxn+1],ans;

bool is_valid(ll l1,ll r1,ll l2,ll r2)
{
    return l1<n && r1<m && l2>=0 && l2<n && r2>=0 && r2<m ;
}

ll max_square_grid(ll l1,ll r1,ll l2,ll r2)
{
    if(!is_valid(l1,r1,l2,r2))
        return 0;

    if(l1==l2 && r1==r2 && grid[l1][r1])  // if start and end point is same and it is 1 then return 1
        return 1;

    if(dp[l1][r1][l2][r2]!=-1)
        return  dp[l1][r1][l2][r2];

    ll a = max_square_grid(l1,r1+1,l2-1,r2);

    if(is_valid(l1,r1+1,l2,r2+1))  
    {
        dp[l1][r1+1][l2][r2+1] = max_square_grid(l1,r1+1,l2,r2+1);  
        ans = max(ans,dp[l1][r1+1][l2][r2+1]);
    }
    
    if(is_valid(l1+1,r1,l2+1,r2))
    {
        dp[l1+1][r1][l2+1][r2] = max_square_grid(l1+1,r1,l2+1,r2);  
        ans = max(ans,dp[l1+1][r1][l2+1][r2]);
    }
    ll b = max_square_grid(l1+1,r1,l2,r2-1);

    //ll d = max_square_grid(l1+1,r1,l2+1,r2);
 
    if(grid[l1][r1]&&grid[l2][r2])
    {
        dp[l1][r1][l2][r2] = 1+max(a,b);
        ans = max(ans,dp[l1][r1][l2][r2]);
    }
    else
    {
        dp[l1][r1][l2][r2] =0; //max(c,d);
    }   
        

    return dp[l1][r1][l2][r2];

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;

        for(i=0;i<n;i++) 
            for(j=0;j<m;j++)
                cin>>grid[i][j];

        memset(dp,-1,sizeof(dp)); ans = 0;
        //cout<<max_square_grid(0,0,n-1,m-1)<<"\n";
        max_square_grid(0,0,min(n-1,m-1),min(n-1,m-1));
        cout<<ans<<"\n";
    }
    
    return 0;
}

/*

5 6
0 1 0 1 0 1 
1 0 1 0 1 0 
0 1 1 1 1 0 
0 0 1 1 1 0 
1 1 1 1 1 1

*/