#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll n,m,s1,s2,d1,d2,vis[26][26],min_steps;
ll dx[] = {-2,-2,-1,-1,1,1,2,2};
ll dy[] = {-1,1,-2,2,-2,2,-1,1};

bool is_valid(int i,int j)
{
    return (i>=1 && i<=n && j>=1 && j<=m && vis[i][j]==0 ); 
}

void dfs(ll i,ll j,ll count)  // dfs not working only bfs working
{
    if(!is_valid(i,j))
        return ;

    if(i==d1 && j==d2)
    {   
        min_steps = min(min_steps,count);
        return ;
    }
    vis[i][j] = 1; 

    for(int k=0;k<8;k++)
        dfs(i+dx[k],j+dy[k],count+1);   

    vis[i][j] = 0; 
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,lvl;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;
        cin>>s1>>s2>>d1>>d2; 

        queue <pair<ll,pair<ll,ll>>>q;

        memset(vis,0,sizeof(vis));   
        min_steps = INT_MAX;

        //dfs(s1,s2,0);
        q.push({0,{s1,s2}});   vis[s1][s2] = 1;  

        while(!q.empty())
        {
            auto curr = q.front();
            i = curr.S.F; j = curr.S.S; lvl = curr.F;

            if(i==d1 && j==d2)
                break ;

            q.pop();

            for(k=0;k<8;k++)
            {
                if(is_valid(i+dx[k],j+dy[k]))
                {   
                    vis[i+dx[k]][j+dy[k]] = 1;
                    q.push({lvl+1,{i+dx[k],j+dy[k]}});
                }
            }

        }

      
        if(q.empty()) lvl = -1;
        cout<<lvl<<"\n";
    }
    
    return 0;
}

/*

2
4 7
2 6 2 4
7 13
2 8 3 4

*/