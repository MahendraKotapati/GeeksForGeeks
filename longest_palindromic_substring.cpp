#include<bits/stdc++.h>
typedef long int li;
using namespace std;


string  longest_palindromic_substring(string str)
{


        li len=str.length(),i,j,l,r,maxi=0;
        li dp[len+1][len+1]={0};
        //for(i=0;i<len;i++)  for(j=0;j<len;j++)  dp[i][j]=0;
        memset(dp,0,sizeof(dp));
        for(i=0;i<len;i++) dp[i][i]=1;
        
        for(i=0;i<len;i++)
        {
            l=i-1;  r=i;
            while(l>=0 && r<len )
            {
                if(str[l]!=str[r])  
                  break;
                dp[l][r]=1;
                l--;
                r++;
            }
        }

        for(i=0;i<len;i++)
        {
            l=i-1; r=i+1;
            while(l>=0 && r<len )    
            {
                
                if(str[l]!=str[r])
                  break;
                dp[l][r]|=1;    
                l--;
                r++;
            }     
        }

        maxi=-1;  r=l=0;
        for(i=0;i<len;i++)  
        {
            for(j=i;j<len;j++)
              if(dp[i][j]&& (j-i>maxi) )
              {
                    l=i;r=j;
                    maxi=max(maxi,r-l);
              }

        }
       /* cout<<"  ";
        for(i=0;i<len;i++)
           cout<<i<<" ";
        cout<<"\n";
        for(i=0;i<len;i++)
        {   
            cout<<i<<":";
            for(j=0;j<len;j++)
              cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        cout<<l<<" "<<r;
        */
       string ans="";
       for(i=l;i<=r;i++)
       {
           ans+=str[i];
       }

        return ans;

}

int main()
{

    li t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<longest_palindromic_substring(str)<<"\n";
    }


      return 0;
}
