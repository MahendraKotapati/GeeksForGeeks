#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll n,m,arr[1003][1003];



/* 

 -> inorder to find max area rectangle we take each and every bar and calculate the area with it ,
 -> to calculate area with curr_bar we need its left smallest bar (left_bar) and right smallest bar (right bar) because till that the curr_bar can expand,then 
            curr_area = curr_bar*( right- (left+1) ) ;

            left+1 in curr_area because curr_bar can expand just before the left index . 

 -> while implementation , we stack to catch left bar we push till  arr[s.top()]<=arr[i]   (meaning that we haven't encountered right bar)
    if(arr[s.top()]>arr[i])    (we encountered right bar)

*/


ll max_area_rectangle(ll height[])  // max rectangle in histogram problem
{
    ll max_area=0,curr_area,i,curr_bar;
    stack <ll>s;

    for(i=0;i<m;)
    {
        if(s.empty() || height[s.top()]<=height[i])
            s.push(i++);
            
        else   
        {
            curr_bar = s.top(); s.pop();

            if(s.empty())
                curr_area =  (i)*height[curr_bar];
            else 
                curr_area =  (i-1-s.top())*height[curr_bar];
            max_area = max(max_area,curr_area);
        }
    } 

    while(!s.empty())
    {
       curr_bar = s.top(); s.pop();

        if(s.empty())
            curr_area =  (i)*height[curr_bar];
        else 
            curr_area =  (i-1-s.top())*height[curr_bar];
        max_area = max(max_area,curr_area);
    }

    return max_area;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,max_area,height[1003];
    cin>>t;
	
    while(t--)
    {
        cin>>n>>m;  max_area = 0;
        memset(height,0,sizeof(height));   // for every row we maintaing heights of pillars 
            
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>arr[i][j];
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)   // calculating pillars length for every row 
                if(arr[i][j])
                    height[j]+=1;
                else   
                    height[j]=0;

            max_area = max(max_area,max_area_rectangle(height));     // calulating max rectange as current row as base 
        }
        cout<<max_area<<"\n";
    }
    
    return 0;
}

/*

1
2 8
0 0 1 0 0 0 0 0 
1 1 1 1 1 1 1 0

*/