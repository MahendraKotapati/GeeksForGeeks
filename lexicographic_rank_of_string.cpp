#include<bits/stdc++.h>
#define F first
#define S second
#define mod 1000003
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,len,fact[20],cnt[26],rank;
    string str;

    fact[0]=1;  
    for(i=1;i<=20;i++)
        fact[i]= (i*fact[i-1]) % mod;

    cin>>t;
	
    while(t--)
    {   
        memset(cnt,0,sizeof(cnt));   rank = 0;
        cin>>str; 
        len = str.length();

        for(i=0;i<len;i++)
            for(j=str[i]-'a';j<26;j++)   
                cnt[j]++;
        

        for(i=0;i<len;i++)
        {
            rank = rank + ( (cnt[str[i]-'a']-1)*fact[len-i-1])%mod;
            for(j=str[i]-'a';j<26;j++)   
                cnt[j]--;
        }
        cout<<rank+1<<"\n";
    }
    
    return 0;
}