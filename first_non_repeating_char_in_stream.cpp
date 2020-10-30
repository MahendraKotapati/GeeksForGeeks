#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll i,j,n,t;
    char ch;
    cin>>t;

    while(t--)
    {
        cin>>n;
        queue<char>q;
        unordered_map <char,ll>mp;

        for(i=0;i<n;i++)
        {
            cin>>ch;
            q.push(ch);
            mp[ch]++;

            while(!q.empty() && mp[q.front()]>1)
                q.pop();

            if(q.empty())
                cout<<"-1"<<" ";
            else
                cout<<q.front()<<" ";
        }

    }

    return 0;
}