#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll n,m,mat[21][21],ans[21][21],vis[21][21];

bool is_valid(ll i,ll j)
{
    return (i>=0 && i<n) && (j>=0 && j<m) && (vis[i][j]==0) && (mat[i][j]==1);
}

void ssdp(ll i,ll j,ll dis)
{
    if(!is_valid(i,j))
        return ;
    
    vis[i][j]=1;
    ans[i][j]=min(ans[i][j],dis);

    for(ll di=-1;di<=1;di++)
    {
        for(ll dj=-1;dj<=1;dj++)
        {
            if( (di==-1 && dj==0) || (di==0 && dj==1) || (di==1 && dj==0) || (di==0 && dj==-1) )
            {
                if(is_valid(i+di,j+dj))
                    ssdp(i+di,j+dj,dis+1),vis[i+di][j+dj]=0;
                
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,x,y;
    cin>>t;
	
    while(t--)
    {  
        cin>>n>>m; 
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>mat[i][j],ans[i][j]=INT_MAX,vis[i][j]=0;
        
        cin>>x>>y;
        ssdp(0,0,0); // ssdp(i,j,dis);

        if(ans[x][y]==INT_MAX)
           ans[x][y]=-1;

        cout<<ans[x][y]<<"\n"; 

         
    }
    
    return 0;
}