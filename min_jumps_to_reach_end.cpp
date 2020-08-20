#include<bits/stdc++.h>
typedef long int li;
using namespace std;

li solve(vector <li>&arr,li n)
{

    if(n<=1)
      return 0;
    
    if(arr[0]==0)
       return -1;

    li maxi=0,i,jumps=1,max_index,steps;
    max_index=steps=arr[0];

    for(i=1;i<n;i++)
    {
        if(i==n-1)
          return jumps;  
        
        max_index=max(max_index,i+arr[i]);  
        steps--;

        if(steps==0)
        {
            jumps++;
            if(i>=max_index)
                return -1;   
            steps=max_index-i;
        }

    }
    return jumps;

}
 

int main()
{
    li t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector <li>arr(n);

        for(i=0;i<n;i++)
             cin>>arr[i];
        
        cout<<solve(arr,n)<<"\n";   
    }

    return 0;
}