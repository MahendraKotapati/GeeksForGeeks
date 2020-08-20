#include<iostream>
#include<stack>
using namespace std;


int main()
{
      stack<int> s;
      int t,n,k,arr[100],i,j,flag;
      cin>>t;
      
      while(t--)
      {
          cin>>n;s=stack<int>();
          
          for(i=0;i<n;i++)  cin>>arr[i];
          cin>>k;flag=0;
          
          for(i=0;i<n;i++)
          {
              if(!s.empty())
              {
                 while( (!s.empty()) && (s.top()<arr[i]) )  
                 {   
                     if(k>0) { s.pop();  k--; }
                     else  { flag=1; break;     }
                 }
              }
               
               if(flag)  break;
               else s.push(arr[i]);
          }
           
           for(j=0;!s.empty();j++) { 
               arr[j]=s.top();  s.pop();    
               
           }
           
            for(int k=j-1;k>=0;k--)  
            {
                  cout<<arr[k]; cout<<" ";
            }
        
           for(j=i;j<n;j++)  
            {
                  cout<<arr[j];   if(j) cout<<" ";
            }

              cout<<endl;
            
      }
     
   
 
    
	return 0;
}