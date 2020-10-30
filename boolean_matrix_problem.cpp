#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main()
{

    int t,n,m,i,j,k;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>arr[i][j];
        

        // row -1 , col -2
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]!=1)
                    continue;

                if(arr[i][0]!=-1 && arr[i][0]!=-3)
                    for(k=0;k<m;k++)
                    {
                        if(k==j) continue;
                        if(arr[i][k]!=1)
                            arr[i][k] += -1; 
                    }


                if(arr[0][j]!=-2 && arr[0][j]!=-3)
                    for(k=0;k<n;k++)
                    {
                        if(i==k) continue;
                        if(arr[k][j]!=1) 
                            arr[k][j] += -2;
                    }
            }
        } 


        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(arr[i][j]==0) cout<<"0"<<" ";
                else  cout<<"1"<<" ";
            cout<<"\n";      
        }
    }

    return 0;
}


/*

2 2
1 0
0 0


*/