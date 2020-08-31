#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll arr[101][101],n,m;
ll dx[4]={-1,0,1,0};
ll dy[4]={0,1,0,-1};

bool is_valid(ll i,ll j)
{
    return (i>=0 && i<n && j>=0 && j<m && arr[i][j]==1);
}


int bfs()
{
    ll level = 0,curr_lvl=0,x,y,i,j,count=0,_time;
    queue <pair<ll,ll>>q;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {   
            if(arr[i][j]==2)
            q.push({i,j});            
        }
    }
    
    _time = 0;
    while(!q.empty())
    {  
        count = q.size(); 

        while(count--)  // this is to know level
        {
            auto curr = q.front();
        
            i = curr.F; j = curr.S;
            //arr[i][j] = 2;  we shouldn't do here
            q.pop();

            for(y=0;y<4;y++)
            {
                if(is_valid(i+dx[y],j+dy[y]))
                {   
                    arr[i+dx[y]][j+dy[y]] = 2;  // very important , while considering immediately we make adjacent one rotten because , other
                    q.push({i+dx[y],j+dy[y]});
                }

            }
        }
        if(!q.empty())  // to understand this case assume only 1 one element in queue and futher no more elements are added.
        _time++;  // this is like level
    }
    
    return _time;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;   

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>arr[i][j];
                
        
         
        int ans = bfs();  
         
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(arr[i][j]==1) ans = -1;

        cout<<ans<<"\n";
    }
    
    return 0;
}

/*

to understand why we immediately rottening just check below case you can understand
[[2,2],[1,1],[0,0],[2,0]]

*/