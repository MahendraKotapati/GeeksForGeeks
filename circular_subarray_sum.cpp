#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll kadane(vector <ll>arr,ll n)
{
    ll i,curr_sum=0,max_sum=arr[0];

    for(i=0;i<n;i++)
    {
        curr_sum+=arr[i];

        if(curr_sum>=max_sum)
            max_sum = curr_sum;

        if(curr_sum<0)
            curr_sum=0;
    }
    return max_sum;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,curr_sum,max_sum,total_sum,ans,min_subarray_sum;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];
 
        total_sum = 0; 
        ans = kadane(arr,n);

        if(ans<=0) {  // if all elements are negative 
            cout<<ans<<"\n"; continue;
        }

        for(i=0;i<n;i++)
        {
            total_sum+=arr[i];
            arr[i] = -arr[i];
        }

        min_subarray_sum = kadane(arr,n);
        ans = max(ans,total_sum+min_subarray_sum); // total_sum - min_subarray_sum(i.e max_subarry_sum after inversion)  gives circular_max_subarry_sum

        cout<<ans<<"\n";

    }
    
    return 0;
}