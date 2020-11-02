/* https://leetcode.com/problems/find-k-closest-elements/  */

class Solution {
     
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     
        int n = arr.size(),idx,i,j,temp_k=k;
         
        if(n==0)
            return vector<int>();
        
         
        idx = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
         
        i = idx-1, j = idx;

        while(i>=0 && j<n && k>0)
            if(abs(arr[i]-x)<=abs(arr[j]-x))
                 i--,k--;
            else  
                 j++,k--;

        
        while(i>=0 && k>0)
            i--,k--;


        while(j<n && k>0)
            j++,k--;   
        
        
        return vector<int>(arr.begin()+i+1,arr.begin()+i+1+temp_k);
     
    }
};