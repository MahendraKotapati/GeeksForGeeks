#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{

    ll t,n,i,maxi,num;
    cin>>t;
    while(t--)
    {
        cin>>n;   maxi=0;num=0;
        vector <ll>l(n),r(n),pre(100005,0);
        for(i=0;i<n;i++)
            cin>>l[i];
        
         for(i=0;i<n;i++)
            cin>>r[i];
        
        for(i=0;i<n;i++)
        {
            pre[l[i]]++;
            pre[r[i]+1]--;
        }

        for(i=1;i<=100000;i++)
        {
            pre[i]+=pre[i-1];
            if(pre[i]>maxi)
            {
                num=i;maxi=pre[i];
            }
        }
        cout<<num<<"\n";
    }
    return 0;
}