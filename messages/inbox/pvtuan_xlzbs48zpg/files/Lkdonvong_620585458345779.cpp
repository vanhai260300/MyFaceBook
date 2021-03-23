#include <stdio.h>
#include <string.h>

struct SinhVien {
	char masv[15], tensv[17], lop[8];
	float dtb;
};

struct Node_List {
	SinhVien data;
	Node_List *Adr_ItAf;
};

Node_List *Add_Af(Node_List *H, Node_List *p)
{
	if(H==NULL)
	{
		H=p;
		p->Adr_ItAf=H;
	}
	else
		{
			Node_List *tmp=H;
			while(tmp->Adr_ItAf!=H)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=p;
		}
	return H;
}

Node_List *Input(Node_List *H,int n)
{
	Node_List *p;
	for(int i=1;i<=n;++i)
	{
		fflush(stdin);
		Node_List *It= new Node_List;
		printf("\nSinh vien thu %d: " ,i);
		printf("\nNhap ma sinh vien: ");
		gets(It->data.masv);
		printf("Nhap ten sinh vien: ");
		gets(It->data.tensv);
		printf("Nhap lop sinh vien: ");
		gets(It->data.lop);
		printf("Nhap diem trung binh: ");
		scanf("%f" ,&It->data.dtb);
		It->Adr_ItAf=H;
		H=Add_Af(H,It);
	}
	return H;
}

void display(Node_List *H)
{
	Node_List *tmp=H;
	if(H==NULL)
		printf("\n\nDanh sach NULL\n\n");
	else
		do
		{
			printf("\n\n| %15s | %17s | %8s | %4.2f |" ,tmp->data.masv ,tmp->data.tensv ,tmp->data.lop ,tmp->data.dtb) ;
			tmp=tmp->Adr_ItAf;
		}
		while(tmp!=H);
}

Node_List *Search_It(Node_List *H,char info[])
{
	Node_List *tmp=H;
	do
	{
		if(strcmp(tmp->data.lop,info)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	while(tmp!=H);
	return NULL;			
}

Node_List *Del_Node(Node_List *H, char info[])
{
	Node_List *It_Found=Search_It(H,info);
	if(It_Found==NULL)
		return H;
	if(H->Adr_ItAf==H)
		return NULL;
	if(It_Found==H)
		{
			H=H->Adr_ItAf;
			It_Found->Adr_ItAf=NULL;
			Node_List *tmp=H;
			do
			{
				if(tmp->Adr_ItAf!=It_Found)
					tmp=tmp->Adr_ItAf;
			}
			while(tmp->Adr_ItAf!=It_Found);
			tmp->Adr_ItAf=H;
			return Del_Node(H,info);
		}
	Node_List *tmp=H;
	while(tmp->Adr_ItAf!=It_Found)
		tmp=tmp->Adr_ItAf;
	tmp->Adr_ItAf=It_Found->Adr_ItAf;
	It_Found->Adr_ItAf=NULL;
	return Del_Node(H,info);
}

Node_List *List_1(Node_List *H)
{
	if(H==NULL)
		return NULL;
	Node_List *Head=NULL,*tmp=H,*p;
	do
	{
		if(tmp->data.dtb<5)
			{
				Node_List *It=new Node_List;
				It->data=tmp->data;
				It->Adr_ItAf=Head;
				Head=Add_Af(Head,It);
				p=It;
			}
		tmp=tmp->Adr_ItAf;
	}
	while(tmp!=H);
	return Head;
}


Node_List *List_2(Node_List *H)
{
	if(H==NULL)
		return NULL;
	Node_List *Head=NULL,*tmp=H,*p;
	do
	{
		if(tmp->data.dtb>=5)
			{
				Node_List *It=new Node_List;
				It->data=tmp->data;
				It->Adr_ItAf=Head;
				Head=Add_Af(Head,It);
			}
		tmp=tmp->Adr_ItAf;
	}
	while(tmp!=H);
	return Head;
}

main()
{
	Node_List *Hd,*Hd1,*Hd2;
	int n;
	char l[10];
	
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	Hd= Input(NULL,n)	;
	display(Hd);
	
	fflush(stdin);
	printf("\n\nNhap lop co sinh vien muon xoa: ");
	gets(l);
	Hd=Del_Node(Hd,l);
	display(Hd);
	
	Hd1=List_1(Hd);
	printf("\n\n\n Danh sach sinh vien dtb <5 \n\n");
	display(Hd1);
	
	Hd2=List_2(Hd);
	printf("\n\n\n Danh sach sinh vien dtb >=5 \n\n");
	display(Hd2);
	
}
