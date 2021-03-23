#include<stdio.h>
#include<string.h>
struct Node_BnTr_61
{
	int data_61;
	Node_BnTr_61 *Adr_TrL_61, *Adr_TrR_61;
};
Node_BnTr_61 *Add_Node(Node_BnTr_61 *Tr_61, Node_BnTr_61 *Node_61)
{
	Node_BnTr_61 *tmp_61, *TMP_61;
	if(Tr_61==NULL)
		Tr_61=Node_61;
	else
	{
		tmp_61=Tr_61;
		while(tmp_61!=NULL)
		{
			TMP_61=tmp_61;
			if(tmp_61->data_61>Node_61->data_61)
				tmp_61=tmp_61->Adr_TrL_61;
			else
				tmp_61=tmp_61->Adr_TrR_61;
		}
		if(TMP_61->data_61>Node_61->data_61)
			TMP_61->Adr_TrL_61=Node_61;
		else
			TMP_61->Adr_TrR_61=Node_61;	
		}
		
	return Tr_61;
}
Node_BnTr_61 *Input(Node_BnTr_61 *Tr_61)
{
	Node_BnTr_61 *p_61;
	printf("Nhap so nut cua cay T: ");
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		p_61 = new Node_BnTr_61;
		printf("Nhap nut thu %d: ",i);
		scanf("%d", &p_61->data_61);
		p_61 -> Adr_TrL_61 = NULL;
		p_61 -> Adr_TrR_61 = NULL;
		Tr_61 = Add_Node(Tr_61, p_61 );
	}
	return Tr_61;
}
void Out(Node_BnTr_61 *Tr_61)
{
	if(Tr_61!=NULL)
	{
		Out(Tr_61->Adr_TrL_61);
		printf(" %d", Tr_61->data_61);
		Out(Tr_61->Adr_TrR_61);
	}
}
//Dem so nut trong cay
int dem(Node_BnTr_61 *Tr_61)
{
	if(Tr_61==NULL)
		return 0;
	else
		return 1 + dem(Tr_61->Adr_TrL_61) + dem(Tr_61->Adr_TrR_61);
}
//Tim kiem tra ve con tro
Node_BnTr_61 *search(Node_BnTr_61 *Tr_61, int info)
{
	Node_BnTr_61 *tmp_61;
	if(Tr_61==NULL)
		return NULL;
	else
	{
		tmp_61=Tr_61;
		while(tmp_61!=NULL && tmp_61->data_61!=info)
		{
			if(tmp_61->data_61>info)
				tmp_61=tmp_61->Adr_TrL_61;
			else
				tmp_61=tmp_61->Adr_TrR_61;
		}
		if(tmp_61!=NULL)
			return tmp_61;
		else
			return NULL;	
	}
}
//Xoa nut goc
Node_BnTr_61 *deleteG(Node_BnTr_61 *Tr_61, int info)
{
	Node_BnTr_61 *tmp_61, *R;
	while(search(Tr_61,info)!=NULL)
	{
		tmp_61=search(Tr_61,info);
		if(Tr_61==tmp_61)
		{
			if(tmp_61->Adr_TrL_61!=NULL)
			{
				R=Tr_61->Adr_TrR_61;
				Tr_61=Tr_61->Adr_TrL_61;
				tmp_61->Adr_TrL_61=NULL;
				tmp_61->Adr_TrR_61=NULL;
				tmp_61=Tr_61;
				while(tmp_61->Adr_TrR_61!=NULL)
					tmp_61=tmp_61->Adr_TrR_61;
				tmp_61->Adr_TrR_61=R;
			}
			else
			{
			Tr_61=Tr_61->Adr_TrR_61;
			tmp_61->Adr_TrR_61=NULL;
			}	
		}
	}
	return Tr_61;
}
//Xoa nut la
Node_BnTr_61 *deleteL(Node_BnTr_61 *Tr_61, int info)
{
	Node_BnTr_61 *tmp_61, *t_61;
	while(search(Tr_61,info)!=NULL)
	{
		tmp_61=search(Tr_61,info);
		if(tmp_61!=Tr_61)
		{
			t_61=Tr_61;
			while(t_61->Adr_TrR_61!=tmp_61 && t_61->Adr_TrL_61!=tmp_61)
			{
				if(t_61->data_61>info)
					t_61=t_61->Adr_TrL_61;
				else
					t_61=t_61->Adr_TrR_61;
			}
			if(tmp_61->Adr_TrL_61==NULL && tmp_61->Adr_TrR_61==NULL)
				if(t_61->Adr_TrR_61==tmp_61)
					t_61->Adr_TrR_61=NULL;
				else
					t_61->Adr_TrL_61=NULL;	
		}
	}
	return Tr_61;
}
//Xoa nut ko co cay con ben trai
Node_BnTr_61 *deleteNotL(Node_BnTr_61 *Tr_61, int  info)
{
	Node_BnTr_61 *tmp_61, *t_61, *R_61;
	while(search(Tr_61, info)!=NULL)
	{
		tmp_61=search(Tr_61, info);
		if(tmp_61!=Tr_61)
		{
			t_61=Tr_61;
			while(t_61->Adr_TrR_61!=tmp_61 && t_61->Adr_TrL_61!=tmp_61)
			{
				if(t_61->data_61>info)
					t_61=t_61->Adr_TrL_61;
				else
					t_61=t_61->Adr_TrR_61;
			}
			if(tmp_61->Adr_TrR_61!=NULL && tmp_61->Adr_TrL_61==NULL)
			{ 
				R_61=tmp_61->Adr_TrR_61;
				if(t_61->Adr_TrL_61==tmp_61)
					t_61->Adr_TrL_61=R_61;
				else
					t_61->Adr_TrR_61=R_61;
				tmp_61->Adr_TrR_61=NULL;
			}	
		}
	}
	return Tr_61;
}
//Xoa nut khong co cay con ben phai
Node_BnTr_61 *deleteNotR(Node_BnTr_61 *Tr_61, int info)
{
	Node_BnTr_61 *tmp_61, *t_61, *L_61;
	while(search(Tr_61,info)!=NULL)
	{
		tmp_61=search(Tr_61,info);
		if(tmp_61!=Tr_61)
		{
			t_61=Tr_61;
			while(t_61->Adr_TrR_61!=tmp_61 && t_61->Adr_TrL_61!=tmp_61)
			{
				if(t_61->data_61>info)
					t_61=t_61->Adr_TrL_61;
				else
					t_61=t_61->Adr_TrR_61;
			}
			if(tmp_61->Adr_TrR_61==NULL && tmp_61->Adr_TrL_61!=NULL)
			{
				L_61=tmp_61->Adr_TrL_61;
				if(t_61->Adr_TrL_61==tmp_61)
					t_61->Adr_TrL_61=L_61;
				else
					t_61->Adr_TrR_61=L_61;
				tmp_61->Adr_TrL_61=NULL;
			}
			else
				return Tr_61;
			
		}
		else
			return Tr_61;
	}
	return Tr_61;
}
//Xoa nut co cay con ben phai va ben trai
Node_BnTr_61 *deleteLR(Node_BnTr_61 *Tr_61, int info)
{
	Node_BnTr_61 *tmp_61, *t_61;
	while(search(Tr_61,info)!=NULL)
	{
		tmp_61=search(Tr_61,info);
		if(tmp_61!=Tr_61)
		{
			t_61=Tr_61;
			while(t_61->Adr_TrR_61!=tmp_61 && t_61->Adr_TrL_61!=tmp_61)
				if(t_61->data_61>info)
					t_61=t_61->Adr_TrL_61;
				else
					t_61=t_61->Adr_TrR_61;
			if(tmp_61->Adr_TrL_61!=NULL && tmp_61->Adr_TrR_61!=NULL)
			{
				if(t_61->Adr_TrL_61==tmp_61)
				{
					t_61->Adr_TrL_61=tmp_61->Adr_TrL_61;
					t_61=t_61->Adr_TrL_61;
				}
				else
				{
					t_61->Adr_TrR_61=tmp_61->Adr_TrL_61;
					t_61=t_61->Adr_TrL_61;
				}
				while(t_61->Adr_TrR_61!=NULL)
					t_61=t_61->Adr_TrR_61;
				t_61->Adr_TrR_61=tmp_61->Adr_TrR_61;
				tmp_61->Adr_TrR_61=NULL;
				tmp_61->Adr_TrL_61=NULL;	
			}
		}
	}
	return Tr_61;
}
void TB(Node_BnTr_61 *Tr_61, int d)
{
	if(dem(Tr_61)<d)
	{
		//d=dem(Tr_61);
		printf("\nCay da xoa\n");
		Out(Tr_61);	
	}
	else
		printf("\nSo can xoa khong hop le");
	printf("\n");
}
main()
{
	int d,G,L,NotL,NotR,LR,choice,dung;
	Node_BnTr_61 *Tree_61;
	Tree_61=NULL;
	Tree_61=Input(Tree_61);
	Out(Tree_61);
	printf("\nSo nut trong cay la: %d",dem(Tree_61));
	//d=dem(Tree_61);
	while(dung!=1)
	{
		d=dem(Tree_61);
		//printf("\nMoi lua chon choice tu 1 den 6");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi nhap nut goc can xoa: ");
				scanf("%d", &G);
				Tree_61=deleteG(Tree_61,G);
				TB(Tree_61,d);
				break;
			case 2:
				printf("Moi nhap nut la can xoa: ");
				scanf("%d", &L);
				Tree_61=deleteL(Tree_61,L);
				TB(Tree_61,d);
				break;
			case 3:
				printf("Moi nhap nut khong co cay con ben trai: ");
				scanf("%d", &NotL);
				Tree_61=deleteNotL(Tree_61,NotL);
				TB(Tree_61,d);
				break;
			case 4:
				printf("Moi nhap nut khong co cay con ben phai: ");
				scanf("%d", &NotR);
				Tree_61=deleteNotR(Tree_61,NotR);
				TB(Tree_61,d);
				break;
			case 5:
				printf("Moi nhap nut co cay con ben trai va ben phai: ");
				scanf("%d", &LR);
				Tree_61=deleteLR(Tree_61,LR);
				TB(Tree_61,d);
				break;
			case 6:
				dung=1;
				printf("Exit");
				
		}
	}
	
}

	
	
	
	
	
	
	
	
	
	
	

