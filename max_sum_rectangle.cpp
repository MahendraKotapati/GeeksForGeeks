
/*  
    https://www.youtube.com/watch?v=yCQN096CwWM 
    O(n) space approach   
*/

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll kadane(vector<ll>&arr,int n)
{
    int curr_sum,max_sum,i;
    curr_sum = 0; max_sum = arr[0];

    for(i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        max_sum = max(max_sum,curr_sum);
        if(curr_sum<0)
            curr_sum  = 0;
    }

    return max_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,n,m,max_sum;
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;   max_sum  = INT_MIN;

        vector<vector<ll>>arr(n,vector<ll>(m,0)),col_sum(n+1,vector<ll>(m,0));   
        // col_sum is 1 Indexed based
        vector<ll>ans(m);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>arr[i][j];
  
      
        for(i=1;i<=n;i++)
        {   
            for(k=0;k<m;k++)
                col_sum[i][k] = col_sum[i-1][k]+arr[i-1][k];

            for(j=0;j<i;j++)
            {
                for(k=0;k<m;k++)
                    ans[k]=col_sum[i][k]-col_sum[j][k];
                    
                max_sum = max(kadane(ans,m),max_sum);
            }
        }

        cout<<max_sum<<"\n";        
    }
    
    return 0;
}