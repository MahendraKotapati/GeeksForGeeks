#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,i,t,sum,mini;
	cin>>t;
	
	while(t--)
	{
	    cin>>n;  sum = 0; mini = INT_MAX;
	    vector<int>arr(n);
	    
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	   
	    for(i=0;i<n;i++)
	    {
	        if(sum+arr[i]<mini)
	            mini = sum+arr[i];
	        sum+=arr[i];
	    }
        
	    if(mini>=0)
	        cout<<1<<"\n";
	    else 
	        cout<<abs(mini)+1<<"\n";
	    
	}
	return 0;
}