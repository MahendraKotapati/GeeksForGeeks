#include <bits/stdc++.h>
using namespace std;

bool dfs(int v,vector<int> adj[],vector<int>&vis)
{


    vis[v]=1;

    for(int i:adj[v])
    {
        if(vis[i]==1)
            return true;

        if(dfs(i,adj,vis))
                return true; 
             
    }
     
    return false;

}

bool isCyclic(int V, vector<int> adj[])
{
    
    vector <int>vis(V+1,0);

    for(int j=0;j<V;j++)
    {   
        if(vis[j]==0)
            if(dfs(j,adj,vis))
                return true;
    }
    return false;
}

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