#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

ll g[105][105],n,vis[105];

bool dfs(ll p,ll v)
{
    if(g[p][v])
        return true;
    
    if(vis[p])
        return  false;

    vis[p]=1; 

    for(ll i=0;i<n;i++)
    {
        if(g[p][i])
        {
            if(dfs(i,v)) 
            {  
                g[p][v]=g[i][v]=1; 
                vis[p]=0;
                return true; 
            }
        }
    }
    vis[p]= 0;
    return false;
}

void transitive_closure()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            if(g[i][j]==0)
                g[i][j]=dfs(i,j);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,u,v;
    cin>>t;
	
    while(t--)
    {
         cin>>n;
          
         for(i=0;i<n;i++)
            for(j=0;j<n;j++) 
                 cin>>g[i][j];

         
         for(i=0;i<n;i++)
            g[i][i]=1;

        memset(vis,0,sizeof(vis));
        transitive_closure();

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cout<<g[i][j]<<" ";
        cout<<"\n";

    }
    
    return 0;
}

/*

1
4
1 1 0 1 0 1 1 0 0 0 1 1 0 0 0 1

*/