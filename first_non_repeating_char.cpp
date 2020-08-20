#include<iostream>
#include<string>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,i,fre[26]={0};
    string str;
    queue<char> q;
    
    cin>>t;
    //cout<<t;
    while(t--)
    {  
        for(i=0;i<26;i++)   fre[i]=0;
        q=queue<char>();
        cin>>n;  fflush(stdin);
        
        getline(cin,str);
        
        for(i=0;i<2*n;i+=2)
        {  
           fre[str[i]-'a']++;

           if(fre[str[i]-'a']==1)
             q.push(str[i]); 
        
           while((!q.empty()) && fre[q.front()-'a']>1)
              q.pop();
           
           if(q.empty())  cout<<"-1";
           else cout<<q.front();
           if(i != 2*n-1)  cout<<" ";
           
           
        }
        cout<<endl;
    }
    
	return 0;
}