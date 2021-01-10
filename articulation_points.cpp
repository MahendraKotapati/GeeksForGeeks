/*  
     
    https://cp-algorithms.com/graph/cutpoints.html

*/

#include <bits/stdc++.h>
#define maxn 1003
using namespace std;
int vis[maxn],in[maxn],low[maxn],timer;
vector<int> g[maxn];


bool dfs(int node,int par)
{
    vis[node]=1;
    in[node] = low[node] = timer;
    timer++;

    int child_count = 0;

    for(int child:g[node])
    {
        if(child==par) continue;

        if(vis[child])  // back-edge
            low[node] = min(low[node],in[child]); // since node->child is backedge child has less in[] time so, we can update low[node]
        else   
        {
            child_count++;
            dfs(child,node);
            low[node] = min(low[node],low[child]); // if child has back edge and updated its low then parent (here node) can also update its low through child

            if(low[child]>=in[node] && par!=-1)  // here >= where as inbridges >
                cout<<node<<"is Cut vertex";

        }
    }

    if(par==-1 && child_count>1)
        cout<<node<<" is Cut vertex";
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    for(int i=0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        g[u].push_back(v);
            g[v].push_back(u);
	    }
	    
        timer = 0;
	    cout << dfs(0,-1) << endl;

        for(int i=0;i<maxn;i++) g[i].clear();
	    
	}
	
	return 0;
}  // } Driver Code Ends