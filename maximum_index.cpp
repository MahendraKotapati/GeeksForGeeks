#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n); 
        for(i=0;i<n;i++){
            cin>>arr[i];
            arr[i]=-arr[i];
        }
        
    }
    
    return 0;
}