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
    cin>>t;
	
    while(t--)
    {
        cin>>n;

        vector<ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        stack<ll>s;

        for(i=0;i<n;i++)
        {
            if(s.empty()||arr[s.top()]>arr[i])
            {    
                if(s.empty())
                    cout<<i+1<<" ";
                else   
                    cout<<i-s.top()<<" ";
            }
            else  
            {   
                while(!s.empty() && arr[i]>=arr[s.top()])
                    s.pop();
                
                if(s.empty())
                    cout<<i+1<<" ";
                else   
                    cout<<i-s.top()<<" ";
                
            }
            s.push(i);
        }   

        cout<<"\n";

    }
    
    return 0;
}

/*

1
7
100 80 60 70 60 75 85
1   1  1  2  1  4  6

if arr[i]<top 
    insert arr[i] into v 

*/
