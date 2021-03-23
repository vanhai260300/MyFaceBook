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
void SXnhanh(int ds[], int L , int R)
{
		int TB = ds[(L+R)/2];
		int i = L;
		int j = R;
 
		while (i<=j)
		{
			while (ds[i] < TB)
				i++;
			while (ds[j] > TB)
				j--;
 
			if (i <= j)
			{
				hoanvi(ds[i], ds[j]);
				i++;
				j--;
			}
		}
		if (L < j)
			SXnhanh(ds, L, j);
		if (R > i)
			SXnhanh(ds, i, R);
	
}
main()
{
	int a[10],n;
	printf("Nhap so phan tu cua mang a : ");
	scanf("%d",&n);
	Input(a,n);
	printf("\n Day so ban dau La : \n");
	Out(a,n);
	printf("\n Day so sau khi sap xep La : \n");
	SXnhanh(a,1,n);
	Out(a,n);
	}
