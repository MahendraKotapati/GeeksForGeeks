#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,ans,c;
    cin>>t;
	
    while(t--)
    {
       cin>>n;  ans=c=0;
	   vector <ll>arr(n);
	   for(i=0;i<n;i++)
			cin>>arr[i];
	
	   sort(arr.begin(),arr.end(),greater<int>());

	   for(i=0;i<n;i++)
	   {
		   if((ans|arr[i])>ans)
		   		ans=ans|arr[i],c++;

	   }	
	   cout<<c<<"\n";

    }
    
    return 0;
}