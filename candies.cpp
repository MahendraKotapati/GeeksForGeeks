/*  https://leetcode.com/problems/candy/  */

class Solution 
{
public:
    int candy(vector<int>& arr) 
    {  
        int n = arr.size(),i,s,min_candies=0;
        
        if(n<=1) return n;
        
        vector<int>suf(n); // suf largest continous decreasing subsequence start from [i]

        
        suf[n-1] = 1;
        
        for(i=n-2;i>=0;i--)
            if(arr[i]>arr[i+1])
                suf[i] = suf[i+1]+1;
            else 
                suf[i] = 1;
           
        s = suf[0];
        
        for(i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                min_candies+= s;
                s++;
                s = max(s,suf[i+1]);
            }
            else if(arr[i]>=arr[i+1])
            {
                min_candies+=s;
                s = suf[i+1];
            }       
        }
        
        min_candies+=s;  // for last element 
        
        return min_candies;     
        
    }
};

/*

ratings 1 2 3 4 10 8 7 6 5 
candies 1 2 3 4 5  4 3 2 1


1 2 3 4 10 8 7 
1 2 3 4 5  2 1 


1 2 3 2 4 5 6
1 2 3 1 2 3 4

34 12 34 9 8
2  1  2  


*/