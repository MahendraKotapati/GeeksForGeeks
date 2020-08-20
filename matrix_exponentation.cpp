#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mod 1000000007
#define maxn 3
typedef long long ll;
using namespace std;

void mul(ll A[maxn][maxn],ll B[maxn][maxn])
{
    ll res[maxn][maxn],i,j,k;

    for(i=0;i<maxn;i++)
    {
        for(j=0;j<maxn;j++)
        {   
            res[i][j]=0;
            for(k=0;k<maxn;k++)
                res[i][j] = (res[i][j]+ (A[i][k]*B[k][j])%mod )%mod;
        }
    }
    
    for(i=0;i<maxn;i++)
        for(j=0;j<maxn;j++)
            A[i][j]=res[i][j];

}

ll expo(ll exp)
{
    ll res[maxn][maxn]={ {1,0,0},{0,1,0},{0,0,1} },i,j;
    ll base[maxn][maxn]={ {0,1,0},{0,0,1},{1,1,0} };

    while(exp>0)
    {
        if(exp&1)
            mul(res,base);
        mul(base,base);
        exp/=2;
    }


    /* 
    
    F(n)=F(n-2)+F(n-3)   is nothing but,  F(n) = 0*F(n-1)+F(n-2)+F(n-3)
    
    Nth term depends on previous 3 terms of 3X3 matrix is taken
          ^1
    [ 0 1 0 ][F0]   [F1]
    [ 0 0 1 ][F1] = [F2]
    [ 1 1 0 ][F2]   [F3]

            ^(n-2)
    [ 0 1 0 ]    [F0]   [Fn-2]
    [ 0 0 1 ]    [F1] = [Fn-1]
    [ 1 1 0 ]    [F2]   [Fn]

    */
 
    return (res[2][0]+res[2][2])%mod;  // return 1*res[2][0]+0*res[2][1]+1*res[2][2];
}

ll solve(ll n)
{   
    return expo(n-2);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,n;
    cin>>t;
	
    while(t--)
    {
        cin>>n; 
        if(n==0) cout<<"1";
        else if(n==1) cout<<"0";
        else if(n==2) cout<<"1";
        else  
            cout<<solve(n);
        cout<<"\n";
    }
    
    return 0;
}