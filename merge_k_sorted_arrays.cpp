#include<bits/stdc++.h>
typedef long long ll;
#define F first
#define S second
#define pll pair <ll,ll>
#define pb push_back
using namespace std;

ll arr[105][105];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,curr;
    cin>>t;
	
    while(t--)
    {   
        cin>>k;
        vector <ll>p(k,0),ans;  // p[] stores pointer of i th array value 
        priority_queue <pll,vector<pll>,greater<pll>>pq;  // for min heap stores {Element,array_no }
        for(i=0;i<k;i++)
            for(j=0;j<k;j++)
                cin>>arr[i][j];
        
        for(i=0;i<k;i++)
            pq.push({arr[i][0],i});   // push all arrays first elements first value and array no 
                                      // pq.push({ arr[array_no][pointer_value_of_array],array_no })
        

        while(!pq.empty())  
        {   
            auto curr = pq.top();
            ans.pb(curr.F);pq.pop();

            p[curr.S]++;  // increment pointer value of curr.S (currently removed element) 

            if(p[curr.S]<k) // if currently removed element array has till contain elements insert next element 
                pq.push({arr[curr.S][p[curr.S]],curr.S});
        }

        for(i=0;i<k*k;i++)
            cout<<ans[i]<<" ";
    }
    
    return 0;
}