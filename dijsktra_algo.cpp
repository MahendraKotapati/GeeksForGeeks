#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}

// } Driver Code Ends
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/


int get_min_key(int dis[],int vis[],int V)
{
    int i,u,mini=INT_MAX;

    for(i=0;i<V;i++)
        if(mini>dis[i] && vis[i]==0)
            mini=dis[i],u=i;
    return u;
}


void dijkstra(vector<vector<int>> graph, int src, int V)
{
    
    int i,v,w,u,c=0;
    int  dis[V+1],vis[V+1];

    
    for(i=0;i<V;i++)
        dis[i]=INT_MAX,vis[i]=0;

    
   dis[src]=0;

    while(c!=V)
    {    
        u = get_min_key(dis,vis,V);
        vis[u]=1;
        
        for(v=0;v<V;v++)
        {
            if(graph[u][v] &&  dis[v]>dis[u]+graph[u][v] )  
                dis[v] = dis[u]+graph[u][v];
            
        }
        c++;
    }

    for(i=0;i<V;i++)
        cout<<dis[i]<<" ";
    cout<<"\n"; 

    
}