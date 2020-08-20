#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{

    ll t,n,i,fre,flag,ans;
    unordered_map <ll,ll>mp;
    cin>>t;
   while(t--)
   { 
    cin>>n;  flag=0;
    vector <ll>arr(n);

    for(i=0;i<n;i++)
    {
         cin>>arr[i];
         mp[arr[i]]++;
    }
    fre=n/2;
    //if(n&1)  fre++;
    ans=-1;

    for(auto itr:mp)
    {
        if(fre<itr.second)
        {   
             ans=itr.second;
             break;
        }
    }
    cout<<ans<<"\n";
    mp.clear(); 

   }
    return 0;
}