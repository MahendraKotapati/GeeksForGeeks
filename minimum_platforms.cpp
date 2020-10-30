#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

bool cmp(pair<ll,ll>&p1,pair<ll,ll>&p2)
{
    return p1.F<p2.F;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,j,curr_platforms,max_platforms;
    cin>>t;
	
    while(t--)
    {
        cin>>n;   curr_platforms = 1; max_platforms = 0;

        vector<ll>arr(n),dep(n);

        for(i=0;i<n;i++)
            cin>>arr[i];
        
        for(i=0;i<n;i++)
            cin>>dep[i];
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());

        // we need only count of trains not which train, so we can sort arr,dep separately

        i=1; j=0;

        while(i<n && j<n)
        {
            if(arr[i]<=dep[j])    // next train arrival is before last train departure , we need one more platform
                curr_platforms++,i++;

            else if(arr[i]>dep[j])  //  if last train departureed, before next train arrival. we are we have one more free plaform
                curr_platforms--,j++;
            
            max_platforms = max(max_platforms,curr_platforms);
        }

        cout<<max_platforms<<"\n";
        
    }
    
    return 0;
}