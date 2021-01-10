/*  
    https://www.youtube.com/watch?v=tWDUjkMv6Lc
    https://www.youtube.com/watch?v=eKOMXcmKF7w

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {

public:		
	int lps(string s)
	{
	    int n = s.length(),i,j;
	    int LPS[n];
	       
	    LPS[0] = 0;
	    
	    for(i=1;i<n;i++)
	    {
	        j = LPS[i-1];   
            // always LPS[i]<=LPS[i-1]+1 , so we take LPS[i-1] and now check s[i] , s[j] because s[0:j-1]  already LPS of length j
	        while(j>0 && s[i]!=s[j])
	           j = LPS[j-1];
	        
	        if(s[i]==s[j])
	            j++;
	            
	        LPS[i] = j;  
	    }
	    return LPS[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends