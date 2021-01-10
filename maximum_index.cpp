#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,ans,low,mid,high;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n),Rmax(n),Lmin(n); 

        for(i=0;i<n;i++)
            cin>>arr[i];
        
        Rmax[n-1] = arr[n-1]; ans = 0;

        for(i=n-2;i>=0;i--)
            Rmax[i] = max(arr[i],Rmax[i+1]);
        
        Lmin[0] = arr[0];
        for(i=1;i<n;i++)
            Lmin[i] = min(arr[i],Lmin[i-1]);
        
        i = j = 0;

        while(i<n && j<n)
        {
            if(Lmin[i]<=Rmax[j])
            {
                ans = max(ans,j-i);
                j++;
            }
            else   
                i++;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}


/*
O(nlogn) approach

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,ans,low,mid,high;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n),max_suf(n); 

        for(i=0;i<n;i++)
            cin>>arr[i];
        
        max_suf[n-1] = arr[n-1]; ans = 0;
        // max suf is in incresing order from right

        for(i=n-2;i>=0;i--)
            max_suf[i] = max(arr[i],max_suf[i+1]);
        
        for(i=0;i<n;i++)
        {
            low = i+1; high = n-1;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(max_suf[mid]>=arr[i])
                { 
                    low = mid+1; ans = max(ans,mid-i);
                }    
                else   
                    high = mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
*/

/*

1
9
34 8 10 3 2 80 30 33 1

*/