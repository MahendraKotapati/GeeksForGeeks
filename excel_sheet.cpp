#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n;
    string str;
    cin>>t;
	
    while(t--)
    {
       cin>>n;

       while(n)
       {    
            /*if(n%26)
                str =  str+ (char)(n%26+'A'-1);
            else  
                str =  str+"Z";
           n/=26;
           */
            n--;
            str =  str+ (char)(n%26+'A');
            n/=26;
       }
       reverse(str.begin(),str.end());
       cout<<str<<"\n";
    }
    
    return 0;
}