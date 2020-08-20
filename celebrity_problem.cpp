#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)

/*int getId(int M[MAX][MAX], int n)
{
    int col_sum[n+1],i,j,c_count=0,temp=0,c_index;

    memset(col_sum,0,sizeof(col_sum));
    
    for(i=0;i<n;i++)
    {   
        temp=0;
        for(j=0;j<n;j++)
        {   
            if(i==j) continue;
            col_sum[j]+= (M[i][j]==1);
            temp += (M[i][j]==0);
        }
         
        if(temp==n-1)  c_count++,c_index=i;
    }
    if(c_count!=1) return -1;

    if(col_sum[c_index]==n-1)
        return c_index;
    return -1;
}
*/

int getId(int grid[MAX][MAX], int n)
{
    int candidate=0,i; // candidate is the person who may be the celebrity 

    for(i=0;i<n;i++)
        if(grid[candidate][i])  // if candidate knows i, candidate can't  be celebrity , so assign candidate =i
            candidate=i;

    // checking candidate is really celebrity 
    for(i=0;i<n;i++)
    {   
        if(i==candidate) continue;  // can't compare candidate with himself.
        if( grid[candidate][i] || !grid[i][candidate])  // if candidate knows i or i doesn't know candidate return -1;
    }       return -1;
    return candidate;

}

