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
void SXtructiep(int ds[],int n)
{
	for(int i=1;i<=n-1;i++)
	{
	    int min=i;
	    for(int j=i+1;j<=n;j++)
	        if(ds[min]>ds[j])
	        	min=j;
	    hoanvi(ds[i],ds[min]);
	    if(i!=min)
	    {
	      printf("\n");
	      Out(ds,n);
	    }
	}
}
main()
{
	int a[10],n;
	printf("Nhap so phan tu trong mang : ");
	scanf("%d",&n);
	Input(a,n);
	printf("Day so ban dau la : \n");
	Out(a,n);
	printf("\n Minh hoa thuat toan : \n");
	SXtructiep(a,n);
	printf("\n Day so sau khi sap xep la : \n");
	Out(a,n);
}
