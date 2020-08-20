#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

#define li long long int
using namespace std;

int main()
{

    li t,n,*arr,i,j,neg,*m,pro;
    cin>>t;
    while(t--)
    {
        cin>>n;  neg=0;pro=1;
        arr=(li*)malloc(n*sizeof(li));
        for(i=0;i<n;i++)
        {
            cin>>arr[i];  if(arr[i]<0)  neg++;
        }
        if(neg==0)     
        {
            m=min_element(arr,arr+n);
            cout<<*m<<endl;
        }
        else if(neg&1)
        {
            for(i=0;i<n;i++)  if(arr[i])  pro*=arr[i];
            cout<<pro<<endl;
        }
        else 
        {   sort(arr,arr+n);
            for(i=0;i<n;i++)
            {
                if(arr[i]>=0) break;
                pro*=arr[i];
            }
            pro/=arr[i-1];
            for(j=i;j<n;j++)  if(arr[i]) pro*=arr[j];
            cout<<pro<<endl;

        }
    
    }

  return 0;
}