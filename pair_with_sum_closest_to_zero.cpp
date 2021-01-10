/*  https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1/  */
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            int i,j,l,r;
            i = 0; j = n-1;
            l = r = INT_MAX;
            
            sort(arr,arr+n);
            
            while(i<j)
            {
                if(abs(l)>abs(arr[i]+arr[j]))
                    l = arr[i]+arr[j];
                else if(abs(l)==abs(arr[i]+arr[j]))
                    l = max(l,arr[i]+arr[j]);
                    
                if(arr[i]+arr[j]==0)
                    return 0;
                else if(arr[i]+arr[j]<0)
                    i++;
                else 
                     j--; 
            }
            return l;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends