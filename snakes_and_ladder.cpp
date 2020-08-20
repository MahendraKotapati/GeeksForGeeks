#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

vector<ll>g[35];

ll bfs()
{   
    ll vis[35]={0},node,lvl;
    queue <pair<ll,ll>>q;
    q.push({1,0});vis[1]=1;

    while(!q.empty())
    {
        node = q.front().F; lvl = q.front().S;  q.pop();

        for(int child:g[node])
        {
            if(vis[child]==0) 
            {   
                if(child==30) return lvl+1;
                q.push({child,lvl+1});
                vis[child]=1;
            }
        }
    }
    return 0; 
        
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,num,a,b,n,mp[35];
    cin>>t;
	
    while(t--)
    {   
        memset(mp,0,sizeof(mp));
    
        cin>>num;
        for(i=0;i<num;i++)
            cin>>a>>b,mp[a]=b;
        
        for(i=1;i<=30;i++)
        {
            for(j=1;j<=6 && (i+j<=30) ;j++)
            {
                a = i+j; if(mp[a]) a = mp[a];
                g[i].pb(a);
            }   
        }
        
        cout<<bfs()<<"\n";
        for(i=0;i<30;i++) g[i].clear();
    }
    
    return 0;
}