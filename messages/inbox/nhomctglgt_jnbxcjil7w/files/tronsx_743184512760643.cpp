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
void SXtructiep(int ds[],int n)
{
	for(int i=1;i<=n-1;i++)
	{
	    int min=i;
	    for(int j=i+1;j<=n;j++)
	        if(ds[min]>ds[j])
	        	min=j;
	    hoanvi(ds[i],ds[min]);
	}
}
void SXtron(int ds[],int a[],int b[],int m,int n,int &k)
{
	int i=1,j=1,p;
    k=1;
    while(i<m&&j<n)
    {
    	if(a[i]<=b[j])
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
    	
main()
{
	int a[10],b[10],x,y,k,ds[20];
	printf("Nhap so phan tu trong mang a : ");
	scanf("%d",&x);
	Input(a,x);
	SXtructiep(a,x);
	printf("\n Day so sau khi sap xep cua mang a la : \n");
	Out(a,x);
	printf("\n Nhap so phan tu trong mang b : ");
	scanf("%d",&y);
	Input(b,y);
	SXtructiep(b,y);
	printf("\n Day so sau khi sap xep cua mang b la : \n");
	Out(b,y);
	SXtron(ds,a,b,x,y,k);
	printf("\nDay so sau khi sap xep tron mang a va mang b la : \n");
	Out(ds,k);
	
}
