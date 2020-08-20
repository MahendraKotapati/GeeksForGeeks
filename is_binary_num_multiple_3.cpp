#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

bool prime(ll n)
{
    if(n<=2)
        return false;
    
    for(ll i=2;i<n;i++)
        if(n%i==0)
            return false;
    
    return true;

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,len,pos,ones;
    string str;
    cin>>t;
	
    while(t--)
    {
        cin>>str;  ones = pos = 0;
        len = str.length();

        for(i=len-1;i>=0;i--)
        {
            ones+=str[i]-'0';
            pos++;
        }
        if( (ones%3==0) || prime(ones))
            cout<<"1"<<"\n";
        else  
            cout<<"0"<<"\n";

    }
    
    return 0;
}