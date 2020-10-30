#include<iostream>
#include<stdlib.h>
#include<algorithm>
#define li long int
using namespace std;

int main()
{

    li t,n,*arr,i,j,sum,low,high;
    cin>>t;
    while(t--)
    {
        cin>>n;   low=0;high=-1;
        arr=(li*)malloc(n*sizeof(li)); 
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        for(i=low+1;i<n;)
        {
            if(arr[low]<arr[i])
        } 
    }

    return 0;
}