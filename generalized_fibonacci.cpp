#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;
#define maxm 3

ll mod,a,b,c;

void mat_mul(ll A[][3],ll B[][3])
{
    ll res[3][3],i,j,k;
     
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {   
            res[i][j]=0;
            for(k=0;k<3;k++)
                res[i][j] = ( res[i][j]+ (A[i][k]*B[k][j])%mod )%mod ;          
        }
    }

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            A[i][j] = res[i][j]; 

}

ll power(ll n)
{
    ll i,j,mag[3][3],res[3][3]={0};


    /* 
        matrix is   [ 0 1 0][ G1 ]    [ G2 ]
                    [ b a c][ G2 ] =  [ G3 ]
                    [ 0 0 1][ 1  ]    [ 1  ]  
    */
    res[0][0] = res[1][1] = res[2][2] = 1;

    mag[0][0]=0; mag[0][1]=1;  mag[0][2]=0;
    mag[1][0]=b; mag[1][1]=a;  mag[1][2]=c;
    mag[2][0]=0; mag[2][1]=0;  mag[2][2]=1;

    
    while(n>0)
    {
        if(n&1)
            mat_mul(res,mag);
        
        mat_mul(mag,mag);
        n/=2;
    }

    return  (res[1][0]+res[1][1]+res[1][2])%mod; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,m,n;
    cin>>t;
	
    while(t--)
    {   

        cin>>a>>b>>c>>n>>mod;  
        n--; // we need to take 0th indexing 
        if(n<=1)
            cout<<"1"<<"\n";
        else 
            cout<<power(n-1)<<"\n";
    }
    
    
    return 0;
}