#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node_BnTr
{
	char hotensv[10],masv[10];
	float dtb;
	Node_BnTr *Adr_TrL,*Adr_TrR;
};
Node_BnTr *Add_Node(Node_BnTr *Tr,Node_BnTr *node)
{
	Node_BnTr *tmp,*TMP;
	if(Tr==NULL)
		Tr=node;
	else
	{
		tmp=Tr;
		while(tmp!=NULL)
		{
			TMP=tmp;
			if(tmp->dtb>node->dtb)
				tmp=tmp->Adr_TrL;
			else
				tmp=tmp->Adr_TrR;
		}
		if(TMP->dtb>node->dtb)
			TMP->Adr_TrL=node;
		else
			TMP->Adr_TrR=node;
	}
	return Tr;
}
void *Add_SV(Node_BnTr *Tr)
{
	fflush(stdin);
	struct Node_BnTr *a=(struct Node_BnTr *)malloc(sizeof(struct Node_BnTr));
	printf("\nNhap ma sinh vien: ");
	gets(a->masv);
	printf("Nhap ten sinh vien: ");
	gets(a->hotensv);
	printf("Nhap diem trung binh: ");
	scanf("%f",&a->dtb);
	a->Adr_TrL=NULL;
	a->Adr_TrR=NULL;
	Tr=Add_Node(Tr,a);
}
int count(Node_BnTr *Tr,float infor)
{
	if(Tr==NULL)
		return 0;
	if(Tr->dtb>=infor)
		return 1+count(Tr->Adr_TrR,infor)+count(Tr->Adr_TrL,infor);
	if(Tr->dtb<infor)	
		return count(Tr->Adr_TrR,infor);
}
void display(Node_BnTr *Tr)
{
	if(Tr!=NULL)
	{
		if(Tr->dtb>=5.5)
			printf("\n%5s | %5s | %5f ",Tr->masv,Tr->hotensv,Tr->dtb);
		display(Tr->Adr_TrR);
	}
}
void BRW_Node_GTP(Node_BnTr *Tr)
{
	if(Tr!=NULL)
	{
		printf("\n%5s | %5s | %5f ",Tr->masv,Tr->hotensv,Tr->dtb);
		BRW_Node_GTP(Tr->Adr_TrL);
		BRW_Node_GTP(Tr->Adr_TrR);
	}
}
Node_BnTr *SEARCH_Tr(Node_BnTr *Tr,float infor)
{
	Node_BnTr *tmp;
	if(Tr==NULL)
		return NULL;
	else
	{
		tmp=Tr;
		while(tmp!=NULL&&tmp->dtb>=infor)
			if(tmp->dtb>infor)
				tmp=tmp->Adr_TrL;
			else
				tmp=tmp->Adr_TrR;
		if(tmp!=NULL)
			return tmp;
		else
			return NULL;
	}
}
Node_BnTr *DELETE_G(Node_BnTr *Tr,float infor)
{
	Node_BnTr *R,*tmp;
	tmp=SEARCH_Tr(Tr,infor);
	if(tmp->Adr_TrL!=NULL)
	{
		R=Tr->Adr_TrR;
		Tr=Tr->Adr_TrL;
		tmp->Adr_TrL=NULL;
		tmp->Adr_TrR=NULL;
		tmp=Tr;
		while(tmp->Adr_TrR!=NULL)
			tmp=tmp->Adr_TrR;
		tmp->Adr_TrR=R;
	}
	else
	{
		Tr=Tr->Adr_TrR;
		tmp->Adr_TrR=NULL;
	}
	return Tr;	
}
Node_BnTr *DELETE_La(Node_BnTr *Tr,float infor)
{
	Node_BnTr *tmp,*t;
	tmp=SEARCH_Tr(Tr,infor);
	t=Tr;
	while(t->Adr_TrR!=tmp&&t->Adr_TrL!=tmp)
		if(t->dtb>infor)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	if(t->Adr_TrR==tmp)
		t->Adr_TrR=NULL;
	else
		t->Adr_TrL=NULL;
	return Tr;
}
Node_BnTr *DELETE_NULL_L(Node_BnTr *Tr,float infor)
{
	Node_BnTr *tmp,*t,*R;
	tmp=SEARCH_Tr(Tr,infor);
	t=Tr;
	while(t->Adr_TrR!=tmp&&t->Adr_TrL!=tmp)
		if(t->dtb>infor)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	R=tmp->Adr_TrR;
	if(t->Adr_TrL==tmp)
		t->Adr_TrL=R;
	else
		t->Adr_TrR=R;
	tmp->Adr_TrR=NULL;
	return Tr;
}
Node_BnTr *DELETE_NULL_R(Node_BnTr *Tr,float infor)
{
	Node_BnTr *tmp,*t,*L;
	tmp=SEARCH_Tr(Tr,infor);
	t=Tr;
	while(t->Adr_TrR!=tmp&&t->Adr_TrL!=tmp)
		if(t->dtb>infor)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	L=tmp->Adr_TrL;
	if(t->Adr_TrL==tmp)
		t->Adr_TrL=L;
	else
		t->Adr_TrR=L;
	tmp->Adr_TrL=NULL;	
	return Tr;
}
Node_BnTr *DELETE_L_R(Node_BnTr *Tr,float infor)
{
	Node_BnTr *tmp,*t;
	tmp=SEARCH_Tr(Tr,infor);
	t=Tr;
	while(t->Adr_TrR!=tmp&&t->Adr_TrL!=tmp)
		if(t->dtb>infor)
			t=t->Adr_TrL;
		else
			t=t->Adr_TrR;
	if(t->Adr_TrL==tmp)
	{
		t->Adr_TrL=tmp->Adr_TrL;
		t=t->Adr_TrL;
	}
	else
	{
		t->Adr_TrR=tmp->Adr_TrL;
		t=t->Adr_TrR;
	}
	while(t->Adr_TrR!=NULL)
		t=t->Adr_TrR;
	t->Adr_TrR=tmp->Adr_TrR;
	tmp->Adr_TrR=NULL;
	tmp->Adr_TrL=NULL;	
	return Tr;
}
Node_BnTr *DELETE(Node_BnTr *Tr,float infor)
{
	Node_BnTr *tmp;
	tmp=SEARCH_Tr(Tr,infor);
	if(tmp==Tr)
		return DELETE_G(Tr,infor);
	else
		if(tmp->Adr_TrL==NULL&&tmp->Adr_TrR==NULL)
			return DELETE_La(Tr,infor);
		else
			if(tmp->Adr_TrL==NULL)
				return DELETE_NULL_L(Tr,infor);
			else
				if(tmp->Adr_TrR==NULL)
					return DELETE_NULL_R(Tr,infor);
				else
					return DELETE_L_R(Tr,infor);
}
main()
{
	Node_BnTr *Tree,*p;
	int i,n,choose;
	printf("Nhap bao nhieu sinh vien: ");
	scanf("%d",&n);
	Tree=NULL;
	for(i=1;i<=n;i++)
	{
		fflush(stdin);
		p=new Node_BnTr;
		printf("Nhap sinh vien thu %d ",i);
		printf("\nNhap ma sinh vien: ");
		gets(p->masv);
		printf("Nhap ten sinh vien: ");
		gets(p->hotensv);
		printf("Nhap diem trung binh: ");
		scanf("%f",&p->dtb);
		p->Adr_TrL=NULL;
		p->Adr_TrR=NULL;
		Tree=Add_Node(Tree,p);
	}
	while(choose!=4)
	{
		printf("\nMENU:");
		printf("\n1.Dem cay co bao nhieu sinh vien co diem trung binh tren 5.5: ");
		printf("\n2.In cay nhi phan nhung sinh vien co diem trung binh tren 5.5: ");
		printf("\n3.Xoa trong cay nhi phan nhung sinh vien co diem trung binh tren 5.5: ");
		printf("\n4.Thoat");
		printf("\nMoi nhap lua chon: ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				printf("\nCay co %d sinh vien co diem trung binh tren 5.5",count(Tree,5.5));
				break;
			case 2:
				printf("\nDanh sach sinh vien co diem trung binh tren 5.5");
				display(Tree);
				break;
			case 3:
				Tree=DELETE(Tree,5.5);
				printf("\nDanh sach sinh vien sau khi xoa: ");
				BRW_Node_GTP(Tree);
				break;
			case 4:
				break;
			default:
				printf("\nNhap sai, moi nhap lai: ");
				break;
		}
	}
}
