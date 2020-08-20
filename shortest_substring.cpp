#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;


ll solve(string str)
{   
        ll i,len,c=0,uniq,j,min_len,min_index,start,glob_min;
        unordered_map <char,ll>mp,f;
         len=str.length();
         for(i=0;i<len;i++)
         {
            mp[str[i]]=i;
         }
         uniq=mp.size();
         mp.clear();

         for(i=0;i<len;i++)
         {
            if(mp.find(str[i])==mp.end())
                c++;
            mp[str[i]]=i;
             if(c==uniq)
                break;
         }
         
        min_index=INT_MAX;
        for(auto itr:mp)
        {
            min_index=min(min_index,itr.S);  
        }  
        glob_min=i+1-min_index; 
        start=min_index;

        for(j=i+1;j<len;j++)
        { 
           if(str[start]==str[j])
           {
                mp.erase(str[start]);  
                mp[str[j]]=j;
                min_index=INT_MAX;
                for(auto itr:mp)
                {
                   min_index=min(min_index,itr.S);  
                }
                min_len=j+1-min_index;
                glob_min=min(glob_min,min_len);
                start=min_index;
           }
           else  
             mp[str[j]]=j;
               
        }
       return glob_min;
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
         cout<<solve(str)<<"\n";
    }
    
    return 0;
}