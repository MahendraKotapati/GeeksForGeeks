#include<bits/stdc++.h>
typedef  int li;
using namespace std;
//li dp[1004][10004];

string  longest_palindromic_substring(string str)
{

      li len=str.length(),i,j,l,r,maxi=0;
      li dp[len+1][len+1]={0};

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
      
    /*
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

    li t,len,i,j,curr_len=0,l,r,start,max_len;
    string str;
    cin>>t;

    while(t--)
    {
        cin>>str; len = str.length(); start = 0; max_len = 1;

        vector<vector<bool>>dp(len,vector<bool>(len));  // dp [i][j] stores whether str[i:j] is palindrome or not

        for(i=0;i<len;i++)
          dp[i][i]=true;
        
        for(i=1;i<len;i++)
          if(str[i]==str[i-1])
          {
              dp[i-1][i] = true;
              if(max_len<2) max_len=2,start=i-1;
          }

        for(curr_len=3;curr_len<=len;curr_len++)
        {
            for(j=0;j+curr_len-1<len;j++)
            {
                l = j; r = j+curr_len-1;

                if(str[l]==str[r] && dp[l+1][r-1])
                {
                  dp[l][r] = true;
                  if(r-l+1>max_len) 
                      max_len = r-l+1,start = l;
                }
            }
        }

        cout<<str.substr(start,max_len)<<"\n";
    }
      return 0;
}

/*   

a b c d e f g h i j 
- - 
- - -

*/