/* Time complexity : O(V^3)    */

#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
#define INF (ll)(1e7)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,n,g[105][105];
    string str;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>g[i][j];
                //g[i][j]=stol(str);
                
            }
        }   

        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]==10000000)
                    cout<<"INF"<<" ";
                else  
                    cout<<g[i][j]<<" ";
                    
            }
            cout<<"\n";
        }
        cout<<"\n";

    }
    
    return 0;
}

/*

1
4
1 0 343 3434
45 45 10000000 7
2 3 4 5
67 78 34 2

*/