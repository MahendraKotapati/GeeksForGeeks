#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

bool cmp(pair<ll,pair<ll,ll>>&p1,pair<ll,pair<ll,ll>>&p2)
{
    if(p1.first<p2.first)
        return true;
    return false;
}

ll find_par(ll i,vector <ll>&par)
{
    if(i==par[i])
        return i;
    return par[par[i]]=find_par(par[i],par);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,m,u,v,c,cost,flag;
    
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;    cost=0;  flag=0;
        vector <ll>g[n+1];
        vector < pair<ll,pair <ll,ll>> >edges;
        vector <ll>par(n+1);

        for(i=0;i<=n;i++)  par[i]=i;        

        for(i=0;i<m;i++)
        {
            cin>>u>>v>>c;
            edges.pb({c,{u,v}}) ;
            g[v].pb(u);   g[u].pb(v);
        }
        
        sort(edges.begin(),edges.end(),cmp);


        for(auto itr:edges)
        {   
            u=itr.S.F;  v= itr.S.S;
            u=find_par(u,par);
            v=find_par(v,par);

            if(u!=v)
            {
                par[v]=u;
                cost+=itr.F;
            }
        }

        for(i=1;i<=n;i++)
            if(i==par[i])
                flag++;

        if(flag==1)
            cout<<cost<<"\n";
        else
            cout<<"given graph is not  a connected graph"<<"\n";        

    }
    
    return 0;
}