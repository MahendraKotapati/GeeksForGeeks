// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

int vis[1003];

bool has_cycle(vector<int> g[],int node)
{
    vis[node]=1;

    for(int child:g[node])
    {   
        if(vis[child]==2)  // if a child is visited (completely explored)
            continue;
        if(vis[child]==1) // if child is recursion stack comes again means there is cycle 
            return true;
        
        vis[child]=1;  // node is in recursion stack 
        if(has_cycle(g,child))
            return true;
    }
    vis[node]=2; // means node is explored completely,  
    return false;
}

bool isCyclic(int V, vector<int> g[])
{   
    memset(vis,0,sizeof(vis));

    for(int i=0;i<V;i++)
    {   
        if(vis[i]==0)
        if(has_cycle(g,i)) return true;
    }
    return false;
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends