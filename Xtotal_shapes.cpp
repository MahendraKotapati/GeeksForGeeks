#include<bits/stdc++.h>
using namespace std;

char grid[51][51];
int vis[51][51],dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int n,m;

bool is_valid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m && vis[i][j]==0 && grid[i][j]=='X');
}

void dfs(int i,int j)
{
    if(!is_valid(i,j))
        return ;

    vis[i][j]=1;
    for(int k=0;k<4;k++)
        dfs(i+dx[k],j+dy[k]);
    
}

int main()
{

    int t,i,j,total;  
    cin>>t;

    while(t--)
    {
        cin>>n>>m;  
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>grid[i][j];

        memset(vis,0,sizeof(vis));
        total = 0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(vis[i][j]==0 && grid[i][j]=='X')
                {   
                    total++;
                    dfs(i,j);
                }
        } 
        cout<<total<<"\n";      
    }



    return 0;
}

/*

2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO


11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44


OOOOXXO 
OXOXOOX 
XXXXOXO 
OXXXOOO


*/