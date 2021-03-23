#include<stdio.h>
#include<string.h>

struct SV{
	char masv[15] ,tensv[20],lop[10];
	float dtb;
};

struct Node_list{
	SV data;
	Node_list *Adr_ITAD;
};

Node_list *ADD_AF(Node_list *H, Node_list *p)
{
	if(H==NULL)
		H=p;
	else
		{
			Node_list *tmp=H;
			while(tmp->Adr_ITAD!=NULL)
				tmp=tmp->Adr_ITAD;
			tmp->Adr_ITAD=p;
		}
	return H;
}

Node_list *NHAP(Node_list *H, int n)
{
	for(int i=1;i<=n;i++)
	{
		fflush(stdin);
		Node_list *IT=new Node_list;
		printf("\n Nhap sinh vien thu %d: ",i);
		printf("\n Nhap ma sinh vien:");
		gets(IT->data.masv);
		printf(" Nhap ten sinh vien: ",i);
		gets(IT->data.tensv);
		printf(" Nhap lop sinh vien: ",i);
		gets(IT->data.lop);
		printf(" Nhap diem trung binh: ",i);
		scanf("%f",&IT->data.dtb);
		IT->Adr_ITAD=NULL;
		H=ADD_AF(H,IT);
	}
	return H;
}

void XUAT(Node_list *H)
{	
	Node_list *tmp=H;
	printf("\n            MA sv  |    Ten sv       | Lop sv     | DTB");
	if(H=NULL)	
		printf("\n\nDanh sach NULL\n\n");	
	while(tmp!=NULL)
	{	
		printf("\n\n  |%15s | %15s | %10s | %4.2f", 
		tmp->data.masv,tmp->data.tensv,tmp->data.lop,tmp->data.dtb);
		tmp=tmp->Adr_ITAD;
	}		
			
}

Node_list *TimKiem_Node(Node_list *H, char info[])
{
	Node_list *tmp=H;
	while(tmp!=NULL)
	{
		if(strcmp(tmp->data.lop,info)==0)
			return tmp;
		tmp=tmp->Adr_ITAD;
	}
	return NULL;
}
Node_list *XOA_Node(Node_list *H, char info[])
{
	Node_list *IT_Found=TimKiem_Node(H, info);
	if(IT_Found==NULL)
		return H;
	if(IT_Found==H)
	{
		H=H->Adr_ITAD;
		IT_Found->Adr_ITAD=NULL;
		return XOA_Node(H,info);
	}
	Node_list *tmp=H;
	while(tmp->Adr_ITAD!=IT_Found)
		tmp=tmp->Adr_ITAD;
	tmp->Adr_ITAD=IT_Found->Adr_ITAD;
	IT_Found->Adr_ITAD=NULL;
	return XOA_Node(H,info);
}

Node_list *List_A(Node_list *H)
{
	Node_list *Head=NULL, *tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data.dtb<5)
			{
				Node_list *p=new Node_list;
				p->data=tmp->data;
				p->Adr_ITAD=NULL;
				Head=ADD_AF(Head,p);
			}
		tmp=tmp->Adr_ITAD;
	}
	return Head;
}

Node_list *List_B(Node_list *H)
{
	Node_list *Head=NULL, *tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data.dtb>=5)
		{
			Node_list *p=new Node_list;
			p->data=tmp->data;
			p->Adr_ITAD=NULL;
			Head=ADD_AF(Head,p);
		}
		tmp=tmp->Adr_ITAD;
	}
	return Head;
}

main()
{
	Node_list *HD, *HDA,*HDB;
	int n;
	char k[10];
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	HD=NHAP(NULL,n);
	XUAT(HD);
	
	fflush(stdin);
	printf("\n Nhap lop co sinh vien muon xoa: ");
	gets(k);
	HD=XOA_Node(HD, k);
	XUAT(HD);
	
	HDA=List_A(HD);
	printf("\n Danh sach sinh vien co diem trung binh <5 ");
	XUAT(HDA);
	
	HDB=List_B(HD);
	printf("\n Danh sach sinh vien co diem trung binh >=5 ");
	XUAT(HDB);
}

