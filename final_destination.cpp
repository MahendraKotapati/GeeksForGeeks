// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution {
  public:
    int canReach(long long a, long long b, long long x) {
        // code here
        int min_steps  = abs(a)+abs(b);  // minimum needed steps 
        if(min_steps>x)  
            return 0;
        if((x-min_steps)%2==0) // if given steps greater than min_steps we should use that steps in even pairs (like go forward and then backward so , we remain at same position)
            return 1;
        return 0;
    }

   

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,x;
        
        cin>>a>>b>>x;

        Solution ob;
        cout << ob.canReach(a,b,x) << endl;
    }
    return 0;
}  // } Driver Code Ends