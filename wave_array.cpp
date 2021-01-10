// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Function to convert given array to wave like array
// arr: input array
// n: size of array
void convertToWave(int *arr, int n) {
    
        int i;
        
        for(i=0;i<n-1;i++)
        {
            if( (i%2==0) && (arr[i]<arr[i+1]))
                swap(arr[i],arr[i+1]);
            
            if((i&1) && (arr[i]>arr[i+1]))
                swap(arr[i],arr[i+1]);
                
        }
    
    /*
    0     2    4
    \    /\    /\
     \  /  \  /  \
      \/    \/    \
       1     3     5

    */
    
}

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        int a[n]; //declare array of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        
        convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends