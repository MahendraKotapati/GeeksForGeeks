#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

void merge(int  A[],int B[],int n,int m)
{
	int i = n - 1;
	int j = 0;
	while (i >= 0 && j < m)
	{
		if (A[i] > B[j])
			swap(A[i], B[j]);
			
	    i--;
	    j++;
	}

	sort(A, A+n);
	sort(B, B+m);
}

ll cal_gap(ll gap)
{   
    if(gap==1) return 0;
    return (gap/2)+(gap%2);
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,n,m,gap,start;
    cin>>t;
	
    while(t--)
    {   
        cin>>n>>m;
        vector <ll>A(n),B(m);

        for(i=0;i<n;i++)
            cin>>A[i];
        
        for(i=0;i<m;i++)
            cin>>B[i];

        /*gap = (n+m);
        for(gap = cal_gap(gap);gap>0;gap=cal_gap(gap))
        {
            for(i=0;i+gap<n;i++)
                if(A[i]>A[i+gap])
                    swap(A[i],A[i+gap]);
            
            start = (gap>n)?  gap-n : 0;

            for(j=start ; i<n && j<m;i++,j++)
            {
                
                    swap(A[i],B[j]);
            }
if(A[i]>B[j])
           
            for(j=0;j+gap<m;j++)
                if(B[j]>B[j+gap])
                    swap(B[j],B[j+gap]);
            
        }
        */

         
        for(i=0;i<n;i++)
            cout<<A[i]<<" ";
        
        for(i=0;i<m;i++)
            cout<<B[i]<<" ";
        cout<<"\n";
    
    }
    
    return 0;
}

/*  

x x x x x     x x x x x  

0 1 2 3    5 6 7 8 9  values
0 1 2 3    4 5 6 7 8  indexes

*/