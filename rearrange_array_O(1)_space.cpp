// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


    
// Function to rarrange the elements in O(1) extra space
// arr: input array
// n: size of array
void arrange(long long arr[], int n) {
    // Your code here
    
    int i;
    long long inf=10000000;
    
    // idea is to store two values in one position  arr[i] = arr[i]+ inf*(arr[i]%inf)
    // old number can be get by arr[i]%inf;
    // new number can be get by arr[i]/inf;
    
    for(i=0;i<n;i++)
    {
        arr[i] = (arr[arr[i]]%inf)*inf+arr[i];    
    }
    
    for(i=0;i<n;i++)
        arr[i] = arr[i]/inf;
}


// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        
        //calling arrange() function
        arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends