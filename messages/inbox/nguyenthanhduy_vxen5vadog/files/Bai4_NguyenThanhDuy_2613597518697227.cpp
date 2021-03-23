#include<stdio.h>
#include<string.h>
struct Node_List
	{
	float dtb;
	char tensv[30], lop[10], msv[13];
	Node_List *Adr_ItAf;
	};
Node_List *Add_Af(Node_List *H, Node_List *It)
{
	Node_List *tmp;
	if (H==NULL)
		H=It;
	else
	{
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;
	}
	return H;
}
Node_List *Input(Node_List *H, int n)
{
	Node_List *p;
	int i;
	for (i=1;i<=n;i++)
	{		
		p=new Node_List;
		printf("nhap sinh vien thu %d: \n",i);
		fflush(stdin);
		printf("Ten Sinh Vien: ");
		gets(p->tensv);
		printf("Ma Sinh Vien: ");
		gets(p->msv);
		printf("Lop: ");
		gets(p->lop);
		printf("Diem Trung Binh: ");
		scanf("%f",&p->dtb);
		p->Adr_ItAf=NULL;
		H=Add_Af(H,p);
	}
	return H;
}
void  BRW_IT(Node_List *H)
{
	Node_List *tmp;
	if (H==NULL)
		printf("danh sach NULL");
	else
	{
		printf("Thong tin vua nhap la: \n");
		tmp=H;
		while (tmp!=NULL)
		{
			printf("%s || %s || %s || %f \n",tmp->msv,tmp->tensv,tmp->lop,tmp->dtb);
			tmp=tmp->Adr_ItAf;
		}
	}
}
Node_List *Search(Node_List *H, char m[])
{
	Node_List *tmp;
	tmp=H;
	while (tmp!=NULL)
	{
		if (strcmpi(tmp->lop,m)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	return NULL;
}
Node_List *Delete(Node_List *H, char m[])
{
	Node_List *tmp, *p;
	p=Search(H,m);
	if (H==p)
	{
		H=H->Adr_ItAf;
		p->Adr_ItAf=NULL;
	}
	else
	{
		tmp=H;
		while (tmp->Adr_ItAf!=p)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=p->Adr_ItAf;
		p->Adr_ItAf=NULL;
	}
	return H;
}
main()
{
	Node_List *Hd;
	char l[10];
	int n;
	Hd=NULL;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	Hd=Input(Hd,n);
	BRW_IT(Hd);
	printf("Nhap Lop can xoa: ");
	fflush(stdin);
	gets(l);
	Hd=Delete(Hd,l);
	BRW_IT(Hd);
}

