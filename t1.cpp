#include<bits/stdc++.h>
//#define FF first
#define S second
#define pb push_back
#define mod 1003
typedef long long ll;
using namespace std;

string str,key,temp;
ll n;
unordered_map <string,pair<ll,ll>>dp;


void paranthesize(ll l,ll r,ll &T,ll &F)
{   
    if(l==r)
    {
        T = (str[l]=='T');
        F = (str[l]=='F');
        return;
    }
    
    key = to_string(l)+"#"+to_string(r);
	cout<<"key is :"<<key<<"\n";
	

    if(dp.count(key))
    {   
        T = dp[key].first; F = dp[key].S;
        return;
    }

    ll i,leftT,leftF,rightT,rightF,ans;

    for(i=l+1;i<r;i+=2)
    {   
        leftT = leftF = rightT = rightF = 0;

		temp = to_string(l)+"#"+to_string(i-1);

		if(dp.count(temp)) 
			leftT = dp[temp].first,leftF = dp[temp].S;
		else   
			paranthesize(l,i-1,leftT,leftF);
		
		temp = to_string(i+1)+"#"+to_string(r);

		if(dp.count(temp))  
			rightT = dp[temp].first,rightF = dp[temp].S; 
		else   
			paranthesize(i+1,r,rightT,rightF);    
		
		if(str[i]=='&')
		{
			T = ( T + (leftT * rightT)%mod )%mod;
			F = ( (F + (leftT * rightF)%mod ) % mod + ( (leftF * rightT)%mod + (leftF * rightF)%mod )%mod ) % mod ;
		}
		else if(str[i]=='|')
		{
			T = ( (T + (leftT*rightT)%mod)%mod + ((leftT * rightF)%mod + (leftF * rightT)%mod)%mod )%mod ;
			F = ( F + (leftF * rightF)%mod ) % mod ;
		}
		else if(str[i]=='^')
		{
			T =  ( T + ( (leftT * rightF)%mod + (leftF * rightT)%mod ) % mod ) % mod ;
			F =  ( F + ( (leftT * rightT)%mod  + (leftF * rightF)%mod ) % mod ) %mod ;
		}
    }

	cout<<"key : "<<key<<" T: "<<T<<"\n";
    dp[key] = {T,F};
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,l,r,len;
    cin>>t;
	
    while(t--)
    {	
        cin>>n;
        cin>>str;  

        ll T=0,F=0;
        dp.clear();
        paranthesize(0,n-1,T,F);  

		for(auto i:dp) cout<<i.first<<i.second.first<<"\n";

        //cout<<dp[to_string(0)+"#"+to_string(n-1)].first<<"\n";
	}

	return 0;
}

/*

2
7
T|T&F^T
5
T^F|F


2
35
T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F
45
T&T|F|F^F^T^T^T&T^F^T&F|F^F^F&F&F|F|F^F^T|T&T


1
15
T|F^F&T|F^F^F^T
21
T|F^F&T|F^F^F^T|T&T^T
31
T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T

*/