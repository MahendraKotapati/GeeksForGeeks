#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n)
{
    
    if(n==1)
        return 1;

    ll i,maxi=2;

    while(n%2==0)
        n/=2;

    for(i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
             maxi=max(maxi,i);
             n/=i;
        }
    }

    if(n>2)
         maxi=max(maxi,n);

    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        cout<<solve(n)<<"\n";

    }
    
    return 0;
}