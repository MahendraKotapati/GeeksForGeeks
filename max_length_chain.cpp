// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool cmp(struct val &p1,struct val &p2)
{
    return p1.first<p2.first;  
}

/*  (a,b) (c,d)   b<c  */

// if we sort based on first coordinate in incresing order then problem reuduces to LIS
 
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,cmp);

    int i,j,dp[n];

    for(i=0;i<n;i++)
    {   
        dp[i]=1;
        for(j=0;j<i;j++)
            if(p[i].first > p[j].second && dp[i]<dp[j]+1)
                dp[i] = dp[j]+1;
    }
    return *max_element(dp,dp+n); 
    
}

/*

{ {5, 24}, {15, 28}, {27, 40}, {39, 60}, {50, 90} }


class Test:
    _emp  = 10

a = Test()
print(a._emp)

*/