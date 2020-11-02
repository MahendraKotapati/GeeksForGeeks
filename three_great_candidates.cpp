#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    long long maxProduct(int arr[], int n) {
         
        
        int min1,min2,max1,max2,max3;
        
        min1 = min2 = INT_MAX;
        max1 = INT_MIN; max2 = INT_MIN; max3 = INT_MIN;
        
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=min1)
            {    
                min2 = min1;
                min1 = arr[i];
            }
            else if(arr[i]<=min2)
                min2 = arr[i];   
            
            if(arr[i]>=max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = arr[i];
            }
            else if(arr[i]>=max2)
            {
                max3 = max2;
                max2 = arr[i];
            }
            else if(arr[i]>=max3) 
                max3 = arr[i];
                
        }
        
       
      
        long long a,b;
        a = (long long)min1*(long long)min2*(long long)max1;
        b = (long long)max3*(long long)max2*(long long)max1;
        
        return max(a,b);
        
        
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends