#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends





int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int i,j,count=0,pre=-1;
    int vis[n+1][n+1];
    pq.push({mat[0][0],{0,0}});
    vis[0][0]=1;

    memset(vis,0,sizeof(vis));
    
    while(count<k)
    {
        i = pq.top().second.first; j = pq.top().second.second;
        pq.pop();
        
        if(i+1<n && vis[i+1][j]==0)
        {   
            vis[i+1][j]=1;
            pq.push({mat[i+1][j],{i+1,j}});
        }

        if(j+1<n && vis[i][j+1]==0)
        {   
            vis[i][j+1]=1;
            pq.push({mat[i][j+1],{i,j+1}});
        }

        count++;
    }
    
    return mat[i][j];
}


/*

5
7 17 27 36 38
14 23 35 38 43 
19 26 42 49 50 
23 33 48 52 53 
30 40 52 56 64
13

*/
