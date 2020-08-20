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

    ll t,i,n,pre_end,min_start,idx;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <pair<ll,ll>>arr(n);
        
        for(i=0;i<n;i++)
            cin>>arr[i].F>>arr[i].S;
        
        sort(arr.begin(),arr.end(),cmp);

        pre_end = arr[0].S;
        min_start = arr[0].F;
        idx = 0;
       
        for(i=1;i<n;i++)
        {
            if(arr[i].F<=pre_end)
                pre_end = max(arr[i].S,pre_end);  // no need to update the min_start because arr[i].F>min_start

            else  
            {   
                arr[idx].F = min_start; arr[idx].S = pre_end;
                idx++;  
                pre_end = arr[i].S;
                min_start = arr[i].F; 
            }
        }

        arr[idx].F = min_start; arr[idx].S = pre_end;

        for(i=0;i<=idx;i++)
            cout<<arr[i].F<<" "<<arr[i].S<<" ";
        cout<<"\n";

    }
    
    return 0;
}


/*

*/


/*

1
42
11 68 1 1 4 25 59 59 51 65 6 46 22 28 52 92 12 43 17 37 3 5 23 54 75 83 16 17 72 96 3 27 37 39 6 13 36 100 14 95 3 12 28 34 62 65 6 12 18 69 38 45 28 58 24 60 20 42 72 79 15 36 31 43 4 7 1 43 7 49 3 6 11 30 13 51 2 2 30 49 13 24 2 55


*/