
#include <stdio.h>
typedef long int li;

int main() {
  //Write your code here. 
  li n,arr,fre[10005]={0},i,pairs=0;
  scanf("%ld",&n);

  for(i=0;i<n;i++)
  {
    scanf("%ld",&arr);
    fre[arr]++;
  }

  pairs=0;
  for(i=1;i<=10000;i++)
     pairs+=fre[i]/2;

  
    
  printf("%ld",pairs);

  return 0;
}
