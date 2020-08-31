// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/




bool cmp(vector<int>&a,vector<int>&b)
{
    return (b[1]*b[2]<a[1]*a[2]);
}

int maxHeight(int height[],int width[],int length[],int n)
{
    int l1,w1,l2,w2,h2,i,j,k,r,ans,idx=0;
    int dp[3*n];
    vector<vector<int>>arr(3*n,vector<int>(3)); // 0 height ,1-width , 2-length

    for(i=0;i<n;i++)
    {
        arr[idx][0] = height[i];
        arr[idx][1] = min(width[i],length[i]);
        arr[idx++][2] = max(width[i],length[i]);

        arr[idx][0] = width[i];
        arr[idx][1] = min(length[i],height[i]);
        arr[idx++][2] = max(length[i],height[i]);

        arr[idx][0] = length[i];  // hgt
        arr[idx][1] = min(height[i],width[i]);   // wid
        arr[idx++][2] = max(height[i],width[i]);// len
    }


    /*  
        we sort boxes because now, the problem reduces to LIS, if we don't sort then boxes may scattered anywhere, on top of last box
        first box may fit , then it is difficult to slove that , if we sort boxes in descending order of box area, then on top of 
        last box first box doesn't fit (because last box area is small i.e last_box_width<first_box_width or last_box_length<first_box_length )

        now, problem reduces to max sum longest incresing subsequence.
    */
    sort(arr.begin(),arr.end(),cmp);
    n = 3*n;
    
    for(i=0;i<n;i++)
    {    
        dp[i] = arr[i][0];
        
        for(j=0;j<i;j++)
        {
            if(arr[i][1]<arr[j][1] && arr[i][2]<arr[j][2] && dp[i]<dp[j]+arr[i][0])    
                dp[i] = dp[j]+arr[i][0];
        }   
    }
    //for(int i=0;i<n;i++) 
    //    printf("h:%d w:%d l:%d\n",arr[i][0],arr[i][1],arr[i][2]);
    //printf("\n");

    return *max_element(dp,dp+n);
}