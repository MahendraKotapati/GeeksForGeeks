/* https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo/0# */

#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define maxn 25
using namespace std;

vector<ll>g[maxn];
ll in_stack[maxn],in[maxn],low[maxn],vis[maxn],timer,SSC;
stack <ll>s;

void dfs(ll node)
{
    in[node] = low[node] = timer++;
    vis[node] = 1;
    s.push(node);
    in_stack[node] = 1;

    for(ll child:g[node])
    {
        if(vis[child]==1 && in_stack[child]==1)    // the child node through which we are trying to minimize low value should be in_stack it is targens rule
            low[node] = min(low[node],in[child]);
        
        else if(vis[child]==0)
        {
            dfs(child);
            if(in_stack[child]==1)   // targes rule
                low[node] = min(low[node],low[child]);
        }
    }

    ll u;

    if(low[node]==in[node])   // we found one of the  SSC
    {
        SSC++;
        while(1)
        {
            u = s.top(); 
            cout<<u<<" ";
            s.pop();  in_stack[u] = 0;
            if(u==node)
                break;
        }
        cout<<",";
    }
}

int main()
{

    ll t,n,m,i,u,v;
    cin>>t;

    while(t--)
    {   
        timer = 1; SSC = 0;
        memset(vis,0,sizeof(vis));
        memset(in_stack,0,sizeof(in_stack));

        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>u>>v;
            g[u].pb(v);
        }

        for(i=0;i<n;i++)
            if(vis[i]==0)
                dfs(i);


        for(i=0;i<maxn;i++) g[i].clear();
    }

    return 0;
}