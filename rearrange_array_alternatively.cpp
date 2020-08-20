/* question : https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0  */

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,curr,MAX;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];  
        
        MAX = arr[n-1]+1;

        /*  idea is to store two values in one position  arr[i] = arr[i]+ MAX*(arr[idx]%MAX)          

            to know old value  arr[i]=arr[i]%MAX;
            to know new value  arr[i]=arr[i]/MAX;
        */
        j=n-1;
        for(i=n-1;i>=0;i-=2)  //arranging maximum numbers
        {   
            arr[i]+= MAX*(arr[j]%MAX);
            j--;
        }

        j=0;
        for(i=n-2;i>=0;i-=2) // arranging minimum numbers 
        {       
            arr[i] += MAX*(arr[j]%MAX);
            j++;
        }  

        for(i=n-1;i>=0;i--)
        {
            arr[i]=arr[i]/MAX;cout<<arr[i]<<" ";
        }     
        cout<<"\n";
    }
    
    return 0;
}