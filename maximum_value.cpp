#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{

    int t,n,arr[500],i,j,maxi;
    cin>>t;
    while(t--)
    {
        cin>>n;   vector <int>forw(10000,INT_MIN),back(10000,INT_MIN);  maxi=INT_MIN;
        for(i=0;i<n;i++)  cin>>arr[i];  
        if(n<4)   {    cout<<"-1\n";  continue;  }

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)    
            {
                forw[j]=max(forw[j],arr[j]-arr[i]);
            }
        }
        
        for(i=n-1;i>0;i--)
        {
            for(j=i-1;j>=0;j--)     
            {
                back[j]=max(back[j],arr[i]-arr[j]);
            }
        }
       // for(i=1;i<n;i++)  cout<<back[i]<<" "; cout<<"\n";
        for(i=1;i<n;i++)  
        {
            for(j=i+1;j<n-1;j++)  
            {
                maxi=max(maxi,forw[i]+back[j]);
            }
        }
        //sort(diff,diff+d);
        cout<<maxi<<"\n";

    }


    return 0;
}