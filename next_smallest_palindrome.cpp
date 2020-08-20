/*correct solution refer  https://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/ */

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

vector <ll>arr;

void to_array(ll num)
{
    while(num)
        arr.pb(num%10),num/=10;
    reverse(arr.begin(),arr.end());
}

void copy_digits(vector<ll>&arr,ll len)
{   
    ll l,r;
    l = 0;  r=len-1;

    while(l<r)
        arr[r--]=arr[l++];
}


void add_one_to_middle(vector<ll>&arr,ll len)
{   
    ll l,r,mid;
    mid = len/2; 
    if(len%2==0) mid--;

    if(arr[mid]!=9)
        arr[mid]++;
    else   
    {
        arr[mid]=0;
        mid--;
        while(mid>=0 && arr[mid]==9) // propagating carry
            arr[mid--]=0;

        if(mid>=0)
            arr[mid]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,num,len,mid,l,r;
    cin>>t;
	
    while(t--)
    {
        cin>>num;
        to_array(num);
        len = arr.size(); mid = len/2;

        for(i=0;i<len;i++)
            if(arr[i]!=9)  break;
        
        if(i==len) // all nine's case
        {
            arr[0] = 1; 
            for(i=1;i<len;i++) 
                arr[i]=0; 
            arr.pb(1);   
        }
        else  
        {      
            i = mid; j = mid; // if len is odd
            if(len%2==0) i--;  // if len is even 

            while(i>=0 && j<len && arr[i]==arr[j])
                i--,j++;

            if(j==len)  // is already palindrome
            {
                add_one_to_middle(arr,len);    // add +1 to middle digits and propagate if any
                copy_digits(arr,len);          // copy left side to right side
            }
            else  
            {
                if(arr[i]>arr[j])    // when digit in left side greater than right side
                    copy_digits(arr,len);// copy left side to right side

                else
                {  
                    add_one_to_middle(arr,len);// add +1 to middle digits and propagate if any
                    copy_digits(arr,len);    // copy left digits to right
                }
            }     
        }

        for(i=0;i<arr.size();i++)
            cout<<arr[i];
        cout<<"\n";
    }
    
    return 0;
}