#include<stdio.h>
#include<string.h>

struct SV{
	char masv[15], tensv[15],lop[10];
	float dtb;
};

struct Node_list{
	SV data;
	Node_list *Adr_ITAD;
};

Node_list *Add_AF(Node_list *H, Node_list *p)
{
	if(H==NULL)
	{
		H=p;
		p->Adr_ITAD=H;
	}
	else
		{
			Node_list *tmp=H;
			while(tmp->Adr_ITAD!=H)
				tmp=tmp->Adr_ITAD;
			tmp->Adr_ITAD=p;
		}
	return H;
}

Node_list *NHAP(Node_list *H, int n)
{
	Node_list *p;
	for(int i=1;i<=n;i++)
	{
		fflush(stdin);
		Node_list *IT=new Node_list;
		printf("\n nhap sinh vien thu %d: ",i);
		printf("\n nhap ma sinh vien: ");
		gets(IT->data.masv);
		printf(" nhap ten sinh vien: ");
		gets(IT->data.tensv);
		printf(" nhap lop: ");
		gets(IT->data.lop);
		printf(" nhap diem TB: ");
		scanf("%f",&IT->data.dtb);
		IT->Adr_ITAD=H;
		H=Add_AF(H,IT);
	}
	return H;
}

void display(Node_list *H)
{
	Node_list *tmp=H;
	printf("\n        MA sv  |    Ten sv       | Lop sv     | DTB");
	if(H==NULL)
		printf("\n Khong co sinh vien");
	else
		do
		{
			printf("\n %15s| %15s|%10s |%4.2f |",
			tmp->data.masv,tmp->data.masv,tmp->data.lop,tmp->data.dtb);
			tmp=tmp->Adr_ITAD;
		}
		while(tmp!=H);
}

Node_list *search_IT(Node_list *H, char info[])
{
	Node_list *tmp=H;
	do
	{
		if(strcmp(tmp->data.lop, info)==0)
			return tmp;
		tmp=tmp->Adr_ITAD;
	}
	while(tmp!=H);
	return NULL;
}

Node_list *Delete_Node(Node_list *H, char info[])
{
	Node_list *IT_Found=search_IT(H,info);
	if(IT_Found==NULL)
		return H;
	if(H->Adr_ITAD==H)
		return NULL;
	if(IT_Found==H)
	{
		H=H->Adr_ITAD;
		IT_Found->Adr_ITAD=NULL;
		Node_list *tmp=H;
		do
		{
			if(tmp->Adr_ITAD!=IT_Found)
				tmp=tmp->Adr_ITAD;
		}
		while(tmp->Adr_ITAD!=IT_Found);
		tmp->Adr_ITAD=H;
		return Delete_Node(H, info);
	}
	Node_list *tmp=H;
	while(tmp->Adr_ITAD!=IT_Found)
		tmp=tmp->Adr_ITAD;
	tmp->Adr_ITAD=IT_Found->Adr_ITAD;
	IT_Found->Adr_ITAD=NULL;
	return Delete_Node(H, info);
}

Node_list *list_A(Node_list *H)
{
	if(H==NULL)
		return NULL;
	Node_list *Head=NULL, *tmp=H, *p;
	do
	{
		if(tmp->data.dtb <5)
		{
			Node_list *IT=new Node_list;
			IT->data=tmp->data;
			IT->Adr_ITAD=Head;
			Head=Add_AF(Head,IT);
			p=IT;
		}
	}
	while(tmp!=H);
	return Head;	
}

Node_list *list_B(Node_list *H)
{
	if(H==NULL)
		return NULL;
	Node_list *Head=NULL, *tmp=H,*P;
	do
	{
		if(tmp->data.dtb>=5)
		{Node_list *IT=new Node_list;
			IT->data=tmp->data;
			IT->Adr_ITAD=Head;
			Head=Add_AF(Head,IT);		
		}
	tmp=tmp->Adr_ITAD;
	}
	while(tmp!=H);
	return Head;
}

main()
{
	Node_list *HD, *HDA, *HDB;
	int n;
	char k[10];
	
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	HD=NHAP(NULL,n);
	display(HD);
	
	fflush(stdin);
	printf("\n Xoa cac sinh vien lop: ");
	gets(k);
	HD=Delete_Node(HD,k);
	printf("\n danh sach sinh vien con lai: ");
	display(HD);
	
	HDA=list_A(HD);
	printf("\n danh sach sv co diem tb<5: ");
	display(HDA);
	
	HDB=list_B(HD);
	printf("\n danh sach sv co diem tb>=5: ");
	display(HDB);
}
