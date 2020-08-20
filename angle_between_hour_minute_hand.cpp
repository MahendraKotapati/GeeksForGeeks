#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int t;
	double h,m,ans;
	
	cin>>t;
	while(t--)
	{
	    cin>>h>>m;
	    if(m==60)
	        m=0;
	        
	    double angle_h = h*30+m*0.5;  
		double  angle_m = m*6 ; 
		ans = fabs(angle_h-angle_m);
	    
	    cout<<int(min(ans,360-ans))<<"\n";
	}
	return 0;
}