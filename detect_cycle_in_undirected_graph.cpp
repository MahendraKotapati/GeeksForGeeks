// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
int vis[10004];

bool has_cycle(vector<int> g[], int node,int par)
{
    vis[node]=1;
    for(int child:g[node])
    {   
        if(child==par) continue;
        if(vis[child])   // means there is a back-edge 
            return true;
        vis[child]=1;
        if(has_cycle(g,child,node)) return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{   
    memset(vis,0,sizeof(vis));
    for(int i=0;i<V;i++)  // if graph is not connected 
    {   
        if(vis[i]==0)
            if(has_cycle(g,i,-1))  // a cycle is present if there is a back-edge (an edge to one of its ancestors except parent)
                return true;
    }
    return false;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends