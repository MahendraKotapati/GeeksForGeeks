// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// User function template for c++
class Solution {
  public:
    int findMaxLen(string str) {
        // code here
        int i,len=str.length(),max_len,curr_len;
        stack<int>s;
        
        max_len = curr_len = 0;
        s.push(-1); // this is to get previous valid substring starting index
        
        for(i=0;i<len;i++)
        {
            if(str[i]=='(')
                s.push(i);
            else  
            {
                if(s.top()==-1|| str[s.top()]==')')
                    s.push(i);
                else if(str[s.top()]=='(')
                {
                    s.pop(); // important , to get previous valid substring starting index , for below line , now s.top() contains previous valid substring starting index
                    curr_len = i-s.top(); // s doen't become empty because we have initally pushed -1 
                    max_len = max(max_len,curr_len);
                }
            }
        }
        
        return max_len;
        
    }
    
    /* ()()()  */
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends