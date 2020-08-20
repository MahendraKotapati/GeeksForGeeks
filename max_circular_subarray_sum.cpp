/* wrong solution */

#include<bits/stdc++.h>
#define F first
#define S second
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n,curr_sum,max_sum,flag,s,start,end;
    cin>>t;
	
    while(t--)
    {
        cin>>n;   flag=0;

        vector <ll>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];  
        
        curr_sum=0;   max_sum = arr[0];  start=s=0;

        for(i=0;i<n;i=(i+1)%n)
        {   
            if(i==s && flag)
                break;

            curr_sum+=arr[i];

            if(curr_sum>max_sum)
                max_sum=curr_sum,end=i;
    

            if(curr_sum<0)
               start=s,s=(i+1)%n, curr_sum=0;
 
            if(i==n-1)
            {
                if(flag)
                    break;
                flag++;
            }
        }
        cout<<max_sum<<"\n";

    }
    
    return 0;
}

/*

3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1


*/