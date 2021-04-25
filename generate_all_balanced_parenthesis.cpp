#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends


//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses

void generateParenthesis(int idx,int n,int open,int close,string str,vector<string>&ans)
{
    
    if(close==n)  // if close=n means open is also n 
    {
        ans.push_back(str);
        return ;
    }
      
    if(open<n)  
        generateParenthesis(idx+1,n,open+1,close,str+'(',ans);
        
    if(open>close)
        generateParenthesis(idx+1,n,open,close+1,str+')',ans);   
}

 

vector<string> AllParenthesis(int n) 
{
    vector<string>ans;
    generateParenthesis(0,n,0,0,"",ans); 
    return ans;
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> result = AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends