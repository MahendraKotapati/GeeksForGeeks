#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define pll pair<ll,ll>
using namespace std;

ll n,m,mat[21][21],vis[21][21];
ll dx[]={-1,0,1,0},dy[]={0,1,0,-1};


bool is_valid(ll i,ll j)
{
    return (i>=0 && i<n) && (j>=0 && j<m) && (vis[i][j]==0) && (mat[i][j]!=0) ;
}

ll ssdp(ll sx,ll sy,ll desx,ll desy)
{

    if(mat[sx][sy]==0||mat[desx][desy]==0) // if can't step in source or destination
        return 0;
    
    ll i,j,k,dis;
    queue <pll>q; // queue<dis,<x,y>>q;
    q.push({sx,sy});
    vis[sx][sy]=1;

    while(!q.empty())  // BFS 
    {   
        auto curr = q.front(); q.pop();
        i=curr.F; j = curr.S;

        if(i==desx && j==desy)
            return 1;

        for(k=0;k<4;k++)   
        {
            if(is_valid(i+dx[k],j+dy[k]))
            {
                q.push({i+dx[k],j+dy[k]});
                vis[i+dx[k]][j+dy[k]]=1;      
            }
        } 
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,sx,sy,desx,desy;
    cin>>t;
	
    while(t--)
    {  
        cin>>n;m=n; 
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>mat[i][j];vis[i][j]=0;
                if(mat[i][j]==1) sx=i,sy=j;
                else if(mat[i][j]==2) desx=i,desy=j;
            }

        cout<<ssdp(sx,sy,desx,desy)<<"\n";  
    }
    
    return 0;
}