

int findMin(int arr[], int n){



     int low=0,high=n-1,i,mid,min=arr[0];

     while(low<=high)
     {

         i=(low+high)/2;

        if( (i==0 || arr[i-1]<arr[i]) &&
            (i==(n-1) || arr[i]>arr[i+1] ) )
        {
           if((i+1)<n&&min>arr[i+1])  min=arr[i+1]; break;
        }
        else  if( (i==0 || arr[i-1]>arr[i]) &&
            ((i==n-1) || arr[i]<arr[i+1] ) )
         {
             if(min>arr[i]) min=arr[i];   break;
         }

         else   low=i+1;

     }

     low=0;high=n-1;

    while(low<=high)
     {
        i=(low+high)/2;

        if( (i==0 || arr[i-1]<arr[i]) &&
            ((i==(n-1)) || arr[i]>arr[i+1] ) )
        {
           if((i+1)<n&&min>arr[i+1])  min=arr[i+1]; break;
        }
        else  if( (i==0 || arr[i-1]>arr[i]) &&
            ((i==(n-1)) || arr[i]<arr[i+1] ) )
         {
             if(min>arr[i]) min=arr[i];   break;
         }

         else    high=i-1;


     }


    return min;


}



int main()
{

    int arr[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("%d\n",findMin(arr,n));



}

