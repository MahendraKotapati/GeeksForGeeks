#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define maxn 12
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,c[20]={0},n;

    c[0]=c[1]=1;  // base case when no.of nodes is <=1 then possible trees is 1

    for(i=2;i<maxn;i++)
    {   
        for(j=1;j<=i;j++)  // if i is the no.of nodes then 
            c[i]+=c[j-1]*c[i-j];  // then  j-1 nodes falls on left substree , j is root , i-j falls on right substree , 
                                    // since every j is different we guarantee for unique BST
    }
    cin>>t;

    while(t--)
    {   
        cin>>n;
        cout<<c[n]<<"\n";
    }
    
    return 0;
}