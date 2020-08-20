/* 


refer GFG    




*/

#include<bits/stdc++.h>   // it is wrong
typedef long int li;
using namespace std;

li maximum(li a,li b,li c)
{
    return max(max(a,b),c);
}

li max_profit(li arr[],li n)
{
    li inc,exc,i,ans=0;
    inc=exc=0;

    for(i=0;i<n;i++)
    {
        inc+=arr[i];  
        ans=maximum(ans,inc,exc);  
        swap(inc,exc);  
    }

    return ans;
}

int main()
{
    li t,n,arr[10000],i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
             cin>>arr[i];
        cout<<max_profit(arr,n)<<"\n";

    }

    return 0;
}
