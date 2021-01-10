#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,k,n;
	cin>>t;	
	
	while(t--)
	{
	    cin>>n>>k;
	    vector<int>arr(n);
	    deque<int>dq;
	    
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	    
	    
	    for(i=0;i<k;i++)
        {
            // keeping only uselful elements , we are getting higher number arr[i] , 
            // so we don't need  all smaller elements before that, because , if any time we need max . 
            // potential candidate can be arr[i] not the smalller elements we removed, so we can safely remove smaller elements
            while( !dq.empty() && arr[i]>=arr[dq.back()])  
                dq.pop_back();

	        dq.push_back(i);
        }
	   
	    cout<<arr[dq.front()]<<" ";
	    
	    for(i=k;i<n;i++)
	    {   
            while( !dq.empty() && dq.front()<=i-k)  // removing elements out of current window , here we don't need while , If is enough
                dq.pop_front();


            // keeping only uselful elements , we are getting higher number arr[i] , 
            // so we don't need  all smaller elements before that, because , if any time we need max . 
            // potential candidate can be arr[i] not the smalller elements we removed, so we can safely remove smaller elements

            while( !dq.empty() && arr[i]>=arr[dq.back()] )  
                dq.pop_back();

	        dq.push_back(i);
            cout<<arr[dq.front()]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}


/*

1
9 3
1 2 3 1 4 5 2 3 6


1
10 4
8 5 10 7 9 4 15 12 90 13



min in stack O(1)

x<min
x-min<0
2*x-min<x

let y = 2*x-min , y is pushed into stack,now x is new_min

now , to get old_min ( min ) 
= 2*new_min - y
= 2*x - (2*x-min)
= min
*/