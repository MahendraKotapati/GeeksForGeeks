#include<bits/stdc++.h>

using namespace std;

int main()
{
 
    int t,n,m,i,j,max_len;
    bool flag;
    cin>>t;
    
    
    while(t--)
    {
        cin>>n; j = 0;  max_len = 0; flag = false;
        vector<int>arr(n);

        for(i=0;i<n;i++)
            cin>>arr[i];
        
        for(i=0;i<n;i++)
        {
            if(arr[i]==1|| !flag)
                continue;
           
            while(i<n && arr[i]==0) 
                i++;
            
            max_len = max(max_len,i-j);
            
            while(j<i && arr[j]==1)
                j++;
            while(j<i && arr[j]==0)
                j++;
            
            flag = false;
        }
        cout<<max_len<<"\n";
        
    }
	return 0;
}