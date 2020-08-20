#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

vector <ll>g[50];
ll vis[31],c,last;

ll dfs(ll node)
{
    vis[node] = 1;last=node;
    c++;
    for(int child:g[node])
    {   
        if(vis[child]==0)
            dfs(child);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n;
    cin>>t;  bool flag;
	
    while(t--)
    {
        cin>>n;
        vector<string>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j) continue;
                if(arr[i][arr[i].size()-1]==arr[j][0])  // if previous node last char equals to next node first char
                    g[i].pb(j); 
            }
        }
        flag = false;
        
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));  c = 0;
            dfs(i);
            if(c==n && arr[last][arr[last].size()-1]==arr[i][0])  // checking cyclicity
            {
                 flag=true; 
                 break;
            }
        }
        cout<<flag<<"\n";

        for(i=0;i<50;i++) g[i].clear();//clearing graph 

    }
    
    return 0;
}