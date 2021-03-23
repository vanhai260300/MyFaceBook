#include<stdio.h>
void Input(int ds[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("Nhap phan tu thu %d : ",i);
		scanf("%d",&ds[i]);
	}
}
void Out(int ds[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf(" %d ",ds[i]);
	}
}
void hoanvi(int &a,int &b)
{
	int tg=a;
	a=b;
	b=tg;
}
void SXnoibot(int ds[],int n)
{
	for(int i=1;i<=n;i++)
	   for(int j=n;j>=1;j--)
	   	 if(ds[j]<ds[j-1])
	   	{
	   		hoanvi(ds[j],ds[j-1]);
	   		Out(ds,n);
	   	}
}
main()
{
	int a[10],n;
	printf("Nhap so phan tu cua ds : ");
	scanf("%d",&n);
	Input(a,n);
	printf("Day so ban dau la : \n");
	Out(a,n);
	printf("Minh hoa thuat toan : \n");
	SXnoibot(a,n);
	printf("Day so sau khi sap xep la : ");
	Out(a,n);
}
