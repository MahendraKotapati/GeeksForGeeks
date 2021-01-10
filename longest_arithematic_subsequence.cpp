/* https://leetcode.com/problems/longest-arithmetic-subsequence/ */

class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        
        
        int n = arr.size();
        if(n==0) return 0;
        int i,j,diff,dp[n][1003],maxi;
        
        
        memset(dp,0,sizeof(dp));
        
        for(i=0;i<n;i++)
        {
            //dp[i][0] = 1;
            for(j=0;j<i;j++)
            {
                diff = arr[i]-arr[j]+500;
                dp[i][diff] = max(dp[i][diff],dp[j][diff]+1);
                
            }
        }
        maxi = 0;
        
        for(i=0;i<n;i++)
            for(j=0;j<1003;j++)
            maxi = max(maxi,dp[i][j]);
            
        return maxi+1;
    }
};



/* https://www.interviewbit.com/problems/longest-arithmetic-progression/ */

int Solution::solve(const vector<int> &arr) {
    
        int n = arr.size();
        if(n==0) return 0;
        int i,j,diff,maxi;
        vector< unordered_map<int,int> > dp(n);
         
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                diff = arr[i]-arr[j];
                if(dp[j].count(diff))
                    dp[i][diff] = max( (dp[i].count(diff))? dp[i][diff]:0 , dp[j][diff]+1);
                else 
                    dp[i][diff]  = 1; // actually set to 2 but , in return we making +1 so, set to 1
                
            }
        }
        
        maxi = 0;
        
        for(i=0;i<n;i++)
            for(auto j: dp[i])
            maxi = max(maxi,j.second);
            
        return maxi+1;
}




