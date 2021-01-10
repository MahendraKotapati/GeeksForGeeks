#include<bits/stdc++.h>
//#define F first
//#define S second
#define pb push_back
#define mod 1003
typedef long long ll;
using namespace std;

string str,key,temp;
ll n;
//unordered_map <string,pair<ll,ll>>dp;


/*
  // this top down (memoization) approach is not working there is some bug
  
void paranthesize(ll l,ll r,ll &ways_t,ll &ways_f)
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
*/

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,l,r,len;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        cin>>str;  

        int T[n+1][n+1],F[n+1][n+1];
        memset(T,0,sizeof(T));   // T[i][j] stores no of ways in which str[i:j] is true
        memset(F,0,sizeof(F));   // F[i][j] stores no of ways in which str[i:j] is false

        for(i=0;i<n;i+=2)
        {
            T[i][i] = (str[i]=='T');
            F[i][i] = (str[i]=='F');
        }

        /*  basic length of expression is 3   */

        for(len=3;len<=n;len+=2)
        {
            for(i=0;i+len-1<n;i+=2)  // i+=2 because expression length is always odd (so end index is always even)
            {
               l = i; r = i+len-1; 

               for(j=l+1;j<r;j+=2) // break at each operator and calculate T[][], F[][] , j+=2 because operator appears in alternative positions only
               {
                    if(str[j]=='&') {
                        T[l][r] = ( T[l][r] + (T[l][j-1]*T[j+1][r]) % mod )% mod ;
                        F[l][r] = ( (F[l][r] + (T[l][j-1]*F[j+1][r])%mod )%mod + ( (F[l][j-1]*T[j+1][r])%mod + (F[l][j-1]*F[j+1][r])%mod )%mod ) % mod ;
                    }
                    else if(str[j]=='|') {
                        T[l][r] = ( ( T[l][r] + (T[l][j-1]*T[j+1][r])%mod )%mod + ( (T[l][j-1]*F[j+1][r])%mod + (F[l][j-1]*T[j+1][r])%mod )%mod ) % mod;
                        F[l][r] = ( F[l][r] + (F[l][j-1]*F[j+1][r])%mod  )%mod;
                    }
                    else if(str[j]=='^') {
                        T[l][r] = ( T[l][r] + ( (T[l][j-1]*F[j+1][r])%mod + (F[l][j-1]*T[j+1][r])%mod )%mod ) % mod;
                        F[l][r] = ( F[l][r] + ( (T[l][j-1]*T[j+1][r])%mod + (F[l][j-1]*F[j+1][r])%mod )%mod ) % mod;   
                    }
               }
            }
        }
        cout<<T[0][n-1]<<"\n";
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