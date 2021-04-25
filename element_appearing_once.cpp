/* 

https://leetcode.com/problems/single-element-in-a-sorted-array/
https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/100754/Java-Binary-Search-short-(7l)-O(log(n))-w-explanations
find element appearing once in sorted array  

*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    
public:	
	int search(int arr[], int n){

        /*  
            find mid then if mid left or right element is not equal to mid then mid is answer
            else if(left array size is odd) answer is in left subarray
            else if(right array size is odd) then answer is in right subarray
        */
	    
	    int low,high,mid,s;
	    low = 0; high = n-1;
	    
	    while(low<=high)
	    {
	        mid = (low+high)/2;
	        
	        if(mid-1>=low && arr[mid-1]==arr[mid])
	        {
	            s = (mid-2)-low+1;
	            
	            if(s&1)
	                high = mid-2;  // mid-2 because arr[mid-1] == arr[mid]
	            else  
	                low = mid+1;
	        }
	        else if(mid+1<=high && arr[mid+1]==arr[mid])
	        {
	            s = high-(mid+2)+1;
	            
	            if(s&1)
	                low = mid+2;  // mid+2 because arr[mid]==arr[mid+1]
	            else 
	                high = mid-1;
	        }
	        else
	            return arr[mid];      
	    }
	    
	}
};



// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends