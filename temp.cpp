/*  

24
7 10 20 -16 3 -2 20 12 20 2 5 -6 -2 14 13 -18 -13 20 4 18 0 7 15 19

*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    unsigned long long int optimalKeys(int n) {
         
        if(n<=6)
            return n;
            
        int dp[n+1],i;
        
        for(i=0;i<=6;i++)
            dp[i] = i;    
        
        for(i=7;i<=n;i++)
            dp[i] = max(max(2*dp[i-3],3*dp[i-4]),4*dp[i-5]);
            
        //for(i=1;i<=7;i++)
        //    cout<<"i:"<<i<<" :"<<dp[i]<<"\n";
        //dp[2] = 2;
        //cout<<"n :"<<n<<"\n";
        return dp[n];
        
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

/*
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    
    sort(arr.begin(),arr.end());
    
    int p,q,l,r,curr_sum,pairs = 0,n = arr.size();
    vector<vector<int>>ans;
    
    for(p=0;p<n;p++)
    {
        for(q=p+1;q<n;q++)
        {
            curr_sum = k - (arr[p]+arr[q]);
            l = q+1; r = n-1;
            
            while(l<r)
            {
                if(arr[l]+arr[r]==curr_sum)
                    ans.push_back(vector<int>{arr[p],arr[q],arr[l],arr[r]});
                    
                if(arr[l]+arr[r]<curr_sum)
                    l++;
                else 
                    r--;
            }
            
        }
    }
     return ans;
}
*/


/*#include <bits/stdc++.h>
using namespace std;


int main()
{

    dp[0] = dp[1]=1;

    for(i=2;i<=n;i++)
    {   
        dp[i]=0;
        for(j=1;j<=i;j++)
            dp[i]+=dp[j-1]*dp[i-j];
    }
    return 0;
}
 */

/*  

 ncr(int n,int r)
 {
     r = min(r,n-r);

     for(i=0;i<r;i++)
        ans *= (n-i)
        ans/= (i+1);
 }

*/

/*

    3
1 2    4 5
 
1 2
2 1

      1              1
        2             3
          3          2  
    
     2 
    1 3

    3              3
   1              2
     2           1
*/


/* Nqueen problem


   1,1  1,2  1,3 1,4

   2,1  2,2  2,3 2,4

   3,1  3,2  3,3 3,4

   4,1  4,2  4,3 4,4


*/


/*bool place(int k,int i)
{
    for(int j=1;j<k;j++)
        if(x[j]==i || j+x[j]==k+i || abs(j-x[i])==abs(k-i) )    
            return false;
    
    return true;    
}



void Nqueen(int k)
{
    if(k>n) return ;

    for(int i=1;i<=n;i++)
        if(place(k,i))
        {    
            x[k]=i;
            Nqueen(k+1);
        }
}

*/

// graph colouring.cpp


/*
void nextColor(int k)
{
    while(1)
    {
        x[k]= (x[k]+1) % (n+1);  
        if(x[k]==0)
            return ;

        for(j=0;j<n;j++)
            if(g[k][j] && x[k]==x[j])
                break;

        if(j==n)
            return ;

    }
              
}

void graphColor(int k)
{
    if(k>n)
        return ;

    while(1)
    {
       nextColor(i);
       if(x[i]==0)
            return ;
       graphColor(k+1);
    }
}

*/

/*
             7
            / 
            5 
          4   6
        3  5 4  2  

*/
// 1 2 3 4 5
// 0 1 2 3 4

// 1 2 3 4 5 6

// 0 1 2 3 4 5

// 

/*
void increment_middle()
{
    int mid = len/2;
    if(len%2==0) mid--;

    if(arr[mid]!=9)
        arr[mid]++;
    else  
    {
        while(arr[mid]==9 && mid<len )
            arr[mid]=0,mid--;
        arr[mid]++;
    }
}

void copy_digits()
{
    mid = len/2;
    l = mid; r = mid;
    if(len%2==0) l--;

    while(l>=0 && r<len)
        arr[r++]=arr[l--];
}

mid = len/2;

l = mid; r = mid;
if(len%2==0) l--;


while(l>=0 && r>=0 )
{
    if(arr[l]!=arr[r])
        break;
    if(arr[l]!=9 || arr[r]!=9)
        all_nines = false;
    l--;r--;

}

if(l<0)  // given is palindrome
{
   increment_middle();
   copy_digts();
}
else  
{
    if(arr[l]<arr[r])
        increment_middle();
        copy digits();
    
    else  // arr[l]>arr[r]   
    {
        copy_digits();
    }
}


// reverse LL recursively

Node reverseLL(Node **head,Node **tail)
{
    if(*head==NULL)
        return ;
    if((*head)->next==NULL)
    {
        *head = *head;
        *tail = *head;
        return ;
    }    
    
    Node *curr = (*head);
    curr->next = NULL;  
    reverseLL((*head)->next,tail)

    (*tail)->next = curr;

}   

*/

/*
     SC           EC
     11 12 13 14 15
     21 22 23 24 25  SR
     31 32 33 34 35
     41 42 43 44 45
     51 52 53 54 55  ER


*/

