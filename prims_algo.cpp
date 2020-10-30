/*  time complexity : O(V^2)  */

#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

 

int get_min_key(int dis[],int mst[],int V)
{
    int i,u,mini=INT_MAX;

    for(i=0;i<V;i++)
        if(mini>dis[i] && mst[i]==0)
            mini=dis[i],u=i;
    return u;
}




int spanningTree(int V,int E,vector<vector<int> > graph)
{
     
    int i,j,w,u,mst_weight=0,mst_edges=V-1,c=0;
    int mst[V+1],par[V+1],dis[V+1];

    
    for(i=0;i<V;i++)
        dis[i]=INT_MAX,mst[i]=0;   // dst[i] stores minimum of all edges connected to it.

    
   dis[0]=0;

   while(c!=V)
   {    

        u = get_min_key(dis,mst,V);   // O(v) complexity
        mst[u]=1;
        
        for(j=0;j<V;j++)     // O(v) complexity
        {
            if(graph[u][j]!=INT_MAX &&  dis[j]>graph[u][j] && mst[j]==0 )
                dis[j] = graph[u][j],par[j]=u;    
            
        } 
        
        mst_weight+= dis[u];
        c++;
    } 
   
    return mst_weight;
     
}