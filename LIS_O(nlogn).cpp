/*  https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming */

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll binarySearch(ll inc[],ll len,vector <ll>&arr,ll n,ll key)
{
    ll low = 0,high = len-1,mid,ans=0,i;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[inc[mid]]==key)
            return mid;
        else if(arr[inc[mid]]<key)
            low = mid+1;
        else if(arr[inc[mid]]>key)
            high = mid-1,ans = mid;
    }
    return ans;
}

ll LIS(vector <ll>&arr,ll n)
{
    ll len,i,inc[n+1],par[n+1],index;  // inc[]  stores incresing order elements indexes 
 
    memset(par,0,sizeof(par));

    par[0] = inc[0] = 0;  len=1;

    for(i=1;i<n;i++)
    {   
        if(arr[inc[0]]>arr[i])
            inc[0] = i,par[i]=i;  // this is the starting element of LIS 

        else if(arr[inc[len-1]]<arr[i])   
            par[i] = inc[len-1] , inc[len++] = i;  // just adding newElement to LIS 
        else  
        {   
            index = binarySearch(inc,len,arr,n,arr[i]);  // finding position where newElement is to place (position of element just greater > arr[i] )
            par[i] = inc[index-1];
            inc[index] = i;            
        }
    }
    
    i=inc[len-1];
    stack <ll>s;
    while(par[i]!=i)  // generating LIS 
    {
        s.push(arr[i]);
        i=par[i];
    }
    s.push(arr[i]);

    while(!s.empty())  {  // printing LIS 
        cout<<s.top()<<" "; s.pop(); 
    }
    return len;
}


 

int main()
{
    
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll t,i,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);

        for(i=0;i<n;i++)  cin>>arr[i];
        cout<<LIS(arr,n)<<"\n";
    }
    
    return 0;
}