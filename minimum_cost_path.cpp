#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define pll pair<ll,ll>
#define pp pair<ll,pll>
using namespace std;

ll arr[101][101],d[101][101],vis[101][101],n;
ll dx[]={-1,0,1,0},dy[]={0,1,0,-1};

bool is_valid(ll i,ll j)
{
    return (i>=0 && i<n) && (j>=0 && j<n);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,curr_dis,u,v;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>arr[i][j],vis[i][j]=0,d[i][j]=INT_MAX;

        priority_queue<pp,vector<pp>,greater<pp>>pq; //min-heap 
        d[0][0]=arr[0][0];
        pq.push({d[0][0],{0,0}});  // pq stores { dis,{x,y} };

        while(!pq.empty())
        {
            auto curr = pq.top(); pq.pop();
            curr_dis = curr.F; i = curr.S.F; j = curr.S.S;
            for(k=0;k<4;k++)
            {   
                u = i+dx[k]; v = j+dy[k];
                if(!is_valid(u,v)) continue;

                if(d[u][v]>arr[u][v]+curr_dis)
                    d[u][v] =  arr[u][v]+curr_dis;

                if(!vis[u][v]) 
                {
                    pq.push( {d[u][v],{u,v}} );
                    vis[u][v] = 1;
                }
            }
        }
        cout<<d[n-1][n-1]<<"\n";
    }
    
    return 0;
}