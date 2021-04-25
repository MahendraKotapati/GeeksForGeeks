/*  
    Time complexity : O(log(min(n1,n2)))

    TushorRoy's best explanation : https://www.youtube.com/watch?v=LPFhl65R7ww 
    https://github.com/mission-peace/interview/blob/master/src/com/interview/binarysearch/MedianOfTwoSortedArrayOfDifferentLength.java
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1,n2,lowX,highX,minX,minY,maxX,maxY,midX,midY;
        n1 = nums1.size(); n2 = nums2.size();
        
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        
        lowX = 0; highX = n1; // important

        /* 
            our assumption is nums1.size()<nums2.size()
            we apply binary search on smaller array
            both maxX,maxY on left side and min,minY is on right side

            left        right
            a1 a2 a3 | a4 a5
            b1 b2 b3 b4 | b5 b6 b7 b8

            we have to divide two arrays such that size(left)>=size(right)   (greater is needed in case of odd)
            a3 maxX ;  b4 maxY ; a4 minX ; b5 minY
        */
        while(lowX<=highX)
        {
            midX = (lowX+highX)/2;
            midY = (n1+n2+1)/2 - midX; // 
            // we take midX no.of elements from nums1 for left side     
            
            minX = (midX == n1) ? INT_MAX : nums1[midX];    // if we taken total nums1 to left side then there is no minX so  minX = INT_MAX
            maxX = (midX == 0) ? INT_MIN : nums1[midX-1];   // if we taken total nums1 to right side then there is no maxX = INT_MIN
            
            // similarly for larger(nums2) arrray
            minY = (midY == n2) ? INT_MAX : nums2[midY];  
            maxY = (midY == 0) ?  INT_MIN : nums2[midY-1];
            
            
            if(maxX<=minY && maxY<=minX) // if we break at correct position 
            {
                if((n1+n2)&1)   
                    return max(maxX,maxY);
                else 
                    return  (max(maxX,maxY)+min(minX,minY))/2.0; 
                /*  
                    to understand in case of even
                    https://youtu.be/MHNTl_NvOj0?t=137
                */
            }
            else if(maxX>minY)   // if we too much on right side move to left side
                highX =  midX-1;
            else         // if we too much on left side move to right side
                lowX = midX+1;
        }
        return 0;
    }
    
    
    /*
    
      21 23 | 25 30
      10 14 17 | 20 26 
      
      
      10 14 17 20 21 23 25 26 30
      
      // 5 th element is median
    
    */
};