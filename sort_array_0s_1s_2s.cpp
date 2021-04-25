#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,num,low,high,mid;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        low = mid = 0 ; high = n-1;

        while(mid<=high)
        {
            if(arr[mid]==0)
                swap(arr[mid],arr[low]),low++,mid++;
            else if(arr[mid]==1)
                mid++;
            else // arr[mid]==2  
                swap(arr[mid],arr[high]),high--;
        }
        
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        
    }
    
    return 0;
}

/*

2
5
0 2 1 2 0
3
0 1 0

*/