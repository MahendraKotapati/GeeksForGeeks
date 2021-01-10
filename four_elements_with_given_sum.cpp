/*  

    https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1/
    we have to print unique quadruples 

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    
    sort(arr.begin(),arr.end());
    
    int p,q,l,r,curr_sum,pairs = 0,n = arr.size();
    vector<vector<int>>ans;
    unordered_map <string,int>mp;
    string str;
    
    for(p=0;p<n;p++)
    {
        for(q=p+1;q<n;q++)
        {
            curr_sum = k - (arr[p]+arr[q]);
            l = q+1; r = n-1;
            
            while(l<r)
            {
                if(arr[l]+arr[r]==curr_sum)
                {   
                    str = to_string(arr[p])+"#"+to_string(arr[q])+"#"+to_string(arr[l])+"#"+to_string(arr[r]);
                    if(mp.count(str)==0)
                    {
                        ans.push_back(vector<int>{arr[p],arr[q],arr[l],arr[r]});
                        mp[str]++;
                    }
                    l++;r--;  
                    // since we need only unique quardruples we increment/decrement pointers 
                    // once used array[l] or arr[r] cannot use one more time (in same instance -without changing p,q) because it leads to duplicate quarduple which produced earlier
                }
                else if(arr[l]+arr[r]<curr_sum)
                    l++;
                else 
                    r--;
            }
            
        }
    }
     return ans;
}