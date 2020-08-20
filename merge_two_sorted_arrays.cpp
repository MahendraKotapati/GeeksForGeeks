#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

ll find_pivot(vector <ll>&A,ll n,vector <ll>&B,ll m)
{
    ll i=0,j=0,c=0;

    while(c<n)
    {
        if(A[i]<B[j])
            i++;
        else  j++;
        c++;
    }
    if(i<n)
        return A[i];
    return B[j];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,k,n,m,pivot;
    cin>>t;
	
    while(t--)
    {   
        cin>>n>>m;
        vector <ll>A(n),B(m);

        for(i=0;i<n;i++)
            cin>>A[i];
        
        for(i=0;i<m;i++)
            cin>>B[i];

        /*i=k=0;
        while(i<n)
        {
            if(A[i]<=B[j]){
                i++; continue;
            }
            swap(A[i],B[j]);
            swap(B[j],B[k]);
            while(k+1<m && B[k]>B[k+1])
                swap(B[k],B[k+1]),k++; 
            i++;j++;
        }
        */

        pivot = find_pivot(A,n,B,m);
        //cout<<pivot<<" ";
        //B[0]=pivot;
        i=0;j=0;
        while(i<n && j<m)
        {
            while(i<n && A[i]<pivot)
                i++;
            while(j<m && B[j]>=pivot)
                j++; 
            if(i<n && j<m)
                swap(A[i],B[j]);
        }

        //sort(A.begin(),A.end());
        //sort(B.begin(),B.end());

        for(i=0;i<n;i++)
            cout<<A[i]<<" ";
        
        for(i=0;i<m;i++)
            cout<<B[i]<<" ";
        cout<<"\n";
    
    }
    
    return 0;
}