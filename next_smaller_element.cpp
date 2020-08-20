#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    
    ll t,i,n,discount,sum;
    cin>>t;
    
    while(t--)
    {
        cin>>n;  discount=sum=0;
        vector <ll>arr(n);
        stack <ll>s;
        
        for(i=0;i<n;i++)
            cin>>arr[i],sum+=arr[i]; 
        
        s.push(arr[n-1]);
        
        for(i=n-2;i>=0;i--)
        {
            while(!s.empty() && arr[i]<s.top())
                s.pop();
            
            if(!s.empty())         
                discount+=s.top();  // adding next smaller element to discount ;
   
            s.push(arr[i]);
        }
        cout<<sum-discount<<"\n";
        
        
    }
    
    
    return 0;
}    
