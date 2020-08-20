#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,n,i,shares,cost,profit;
    cin>>t;
	
    while(t--)
    {
        cin>>n;   shares=cost=profit=0;
        vector <ll>arr(n),suf_max(n);

        for(i=0;i<n;i++)
            cin>>arr[i];

        suf_max[n-1]=arr[n-1];
        

        for(i=n-2;i>=0;i--)
            suf_max[i]=max(suf_max[i+1],arr[i]);
        
        for(i=0;i<n;i++)
        {
            if(arr[i]<suf_max[i])
                shares++,cost+=arr[i];

            else if(arr[i]==suf_max[i])
            {
                profit+=shares*suf_max[i]-cost;
                shares=0;
                cost=0;
            }

        }
        cout<<profit<<"\n";

    }
    
    return 0;
}

/*

3
3
5 3 2
3
1 2 100
4
1 3 1 2

*/