#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll postfix_evaluation(string str)
{
    ll res,i,len=str.length(),a,b;
    char op;
    stack <ll>s;

    for(i=0;i<len;i++)
    {
        if(isdigit(str[i]))
            s.push(str[i]-'0');
        else   
        {
            b = s.top(); s.pop(); op = str[i]; a = s.top(); s.pop(); 
            
            if(op=='+')
                res = a+b;
            else if(op=='-')
                res = a-b;
            else if(op=='*')
                res = a*b;
            else if(op=='/')
                res = a/b;
            else if(op=='^')
                res = a^b;
            s.push(res);
        }
        
    }
    return s.top();
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i;
    string str;
    cin>>t;
	
    while(t--)
    {
        cin>>str;  
        cout<<postfix_evaluation(str)<<"\n"; 
    }
    
    return 0;
}