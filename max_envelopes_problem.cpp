class Solution {
    
public :
    static bool cmp(const vector<int>&v1,const vector<int>&v2)
    {
        return (v1[0]*v1[1]>v2[0]*v2[1]);
    }
    
public:
    bool is_safe(int a1,int b1,int a2,int b2)
    {
        return (a1<a2 && b1<b2);
    }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        
        
        sort(arr.begin(),arr.end(),cmp);
        
        int n = arr.size(),i,j; 
        
        if(n==0) return 0;
        
        int dp[n];
        
        for(i=0;i<n;i++)
        {
            dp[i]=1;
            for(j=0;j<i;j++)
                if(is_safe(arr[i][0],arr[i][1],arr[j][0],arr[j][1]) && dp[i]<dp[j]+1)
                       dp[i] = dp[j]+1;
        }
        
        return *max_element(dp,dp+n);
    }
};


/*  
    https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation

 */
#include <bits/stdc++.h> 
using namespace std; 


bool cmp(vector<int>& a, vector<int>& b) { 
	return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]); 
}

int maxEnvelopes(vector<vector<int> >& envelopes) 
{ 
	// Number of envelopes 
	int N = envelopes.size(); 

	if (N == 0) 
		return N; 

	// Sort the envelopes in increasing 
	// order of width and decreasing order 
	// of height is width is same                                    [width,height]
    // this is done becaouse we need strictly incresing subsequence, [3,3] can't fit in [3,4] , 
    // if we don't sort height in  descresing order n case of tie of width, then algorithms count as incresing subsequenc but it is not.
	sort(envelopes.begin(), envelopes.end(), cmp); 

	// To store the longest increasing 
	// sequence of height 
	vector<int> dp; 

	// Finding LIS of the heights 
	// of the envelopes 
	for (int i = 0; i < N; ++i) { 
		auto iter = lower_bound(dp.begin(), dp.end(), envelopes[i][1]); 

		if (iter == dp.end()) 
			dp.push_back(envelopes[i][1]); 
		else if (envelopes[i][1] < *iter) 
			*iter = envelopes[i][1]; 
	} 

	// Return the result 
	return dp.size(); 
} 

// Driver Code 
int main() 
{ 
	// Given the envelopes 
	vector<vector<int> > envelopes 
		= { { 4, 3 }, { 5, 3 }, { 5, 6 }, { 1, 2 } }; 

	// Function Call 
	cout << maxEnvelopes(envelopes); 
	return 0; 
} 
