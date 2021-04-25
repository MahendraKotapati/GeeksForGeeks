// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
vector <int> maxOfMin(int arr[], int n);
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        vector <int> res = maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to print maximum of minimum of every window size
// arr[]: input array
// N: size of array
vector <int> maxOfMin(int arr[], int n) {
     
    int left[n],right[n],i,j,len;
    // left[i] stores next smaller element of arr[i] in left side
    // right[i] stores next smaller element of arr[i] in right side
    
    vector<int>ans(n+1,INT_MIN);
    stack <int>s;
    
    for(i=0;i<n;i++) 
        left[i] = -1,right[i] = n;
        
     
    s.push(n-1);
    
    for(i=n-2;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()]>=arr[i] )
            s.pop();
            
        if(!s.empty()) 
            right[i] = s.top(); 
            
        s.push(i);
    }
    
    // clear the stack for the next use
    while(!s.empty())   
        s.pop();
        
    s.push(0);
    
    for(i=1;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>=arr[i] )
            s.pop();
            
        if(!s.empty()) 
            left[i] = s.top(); 
        s.push(i);
    }
    
    for(i=0;i<n;i++)
    {
        len = right[i]-left[i]-1;
        ans[len] = max(ans[len],arr[i]);
    }
    
    for(i=n-1;i>=0;i--)  // unable to understand here
    {
        ans[i] = max(ans[i],ans[i+1]);         
    }
    
    return vector<int>(ans.begin()+1,ans.end());  // we don't need length 0 window answer
     
}