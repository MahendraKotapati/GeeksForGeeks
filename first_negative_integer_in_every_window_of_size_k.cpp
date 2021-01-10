#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,i,k,n;
	cin>>t;
	
	
	while(t--)
	{
	    cin>>n;
	    vector<int>arr(n);
	    queue<int>q;
	    
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	    cin>>k;
	    
	    for(i=0;i<k;i++)
	        if(arr[i]<0)
	           q.push(arr[i]);
	   
	    if(q.empty()) 
	        cout<<"0"<<" ";
	    else 
	        cout<<q.front()<<" ";
	    
	    for(i=k;i<n;i++)
	    {   
	        if(arr[i]<0)
	            q.push(arr[i]);
	            
	        if(arr[i-k]<0)
	            q.pop();
	            
	        if(q.empty()) 
	            cout<<"0"<<" ";
	        else 
	        cout<<q.front()<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}