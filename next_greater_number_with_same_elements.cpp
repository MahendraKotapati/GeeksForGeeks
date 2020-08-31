/*  https://www.geeksforgeeks.org/find-next-greater-number-set-digits/  */
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,num,n,min_index;
    cin>>t;
	
    while(t--)
    {   
        vector<ll>arr;
        cin>>num;   
        while(num>0)
            arr.pb(num%10),num/=10; 
        
        reverse(arr.begin(),arr.end());
        n = arr.size();

        for(i=n-2;i>=0;i--)
        {
            if(arr[i]>=arr[i+1])
                continue;
            break;
        }
        min_index = i;

        if(i<0) {   // if given number is in decresing order
            cout<<"not possible"<<"\n";
            continue;
        }

        // arr[min_index:n] is in decresing order

        for(i=n-1;i>=0;i--)   // finding number just greater than arr[min_index] position below it 
        {
            if(arr[min_index]<arr[i])
            {
                swap(arr[min_index],arr[i]);
                break;
            }    
        }
        reverse(arr.begin()+min_index+1,arr.end());  // dont need sort we can just reverse because it is in decresing order

        for(i=0;i<n;i++)
            cout<<arr[i];
        cout<<"\n";
    }
    
    return 0;
}