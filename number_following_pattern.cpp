/* https://www.includehelp.com/icp/number-following-the-pattern.aspx */

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{

    ll t,n,len,i;
    string str,ans;
    cin>>t;

    while(t--)
    {
        cin>>str; 
        len=str.length();
        stack<ll>s;

        for(i=0;i<=len;i++)
        {   
            s.push(i+1);  // for D we need ouput in decresing order so , we use stack
            if(i==len || str[i]=='I')
                while(!s.empty())
                    cout<<s.top(),s.pop();
        }
        cout<<"\n";
    }

    return 0;
}