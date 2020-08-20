// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];

    
	while(t--)
	{
		memset(g,0,sizeof(g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
 bool isBipartite(int G[][MAX],int V)
{
    
    queue <int>q;
    int vis[V+1],col[V+1],i,j,v;
    
    memset(vis,0,sizeof(vis));
    memset(col,-1,sizeof(col));
    
  for(j=0;j<V;j++)
  {
    if(vis[j]==1)
        continue;
    q.push(j); vis[j]=1;col[j]=0;
    
    while(!q.empty())
    {
        v=q.front(); q.pop();
        
        for(i=0;i<V;i++)
        {
            if(G[v][i])
            {   
                if(vis[i]==0)
                    q.push(i),vis[i]=1;
                if(col[i]==-1)
                    col[i]=!col[v];
                else if(col[i]==col[v])
                    return false;
            }
            
        }
    }
  }  
    return true;
    
}