#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll t,i,j,e,temp,n;  
    cin>>t;
	
    while(t--)
    {
        cin>>n;  
        vector <ll>arr(n+3,0);

        for(i=1;i<=n;i++)
        {
            cin>>e;  if(e<=0||e>n) e=0;
            arr[i]=e;
        }

        i=1;
        while(i<=n)
        {
            if(arr[i]<=0){   
                i++;continue;
            }

            if(i==arr[i])
                arr[i]=-i;

            else {    
                temp=arr[arr[i]];
                arr[arr[i]]=-arr[i];
                if(temp>=0)
                    arr[i]=temp;
                else   
                    arr[i]=0;
              
            }
        }
       
        for(i=1;i<=n;i++)
          if(arr[i]==0)
            break;
        
        cout<<i<<"\n";
    }
    return 0;
}

/*

2
5
1 2 3 4 5
5
0 -10 1 3 -20

*/