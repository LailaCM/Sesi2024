#include <stdio.h>

int j,i;

int main()
{
 for(j=1;j<=10;j++){
     for(i=1;i<=10;i++){
         printf("%d x %d = %d \t", j,i, j*i);
     }
     printf("\n");
 }
}
