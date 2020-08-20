// { Driver Code Starts
#include<bits/stdc++.h>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; }
    void addEdge(int v, int w);
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "0\n";    //none
    else if (res == 1)
        cout << "1\n";    //Euler path
    else
        cout << "2\n";    //Euler cycle
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>> v>>e;
		Graph g1(v);
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
		g1.addEdge(a, b);
		}
		test(g1);
	}
    return 0;
}// } Driver Code Ends


void dfs(const list <int>g[],int node,int vis[105],int *node_count)
{
    int c=0;
    vis[node] = 1; (*node_count)++;

    for(auto child:g[node])
        if(vis[child]==0) 
            dfs(g,child,vis,node_count);
    
}

bool Graph::isConnected() 
{   
    int vis[105]={0},v=this->V,i,e=0,node_count,cc;

    cc= 0; // connected_components 

    for(i=0;i<v;i++)
    {   
        node_count=0;
        if(vis[i]==0)
        {
            dfs(this->adj,0,vis,&node_count);  
            if(node_count!=1) 
                cc++;
        }
    }

    return !(cc>1);// cc>1 means no of connected components > 1 so,graph is not connected .
}

int Graph::isEulerian()
{
    if(this->isConnected()==0) return 2;
    
    int vis[105]={0},v=this->V,i,odd_degree;

    odd_degree = 0;
    
    for(i=0;i<v;i++) 
        if((this->adj[i].size())&1) 
             odd_degree++;
    
    /* odd_degree will not be 1 , because for a undirected graph  degree of graph  is always even , 
    if no.of odd_degree nodes are 1 then total degree of graph is also odd which is not possible  */
    
    if(odd_degree==0)  // euler cycle
        return 2;
    else if(odd_degree==2) // euler path
        return 1;
    return 0;
    
}