#include<bits/stdc++.h>
#include<algorithm>
#define F first
#define S second
typedef long long ll;
using namespace std;

ll lenpf,m;
vector <ll>pf[10004];

/*void solve(ll val,vector<ll> &lcm)
{
    ll i,c;
    for(i=0;i<lenpf;i++)
    {  
        if(val==1)
            break;
        c=0;
       
        while(val%pf[i]==0)
            val/=pf[i],c++;
        
        lcm[pf[i]]=max(lcm[pf[i]],c);
        
    }
}
*/

void solve()
{   
    ll i,j,val,c;

    for(i=2;i<=1000;i++)
    {
        val = i;  c=0;

        while(val%2==0)
            val/=2,c++;

        if(c)  pf[i].push_back(2);

        for(j=3;j*j<=i;j+=2)
        {   c=0;
            while(val%j==0)
                val/=j,c++;
            if(c)   pf[i].push_back(j);
        }
        if(val>2)
            pf[i].push_back(i);
        //cout<<"check";
    }
    

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll t,i,j,n,x,gcd,curr,maxi,c,val;
    
    cin>>t;
	
    solve();
     
    while(t--)
    {
        cin>>n>>m;  
        vector <ll>arr(n),lcm(10000+1,0);


        for(i=0;i<n;i++)
        {
            cin>>val;  c=0;
            
            for(auto j:pf[val])
            {
                while(val%j==0)
                    val/=j,c++;

                lcm[j]=max(lcm[j],c);
            }
        }    


        
        gcd=1; maxi = 0; x=1;

        for(j=1;j<=m;j++)
        {      
            c=0;   val=j;   gcd=1;
           
            for(auto i:pf[val])
            {  
               
                c=0;
                while(val%i==0)
                    val/=i,c++;
            
                gcd*=(ll)(pow(i,min(lcm[i],c))+0.5);
                
            } 
         
            curr = j/gcd;
            
            if(maxi<curr)
                maxi = curr,x=j;

        }
    
       cout<<x<<"\n";

    }
    
    return 0;
}

/*

2
3 2
2 1 2
4 7
2 5 6 3


*/