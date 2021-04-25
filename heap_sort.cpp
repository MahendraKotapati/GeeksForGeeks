// refer https://www.programiz.com/dsa/heap-sort
// https://www.youtube.com/watch?v=HI97KDV23Ig build heap complexity 
// heap operations : https://afteracademy.com/blog/operations-on-heaps

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

void heapify(vector<ll>&arr,ll n,ll i)
{   
    ll largest=i,left=2*i+1,right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    
    swap(arr[i],arr[largest]);
    if(i!=largest)
        heapify(arr,n,largest);

}

void heap_sort(vector <ll>&arr,ll n)
{
    ll i;
    for(i=n/2-1;i>=0;i--)  // build heap 
        heapify(arr,n,i);
    
    for(i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);  // pop top element insert at end 
        heapify(arr,i,0);
    } 
     
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        heap_sort(arr,n);

        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}