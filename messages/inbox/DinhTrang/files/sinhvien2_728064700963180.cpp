#include<stdio.h>
#include<string.h>
struct SINHVIEN
        {
        	char masv[13], ten[10], hlot[20];
        	float dtb;
		};
void NHAP_SV (SINHVIEN ds[], int  n)       
{
	int i;
	for(i=1;i<=n; i++)
	{
	  fflush(stdin);
	  printf("Nhap ma sinh vien thu %d ",i);
	  gets(ds[i].masv);
      printf("Nhap ho va ten ");
	  gets(ds[i].hlot);
	  gets(ds[i].ten);
	  printf("Diem Trung Binh :");
	  scanf("%f",&ds[i].dtb);
	}
     
}
void IN_SV(SINHVIEN ds[], int n)
{
	int i;
	for(i=1;i<=n;i++)
	  printf("%13s  |   %20s %10s  |  %0.2f\n ",ds[i].masv,ds[i].hlot,ds[i].ten,ds[i].dtb);
}
void Chen_SV (SINHVIEN  a[],int &n,int vt)
{  
    int i;
    if(vt>n)
      vt=n+1;
    if(vt<1)
	  vt=1;  
    for ( i=n;i>=vt;i--)
 
    {
        strcpy(a[i+1].masv,a[i].masv);
        strcpy(a[i+1].hlot,a[i].hlot);
        strcpy(a[i+1].ten,a[i].ten);
        a[i+1].dtb=a[i].dtb;
    }  
	n=n+1;
    fflush(stdin);
    printf("Nhap masv can chen: ");
    gets(a[vt].masv);
    printf("Nhap ho va ten can chen : ");
    gets(a[vt].hlot);
    gets(a[vt].ten);
   
    printf("Nhap diem TB can chen : ");
    scanf("%f",&a[vt].dtb);
    
}
main()
{
	SINHVIEN sv[100];
   
	int spt,vitri;

	printf("Nhap bao nhieu sinh vien : ");
	scanf("%d",&spt);
	NHAP_SV(sv,spt);
	IN_SV(sv,spt);
	fflush(stdin);
	
	printf("nhap vi tri chen ");
	scanf("%d",&vitri);
    Chen_SV(sv,spt, vitri);
    IN_SV(sv,spt);
}

