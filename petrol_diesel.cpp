#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll i,a1,b1,c1,d1,e1;
    ll a2,b2,c2,d2,e2;

    cin>>a1>>b1>>c1>>d1>>e1;
    cin>>a2>>b2>>c2>>d2>>e2;


    double total_fuel_needed = (d1)/(float)a1;
    double cost  = total_fuel_needed*b1;
    cost+= e1;   // montyly maintainence
    double cost_a = cost*60;  // for 60 months 
    cost_a += c1;  // show room price

    total_fuel_needed = (d2)/a2;
    cost  = total_fuel_needed*b2;
    cost+= e2;
    double cost_b = cost*60;
    cost_b += c2;  // show room price   

    if(cost_a<cost_b)
        cout<<"petrol";
    else  
        cout<<"diesel";

    return 0;
}

/*   
    13 81 591000 1000 450 
    16 67 684000 1000 1000

    petrol

    15 70 600000 1000 500
    16 60 590000 1000 600

*/