#include<stdio.h> 
#include<locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	
	int i = 0;
	i = i + 1;
	printf("%d\n",i);
	i++;
	printf("%d\n",i);
	i = i + 2;
	printf("%d\n",i);
	i+=2;
	printf("%d\n",i);
	i= i - 1;
	printf("%d\n",i);
	i--;
	printf("%d\n",i);
	i= i - 8;
	printf("%d\n",i);
	i-=8;
	printf("%d\n",i);
	i= i * 3;
	printf("%d\n",i);
	i*=3;
	printf("%d\n",i);
	i= i / 3;
	printf("%d\n",i);
	i/=3;
	printf("%d\n",i);
	return 0;
}
