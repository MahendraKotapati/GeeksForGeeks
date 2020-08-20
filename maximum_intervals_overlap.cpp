#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

bool cmp(pair<ll,ll>&p1,pair<ll,ll>&p2)
{   
    if(p1.S<p2.S)
        return true;
    else if(p1.S==p2.S)
        return (p1.F<p2.F);

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,s,e,curr_max_time,c,maxi,idx,_time=0;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <pair<ll,ll>>arr(n);
        map <ll,ll>mp;

        for(i=0;i<n;i++)
            cin>>arr[i].F;
        
        for(i=0;i<n;i++)
            cin>>arr[i].S;

        sort(arr.begin(),arr.end(),cmp);

        //for(auto itr:arr) 
        //    cout<<itr.F<<" "<<itr.S<<"\n";

        idx= 0;  c = 1; maxi = 0;

        curr_max_time = arr[idx].S;
        mp[arr[idx].F]++;

        for(i=1;i<n && idx<n-1 ; i++)
        {
            if(arr[i].F<=curr_max_time)
            {
                c++;
                mp[arr[i].F]++;
            }   
            else  
            {   
                if(c>maxi)
                    maxi = c,_time = mp.rbegin()->F;
                else if(c==maxi)
                    _time = min(mp.rbegin()->F,_time);

                idx++;
                (i==idx)? c=1 : c--;

                mp[arr[idx-1].F]--;

                if(mp[arr[idx-1].F]==0)
                    mp.erase(arr[idx-1].F);

                curr_max_time = arr[idx].S;
                //cout<<"curr:"<<curr_max_time<<" ";
                i--;

            }

            if(c>maxi)
                maxi = c,_time = mp.rbegin()->F;
        }

        cout<<maxi<<" "<<_time<<"\n"; 
    }
    
    return 0;
}


/*

2
5
1 2 10 5 5
4 5 12 9 12
7
13 28 29 14 40 17 3 
107 95 111 105 70 127 74 


*/