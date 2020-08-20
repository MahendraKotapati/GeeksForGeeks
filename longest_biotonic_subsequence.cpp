#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,maxi;
    cin>>t;
	
    while(t--)
    {
        cin>>n;  maxi=0;
        vector <ll>arr(n),f(200+1,0),b(200+1,0);
        for(i=0;i<n;i++)
            cin>>arr[i];
        
        f[0]=1;
        for(i=1;i<n;i++)
        {   f[i]=1;
            for(j=0;j<i;j++)
                if(arr[i]>arr[j] && f[i]<f[j]+1)
                    f[i]=f[j]+1;
           
        }
        b[n-1]=1;
        for(i=n-2;i>=0;i--)
        {   b[i]=1;
            for(j=n-1;j>i;j--)
                if(arr[i]>arr[j] && b[i]<b[j]+1)
                    b[i]=b[j]+1;
            
        }
        
        for(i=0;i<n;i++)
            maxi=max(maxi,f[i]+b[i]-1);
        
        cout<<maxi<<"\n";
        
    }
    
    return 0;
}



// 2d array logic 

/*#include<bits/stdc++.h>
typedef long long ll;
#define ninf -2000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,maxi;
    cin>>t;
	
    while(t--)
    {
        cin>>n;  maxi=0;
        vector <ll>arr(n+1);
        ll f[200+1][2]={0},b[200+1][2]={0};


        for(i=0;i<n;i++)
            cin>>arr[i];
        
        f[0][0]=1;f[0][1]=arr[0];

        for(i=1;i<n;i++)
        {   
            f[i][0]=1;
            for(j=0;j<i;j++)
                if(arr[i]>arr[j] && f[i][0]<f[j][0]+1)
                    f[i][0]=f[j][0]+1,f[i][1]=arr[i]; 
                    

        }

        b[n-1][0]=1;b[n-1][1]=arr[n-1];

        for(i=n-2;i>=0;i--)
        {   
            b[i][0]=1;
            for(j=n-1;j>i;j--)
                if(arr[i]>arr[j] && b[i][0]<b[j][0]+1)
                    b[i][0]=b[j][0]+1, b[i][1]=arr[i];
            
        }

        for(i=1;i<n;i++)
            if(f[i][0]<f[i-1][0])
                f[i][0]=f[i-1][0],f[i][1]=f[i-1][1];
        
        for(i=n-2;i>=0;i--)
            if(b[i][0]<b[i+1][0])
                b[i][0]=b[i+1][0],b[i][1]=b[i+1][1];
         
        b[n][1]=ninf; b[n][0]=0;

        maxi=max(maxi,b[0][0]);  

        for(i=0;i<n;i++)
        {    
            if(f[i][1]>b[i+1][1]) 
                maxi=max(maxi,f[i][0]+b[i+1][0]); 
        }

        cout<<maxi<<"\n";
        
    }
    
    return 0;
}

*/