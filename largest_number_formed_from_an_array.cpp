#include <bits/stdc++.h>
using namespace std;
class Solution{

public:
    static bool cmp(string a,string b)
    {
        return a+b>b+a;  // we can't directly do a>b because for ex 4 40 if we do a>b then 404 but optimal is 440 
    }
public:
	string printLargest(vector<string> &arr) {
	     
	     sort(arr.begin(),arr.end(),cmp);  // sorting the strings in decreasing order 
	     
	     int n = arr.size(),i;
	     string ans = "";
	     
	     for(i=0;i<n;i++)
	        ans += arr[i];
	       
	      return ans;
	     
	}
	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends