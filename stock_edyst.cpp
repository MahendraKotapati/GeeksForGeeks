#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t=1,i,n,max_so_far,profit,share_cost,p,q,flag;
    //cin>>t;
	
    while(t--)
    {
        cin>>n;  profit=0;  flag=0;

        vector <ll> arr(n),suf_max(n);

        for(i=0;i<n;i++)
            cin>>arr[i];

        share_cost=max_so_far=arr[0];
        p=q=0;

        for(i=1;i<n;i++)
        {
            if(arr[i]<max_so_far)
            {
                if(p!=q) 
                    cout<<p<<" "<<q<<"\n",flag=1;          

                share_cost=max_so_far=arr[i];
                p=i;q=i;
                
            }
            else  {    
                max_so_far=arr[i];   q=i;
            }

        }
        if(max_so_far>share_cost)
           cout<<p<<" "<<n-1<<"\n",flag=1;

        if(!flag)
            cout<<"Can't make a profit!";-+
        

    }
    
    return 0;
}