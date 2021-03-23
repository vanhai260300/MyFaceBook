#include<stdio.h>
#include<math.h>
int armstrong(int n)
{
	if(n==0)
		return 0;
	else
		return pow(n%10,3)+armstrong(n/10);
}
main(){
	int n;
	printf("nhap n:");
	scanf("%d",&n);
	if(armstrong(n)==n)
		printf("yes");
	else
		printf("no");
}
