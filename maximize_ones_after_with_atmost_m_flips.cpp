#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t,n,m,max_len,i,j,count;
	cin>>t;
	
	while(t--)
	{
	    cin>>n;  
        j = 0;  // pointing to starting of subarray .
        max_len = 0;
	    
	    vector<int>arr(n);
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	    cin>>m; count = m;
	    
	    for(i=0;i<n;i++)
	    {
	        if(arr[i]==1)
	            continue;
	            
	        if(count>0) 
    	    {     
    	        count--; // flipping zero to one
                continue;
    	    }
            // we have used all flips , so updata max_len 
    	    max_len = max(i-j,max_len);
    	    
    	    while(j<i && arr[j]==1)  // removing starting flip by travrsing j till arr[j] is 0 if not found it simply go beyond i 
    	        j++;
    	    j++; // we done this because ,for next time j should be point to starting of subarray 
	    }
	    max_len = max(i-j,max_len);
	    cout<<max_len<<"\n";
	    
	}
	return 0;
}