/* https://www.geeksforgeeks.org/find-recurring-sequence-fraction/  */

#include<bits/stdc++.h>
using namespace std;


class Solution{
    
	public:
	string fractionToDecimal(int n, int d) {
	     
	    int idx,rem;
	    unordered_map <int,int>mp;
	    string ans="";
	    
	    ans = to_string(int(n/d))+ ((n%d)? "." : "");  // ternary is for cases when 10/2 = 5 not 5.0
	    
	    rem = n%d; mp[rem] = ans.length();
	   
	    while(rem!=0)
	    {
        /* take example of 1/100 = 0.01  */
	       rem*=10;  // important
	       ans+= to_string(rem/d);
	       rem = rem%d;
	       
	       if(mp.count(rem)) // recurring sequence is formed only if remainder repeats 
	       {
	           idx = mp[rem];
	           ans = ans.substr(0,idx)+"("+ans.substr(idx)+")";
	           return ans;
	       }
	       mp[rem] = ans.length();
	    }
	    
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends