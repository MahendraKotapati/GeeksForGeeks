#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll u,v,vis[11];
//vector<ll>g[11];

int dfs(int node,vector<ll>(&g)[101])
{
    if(node==v)
        return 1;
    //cout<<"loop";

    vis[node]=1;
    int count = 0;

    for(int child:g[node])
        if(vis[child]!=1)
            count+=dfs(child,g);

    vis[node] = 0;  // vis is nothing but recursion stack
    
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,e;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>e;    
        vector<ll>g[100+1];

        memset(vis,0,sizeof(vis));

        for(i=0;i<e;i++)
            cin>>u>>v,g[u].pb(v);

        cin>>u>>v;
        cout<<dfs(u,g)<<"\n";
        //for(i=0;i<=n;i++) g[i].clear();
    }
    
    return 0;
}

/*

1
4 6
0 1 0 2 0 3 2 0 2 1 1 3
2 3


*/