#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,i,n,f_max,b_max,pro;
    cin>>t;

    while(t--)
    {
        cin>>n;     f_max=b_max=INT_MIN;
        vector <ll>arr(n);

        for(i=0;i<n;i++)
             cin>>arr[i];   
        
       
        pro=1; 
        for(i=0;i<n;i++)
        {   
           pro*=arr[i];
           f_max=max(f_max,pro);  
           if(arr[i]==0)
            pro=1;
        }
        f_max=max(f_max,pro);
        pro=1; 
        for(i=n-1;i>=0;i--)
        {   
           pro*=arr[i];
           b_max=max(b_max,pro);  
           if(arr[i]==0)
            pro=1;
                 
        }
        b_max=max(b_max,pro);
        cout<<max(f_max,b_max)<<"\n";
    }
    
    return 0;
}


/*

1
10
0 3 -5 -2 8 -7 -6 -2 -3 -9

*/