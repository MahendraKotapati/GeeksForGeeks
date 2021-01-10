// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution{
    
public:	
	string addBinary(string A, string B)
	{
	    int i,j,sum,carry=0;
	    string res="";
	    i = A.length()-1 ; j = B.length()-1;
	    
	    while(i>=0||j>=0)
	    {
	        sum = carry;
	        if(i>=0) sum+= A[i]-'0';
	        if(j>=0) sum+= B[j]-'0';
	        
	        res += (sum%2)+'0';  // if sum is odd only then res[] is 1
	        carry = sum/2;   // carry is always if sum>1
	        i--;j--;
	    }
	   
	    
	    if(carry) res +='1';
	   
	    reverse(res.begin(),res.end());
	    
	    for(i=0;i<res.length();i++)  // to remove leading zeroes 
	       if(res[i]=='1')           
	           return res.substr(i);
	    return "";
	    
	}
};

/*
        1
     10111
     10111
    -------
        10
*/


// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends