#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    unsigned long long int optimalKeys(int n) {
        
        if(n<=6)
            return n;
            
        int dp[n+1],i;
        
        for(i=0;i<=6;i++)
            dp[i] = i;    
        
        // we can use three key strokes for Ctrl A, Ctrl C , Ctrl V
        // we can use four key strokes for Ctrl A, Ctrl C , Ctrl V ,Ctrl V 
        // we can use five key strokes for Ctrl A, Ctrl C , Ctrl V ,Ctrl V , Ctrl V
        // we don't do one more Ctrl V because instead of doing it we do Ctrl A, Ctrl C , Ctrl V
        for(i=7;i<=n;i++)
            dp[i] = max(max(2*dp[i-3],3*dp[i-4]),4*dp[i-5]);
        
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  