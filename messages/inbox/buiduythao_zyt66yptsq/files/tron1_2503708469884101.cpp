#include<stdio.h>
#include<String.h>
	struct ten{
		char z[10];
	};
void SXtron(ten ds[],ten a[],ten b[],int m,int n,int &k)
{
	int i=1,j=1,p;
    k=1;
    while(m>=i&&n>=j)
    {
    	if(strcmp(a[i].z,b[j].z)<=0)
    	{
    		ds[k]=a[i];
    		i++;
    	}
    	else
    	{
    		ds[k]=b[j];
    		j++;
    	}
    	k++;	
    }
    if(i<m)
    {
    	for(p=i;p<=m;p++)
    	{
    		ds[k]=a[p];
    		k++;
    	}
    }
    else
        for(p=j;p<=n;p++)
    	{
    		ds[k]=b[p];
    		k++;
    	}
}
  void Out(ten ds[],int n)
{
	for(int i=1;i<=n;i++)
	{
		printf(" %10s ",ds[i].z);
	}
	printf("\n");
} 	
main()
{
	ten a[10],b[10],c[20];
	int k,m,n;
	printf("Nhap so danh sach a : ");
	scanf("%d",&m);
	printf("\nNhap danh sach a \n");
	for(int i=1;i<=m;i++)
	{
		fflush(stdin);
		printf("Nhap ten thu %d : ",i);
		gets(a[i].z);
	}
	printf("\nNhap so danh sach b : ");
	scanf("%d",&n);
	printf("Nhap danh sach b \n ");
	for(int j=1;j<=n;j++)
	{
		fflush(stdin);
		printf("Nhap ten thu %d : ",j);
		gets(b[j].z);
	}
	SXtron(c,a,b,m,n,k);
	printf("\n Danh sach sau khi sap xep la : \n");
	Out(c,k-1);
  
}
