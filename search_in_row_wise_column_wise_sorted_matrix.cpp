/*  https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/  */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	     int i=0,j=M-1;
         // start from top right corner 
	     
	     while(i<N && j>=0)
	     {
	            if(mat[i][j]==X)
	                return 1;
	                
	           if(mat[i][j]<X)
	                i++;
	           else 
	                j--;
	     }
	     
	     return 0;
	}
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  // } Driver Code Ends