// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
    int start=0,i=0,curr_petrol=0;
    int flag=0; // signifies how many iterations we have done on array.

    while(1)
    {  
        curr_petrol = (curr_petrol+p[i].petrol) - p[i].distance;    
        i=(i+1)%n;
    
        if(i==start)   // we reached the tour 
        {
          if(curr_petrol>=0)  
            return start ;
          return -1;   // if in last step we dont have suffcient petrol.
        }
        
        if(curr_petrol<0)   // if not able to do tour re-starting tour
        {   
            start = i;
            curr_petrol=0;
        }

        if(i==0) // this is keep track of how many times we are iterating over array (to avoid infinte loop)
        { 
            if(flag)   // flag is true and once again i=0 means that we already done one iteration , we try to do one more 
                return -1;
            flag++;
        }
        
    }
    return start;
}
