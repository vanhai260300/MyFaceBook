#include<stdio.h>
#include<String.h>
   struct SinhVien{
   	     char msv[3],tensv[12],lop[5];
   	     float dtb;
   };
   struct Node_BnTr{
   	  SinhVien data;
   	  Node_BnTr *Adr_TrL,*Adr_TrR;
   };
Node_BnTr*Add_Node(Node_BnTr*Tr,Node_BnTr*node)
{
	Node_BnTr*tmp,*TMP;
	if(Tr==NULL)
	  Tr=node;
	else
	{
	  tmp=Tr;
	  while(tmp!=NULL)
	  {
	  	TMP=tmp;
	  	if(tmp->data.dtb>node->data.dtb)
	  	    tmp=tmp->Adr_TrL;
	  	else
	  	    tmp=tmp->Adr_TrR;
	  }
	  if(TMP->data.dtb>node->data.dtb)
	     TMP->Adr_TrL=node;
	  else
	     TMP->Adr_TrR=node;
	}
	return Tr;	     
}
Node_BnTr*Input(Node_BnTr*Tr)
{
	Node_BnTr*p;
	int n,i;
	printf("Nhap so sinh vien : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=new Node_BnTr;
		printf("Nhap thong tin sv : ");
		printf("\n Nhap ma sinh vien : ");
		fflush(stdin);
		gets(p->data.msv);
		printf("\n Nhap ho ten sinh vien : ");
		gets(p->data.tensv);
		printf("\n Nhap lop cua sinh vien : ");
		gets(p->data.lop);
		printf("\n Nhap diem trung binh : ");
		scanf("%f",&p->data.dtb);
		p->Adr_TrL=NULL;
		p->Adr_TrR=NULL;
		Tr=Add_Node(Tr,p);
	}
	return Tr;
}
void Out(Node_BnTr*Tr)
{
	if(Tr!=NULL)
	{
		Out(Tr->Adr_TrL);
		printf(" %3s || %12s || %5s || %0.2f \n",Tr->data.msv,Tr->data.tensv,Tr->data.lop,Tr->data.dtb);
		Out(Tr->Adr_TrR);
	}
}
void Outdtb(Node_BnTr*Tr)
{
	if(Tr!=NULL)
	{
		Outdtb(Tr->Adr_TrL);
		if(Tr->data.dtb>5.5)
		    printf(" %3s || %12s || %5s || %0.2f \n",Tr->data.msv,Tr->data.tensv,Tr->data.lop,Tr->data.dtb);
		Outdtb(Tr->Adr_TrR);
	}
}
int Demdtb(Node_BnTr*Tr)
{
	if(Tr==NULL)
	  return 0;
	if(Tr->data.dtb>5.5)
	  return 1+Demdtb(Tr->Adr_TrL) + Demdtb(Tr->Adr_TrR);
	else
	  return Demdtb(Tr->Adr_TrL)+Demdtb(Tr->Adr_TrR);
	  
}
main()
{
	Node_BnTr*Tree,p;
	Tree=NULL;
	Tree=Input(Tree);
	Out(Tree);
	printf("so sinh vien co dtb lon hon 5,5 la : %d",Demdtb(Tree));
	printf("\nDanh sach co dtb lon hon 5,5 la : \n");
	Outdtb(Tree);
    Tree=Input(Tree);
    Out(Tree);
}
