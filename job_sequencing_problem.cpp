#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

bool cmp(pair<ll,ll>&p1,pair<ll,ll>&p2)
{
    return p1.S>p2.S;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,temp,jobs_count,_time,profit,j;
    cin>>t;
	
    while(t--)
    {
        cin>>n;   jobs_count = 0; _time = 0; profit = 0;
        vector<pair<ll,ll>>arr(n);
        vector<bool>slot(n+1,false);

        for(i=0;i<n;i++)
            cin>>temp>>arr[i].F>>arr[i].S;  // deadline,profit

        sort(arr.begin(),arr.end(),cmp); // sort jobs in decresing order of profit
        
        for(i=0;i<n;i++)
        {   
            for(j=min(arr[i].F,n);j>0;j--)   // for ith job search for slot, from ith job deadline
            {   
                // j=min(arr[i].F,n) is taken because we have assumed n it the max_deadline
                if(!slot[j-1])   // if slot is not filled 
                {
                    jobs_count++;
                    slot[j-1]=true;  // slot is now filled
                    profit+=arr[i].S;
                    break;
                }
            }
        }
        cout<<jobs_count<<" "<<profit<<"\n";
    }
    
    return 0;
}

/*

2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

*/