#include<stdio.h>
#include<string.h>
struct Node_BnTr_09{
	char ten_09[1];
	Node_BnTr_09 *Adr_TrL_09, *Adr_TrR_09;
};
Node_BnTr_09 *Add_Node_09(Node_BnTr_09 *Tr_09, Node_BnTr_09 *node_09)
{
	Node_BnTr_09 *tmp_09, *TMP_09;
	if(Tr_09==NULL)
		Tr_09=node_09;
	else
	{
		tmp_09=Tr_09;
		while(tmp_09!=NULL)
		{
			TMP_09=tmp_09;
			if(strcmp(tmp_09->ten_09,node_09->ten_09)>0)
				tmp_09=tmp_09->Adr_TrL_09;
			else
				tmp_09=tmp_09->Adr_TrR_09;		
		}
		if(strcmp(TMP_09->ten_09,node_09->ten_09)>0)
			TMP_09->Adr_TrL_09=node_09;
		else
			TMP_09->Adr_TrR_09=node_09;
	}
	return Tr_09;
}
Node_BnTr_09 *Input_09(Node_BnTr_09 *Tr_09, int n_09)
{
	Node_BnTr_09 *p_09;
	for(int i=1;i<=n_09;i++)
	{
		p_09=new Node_BnTr_09;		
		printf("Nhap ten sinh vien thu %d: ",i);
		fflush(stdin);
		gets(p_09->ten_09);
		p_09->Adr_TrL_09=NULL;
		p_09->Adr_TrR_09=NULL;
		Tr_09=Add_Node_09(Tr_09,p_09);
	}
	return Tr_09;
}
void BRW_Node_2(Node_BnTr_09 *Tr)
{
	if(Tr!=NULL)
	{
		printf("%s\t",Tr->ten_09);
		BRW_Node_2(Tr->Adr_TrL_09);		
		BRW_Node_2(Tr->Adr_TrR_09);
	}
}
void BRW_Node_3(Node_BnTr_09 *Tr)
{
	if(Tr!=NULL)
	{		
		BRW_Node_3(Tr->Adr_TrL_09);		
		BRW_Node_3(Tr->Adr_TrR_09);
		printf("%s\t",Tr->ten_09);
	}
}
int Count(Node_BnTr_09 *Tr)
{
	if(Tr==NULL)
		return 0;
	else	
		return 1+Count(Tr->Adr_TrL_09)+Count(Tr->Adr_TrR_09);
	
}

int Search_09(Node_BnTr_09 *Tr_09, char t_09[])
{
	if(Tr_09==NULL)
		return 0;
	if(strcmp(Tr_09->ten_09,t_09)==0)
		return 1+Search_09(Tr_09->Adr_TrR_09,t_09);
	else
		return Search_09(Tr_09->Adr_TrR_09,t_09) + Search_09(Tr_09->Adr_TrL_09,t_09);
	
}
main()
{
	Node_BnTr_09 *Tree_09;
	char T_09[1];
	int spt_09;
	Tree_09=NULL;
	printf("Nhap so sinh vien: ");
	scanf("%d",&spt_09);
	Tree_09=Input_09(Tree_09,spt_09);
	printf("Danh sach vua nhap theo Goc Trai Phai: ");
	BRW_Node_2(Tree_09);
	printf("\nDanh sach nhap theo Trai Phai Goc: ");
	BRW_Node_3(Tree_09);
	printf("\nSo sinh vien: %d",Count(Tree_09));
	printf("\nNhap ten sinh vien can tim: ");
	fflush(stdin);
	gets(T_09);
	printf("Co: %d sinh vien can tim",Search_09(Tree_09,T_09));
	
	
}
