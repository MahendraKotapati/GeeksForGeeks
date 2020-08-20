#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll pre(char ch)
{
    switch(ch)
    {
        case '^': return 3;
        case '/': return 2;
        case '*': return 2;
        case '-': return 1;
        case '+': return 1;
        case '(': return -1;   /* this is to handle case where top is '(' and str[i] is any other operator (+,-.*,/);
                                        |   |
                                        |   |
                                        | ( |
                                        |___|
                                */
    }
}

string infix_to_postfix(string str)
{

    string post_fix="";
    ll len = str.length(),i;
    stack <char>s;

    for(i=0;i<len;i++)
    {   
        //cout<<str[i]<<" ";
        if(isalpha(str[i]))
            post_fix.pb(str[i]);
        else 
        {
            if(str[i]=='(')
                s.push(str[i]);

            else if(str[i]==')')    // if str[i] is ')' means there is already ')' in stack so we pop till ')'
            {
                while(!s.empty() && s.top()!='(')
                    post_fix.pb(s.top()),s.pop();   

                s.pop();  // this is to pop left bracket '('
            }
            else if(s.empty())   // if stack is empty push str[i]
                s.push(str[i]);

            else if(pre(str[i])>pre(s.top()))  // if precedence of top of stack<str[i] we can push str[i] into stack
                s.push(str[i]);

            else
            { 
                while(!s.empty() && s.top()!='(' &&  pre(str[i])<=pre(s.top()) ) // poping all higher precedence operators 
                    post_fix.pb(s.top()),s.pop(); 

                s.push(str[i]);  // pushing str[i] into stack
            }
                
        }
         
    }

    while(!s.empty())
        post_fix.pb(s.top()),s.pop(); 

    return post_fix;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t;
    string str;
    cin>>t;
	
    while(t--)
    {
        cin>>str;
        cout<<infix_to_postfix(str)<<"\n";
    }
    
    return 0;
}