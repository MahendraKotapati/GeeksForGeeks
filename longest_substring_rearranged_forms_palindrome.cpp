#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubstring(string s) {
        
        unordered_map <long int,int>mp;
        int n = s.length(),i,j,ans=0;
        long int mask=0,mask2;
        // mask has 0-25 bits  corresonding to a-z chars i bit is 0 if correponding char occur even times

        mp[mask] = -1;  // if all even chars occurs in s[0:i] then answer will be of length i+1
        
        for(i=0;i<n;i++)
        {
            mask = mask^(1<<(s[i]-'a'));

            if(mp.count(mask))
                ans = max(ans,i-mp[mask]);
            else 
                mp[mask]=i;
            
            // for odd length palindrome
            for(j=0;j<26;j++)
            {
                mask2 = mask^(1<<j);
                if(mp.count(mask2))
                    ans = max(ans,i-mp[mask2]);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}  // } Driver Code Ends