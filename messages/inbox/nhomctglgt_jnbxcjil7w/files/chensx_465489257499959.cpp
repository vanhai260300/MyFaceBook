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
void SXchen(int ds[],int n)
{
 	int t,j,x;
 	for(int i=1;i<=n;i++)
 	{
  		j=i-1;
  		t=ds[i];
  		if(t<ds[j])
  		{
  			while(j>=0&&t<ds[j])
  			{
   				ds[j+1]=ds[j];
   				j--;
  			}
  			ds[j+1]=t;
  			Out(ds,n);
  			printf("\n");
  		}
  		else
  		   ds[j+1]=t;
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
	SXchen(a,n);
	printf("\n Day so sau khi sap xep la : \n");
	Out(a,n);	
}
