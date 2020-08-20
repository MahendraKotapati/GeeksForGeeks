#include<iostream>
#include<vector>
#include<cmath>
typedef unsigned long int li;
using namespace std;

li fact(li n)
{
    li f=1,i;
    for(i=1;i<=n;i++)  f*=i;  
    return f;
}

li ncr(li n,li r) 
{
    return fact(n)/(fact(n-r)*fact(r));  
}



int main()
{   

    li t,n,arr[20],i,sum,integer;
    double avg,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;  vector <li>arr(n);  sum=0;avg=0;
        for(i=0;i<n;i++)     
        {
            cin>>arr[i];  sum+=arr[i];   
        }
      /*  for(i=0;i<n;i++)  
        { 
            temp=(ncr(n-1,i)*sum)/(float)(i+1);  
            integer=temp*10000000; 
            avg+= (integer)/(float)(10000000);
        }
        */
        avg= (sum*(pow(2,n)-1) )/n;
        
        printf("%.6f",avg);
        
    }
    
    return 0;
}