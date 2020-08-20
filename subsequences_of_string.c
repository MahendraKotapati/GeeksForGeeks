#include<stdio.h>
int size,sub_seq[100],flag=0;


void print_subsequence(int len,int arr[])
{

    for(int i=0;i<=len;i++)  printf("%d ",arr[i]);
    printf("\n");

}

void power_set(int arr[][2],int i,int len)
{

    for(int j=i;j<size;j++)
    {

          if(arr[j][1]==0)
           continue;

          arr[j][1]--;
          sub_seq[len]=arr[j][0];
          print_subsequence(len,sub_seq);
          power_set(arr,j,len+1);
          arr[j][1]++;

    }

}


int main()
{
    int t,n,arr[100],str[100][2];
    int fre[101],i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);size=0;
        memset(fre,0,sizeof(fre));
        for(i=0;i<n;i++)
        {
                scanf("%d",&arr[i]);
                 fre[arr[i]]++;
        }

        for(i=1;i<=100;i++)
        {
            if(fre[i])
            {
               str[size][0]=i;str[size++][1]=fre[i];

            }
        }

             power_set(str,0,0);
    }

    return 0;
}
