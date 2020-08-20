#include<bits/stdc++.h>
typedef long int  ll;
using namespace std;

ll ans[10000000];

int main()
{

    ll t,i,n,top_ele;
    stack <ll>s;
    cin>>t;
    while(t--)
    {   
        cin>>n;
        vector <ll>arr(n); 
        for(i=0;i<n;i++)
            cin>>arr[i];  

        
       for(i=0;i<=1000000;i++) ans[i]=-1;
        s.push(arr[n-1]);

        for(i=n-2;i>=0;i--)
        {   
            
            while(!s.empty() && arr[i]>=s.top())    
                s.pop();

            if(!s.empty())
              ans[i]=s.top(); 
                
            s.push(arr[i]);   
                 
        }

        for(i=0;i<n;i++)  cout<<ans[i]<<" ";

        cout<<"\n";
        s=stack<ll>();
    }

    return 0;
}