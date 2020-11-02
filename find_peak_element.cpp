/* https://www.youtube.com/watch?v=a7D77DdhlFc  */

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        int low=0,high=n-1,mid;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            if( (mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid]>arr[mid+1]) )  // if mid is peak return 
                return mid;
            if(mid+1<n && arr[mid]<arr[mid+1])  
            // if arr[mid]<arr[mid+1] peak can be found in right side 
            // case i) if all right side element in incresin order than last element is peak
            // case ii) if all right side elements in decresing order than arr[mid+1] is peak
                low = mid+1;
            else    // peak found in left side 
                high = mid-1;
        }
        
        return 0;
    }
};





class Solution {
public:
    int findPeakElementIndex(vector<int>& nums) {
        
        int low=0,high=nums.size()-1,mid;
        
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]<nums[mid+1])
                low = mid+1;
            else 
                high = mid;
        }
        
        return high;  // or return low;
    }
};