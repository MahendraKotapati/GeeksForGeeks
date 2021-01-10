/*  https://www.youtube.com/watch?v=WPr1jDh3bUQ */

#include <bits/stdc++.h>
using namespace std;
int dp[505];

class Solution{
    
public:
    bool is_palindrome(int i,int j,string str)
    {
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;j--;
        }
        
        return true;
    }

public:
    int min_partitions(int i,int n,string str)
    {
        
        if(i>=n)
            return -1;  // important at last we don't need to make cut ,but we are adding one in function call to compensate that we return -1;
        
        /*  
            Time complexity : O(n^3)   because , this memoization has n distinct states each state solved in O(n^2) time  
            we can reduce Time complexity to O(n^2) by storing storing palindrome or not in dp array which costs O(n^2) time  O(n^2) space
        */

        if(dp[i]!=-1)       
            return dp[i];
        
        int j,mini=INT_MAX;
        
        for(j=i;j<n;j++)
        {
            if(is_palindrome(i,j,str))
                mini = min(1+min_partitions(j+1,n,str),mini);
        }
        
        return dp[i] = mini;
         
    }
    
public:
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int a =  min_partitions(0,str.length(),str);   
        return a; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends