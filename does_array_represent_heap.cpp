#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

bool check_heap_util(vector <ll>&arr,ll n,ll i)
{
    if(2*i+1<n && arr[i]<arr[2*i+1])
        return false;
    if(2*i+2<n && arr[i]<arr[2*i+2])
        return false;
    return true;

}

bool is_heap(vector <ll>&arr,ll n)
{
    ll i;
    for(i=n/2-1;i>=0;i--)
        if(!check_heap_util(arr,n,i)) return false;
    return true;
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
        cout<<is_heap(arr,n)<<"\n";
    }
    
    return 0;
}