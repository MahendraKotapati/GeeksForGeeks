typedef long long ll;
using namespace std;

ll dp[105][100005];
int main()
{

    ll t,n,i,j,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector <ll>arr(n);
        sum=0;
        for(i=0;i<n;i++)    
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum&1)
        {
            cout<<"NO"<<"\n";continue;
        }
        sum/=2;
       for(i=0;i<=n;i++)
       {
           for(j=0;j<=100000;j++)
            dp[i][j]=0;
       }
        
        for(i=0;i<=n;i++)  dp[i][0]=1;
        for(i=0;i<=sum;i++)  dp[0][i]=0;    
        dp[0][0]=1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)    
                if(j>=arr[i-1])
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                else
                      dp[i][j]=dp[i-1][j]; 
        }
        if(dp[n][sum])
            cout<<"YES"<<"\n";
        else 
            cout<<"NO"<<"\n";

    }
    return 0;
}