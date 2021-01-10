/* for better solution  https://www.geeksforgeeks.org/check-mirror-n-ary-tree/  */

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 15
typedef long long ll;
using namespace std;

ll n,vis[maxn+1];
bool isSame;
vector<ll>g1[maxn+1],g2[maxn+1];

void dfs(ll node)
{
    vis[node]=1;
    stack<ll>s;
    for(ll child:g2[node])
        if(vis[child]==0)
        {   
            s.push(child);
            dfs(child);
        }
    g2[node].clear();

    while(!s.empty())
    {
        g2[node].pb(s.top());
        s.pop();
    }
}

void dfsIsSame(ll node)
{
    vis[node]=1;
    ll i=0;
    for(ll child1:g1[node])
    {
        if(vis[child1]==0)
        {   
            if(i>=g2[node].size() || child1!=g2[node][i]) {    // if child of G1 not equal to G2 or count of childs of G1 and G2 not equal return false
                isSame = false;     
                return;   
            }
            dfsIsSame(child1);
        }
        i++;
    }

}

ll isMirror()
{   
    memset(vis,0,sizeof(vis));
 
    dfs(1);  // reversing child nodes of each node

    isSame = true;
    memset(vis,0,sizeof(vis));

    dfsIsSame(1);  // comparing two trees 
    return isSame;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,e,u,v;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>e;
        for(i=0;i<e;i++)
        {
            cin>>u>>v;
            g1[u].pb(v);
        }

        for(i=0;i<e;i++)
        {
            cin>>u>>v;
            g2[u].pb(v);
        }

        cout<<isMirror()<<"\n";

        for(i=0;i<=maxn;i++) 
            g1[i].clear(),g2[i].clear();
    }
    
    return 0;
}

/*

2
3 2
1 2 1 3
1 3 1 2
3 2
1 2 1 3
1 2 1 3


*/