#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;
vector <ll>arr;

ll next_palindrome()
{   
    ll i,j,len = arr.size(),flag=0;
    i = len/2-1; j = ceil(len/2);

    while(j<len)
    {
        if(arr[i]>arr[j])
            flag=1,index=;
        i--;j++;
    }

    if(flag)
    {   


    }
    else 
    {

    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n;  
        while(n)
            arr.pb(n%10),n/=10;
            
        cout<<next_palindrome()<<"\n";
        arr.clear();
    }
    
    return 0;
}