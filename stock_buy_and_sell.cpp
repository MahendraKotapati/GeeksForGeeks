#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,max_idx,min_idx,flag;
    cin>>t;
	
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);

        for(i=0;i<n;i++)
            cin>>arr[i];
        
        max_idx = 0 ; min_idx = 0; flag = 0;

        for(i=1;i<n;i++)
        {   

            if(arr[i]>arr[max_idx])
                max_idx = i;
            else   
            {   
                if(min_idx!=max_idx)
                {
                    cout<<"("<<min_idx<<" "<<max_idx<<") ";
                    flag=1;
                }
                min_idx = max_idx = i;
            }          
        }

        if(min_idx!=max_idx)
        {
            cout<<"("<<min_idx<<" "<<max_idx<<") ";
            flag=1;
        }

        if(!flag)
            cout<<"No Profit";
        cout<<"\n";

    }
    
    return 0;
}

