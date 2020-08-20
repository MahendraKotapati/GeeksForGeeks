#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define pll pair<ll,ll>
#define pp pair<ll,pll>
using namespace std;

ll n,m,mat[21][21],vis[21][21];
ll dx[]={-1,0,1,0},dy[]={0,1,0,-1};


bool is_valid(ll i,ll j)
{
    return (i>=0 && i<n) && (j>=0 && j<m) && (vis[i][j]==0) && (mat[i][j]==1) ;
}

ll ssdp(ll sx,ll sy,ll desx,ll desy)
{
    if(!mat[sx][sy]||!mat[desx][desy])
        return -1;
    
    ll i,j,k,dis;
    queue <pp>q; // queue<dis,<x,y>>q;
    q.push({0,{0,0}});

    while(!q.empty())
    {   
        auto curr = q.front(); q.pop();
        dis = curr.F; i=curr.S.F; j = curr.S.S;

        if(i==desx && j==desy)
            return dis;

        for(k=0;k<4;k++)   
        {
            if(is_valid(i+dx[k],j+dy[k]))
            {
                q.push({dis+1,{i+dx[k],j+dy[k]}});
                vis[i+dx[k]][j+dy[k]]=1;      
            }    
        } 
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,x,y;
    cin>>t;
	
    while(t--)
    {  
        cin>>n>>m; 
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>mat[i][j],vis[i][j]=0;
        
        cin>>x>>y;
        cout<<ssdp(0,0,x,y)<<"\n";  
    }
    
    return 0;
}