#include <stdio.h>
struct NodeList{
	int Data_29;
	NodeList *L_29, *R_29;
};
NodeList *Add_Node(NodeList *Tr_29, NodeList *Node_29)
{
	if(Tr_29==NULL)
		Tr_29=Node_29;
	else
	{
		NodeList *tmp_29=Tr_29, *TMP_29;
		while(tmp_29!=NULL)
		{
			TMP_29=tmp_29;
			if(tmp_29->Data_29>Node_29->Data_29)
				tmp_29=tmp_29->L_29;
			else
				tmp_29=tmp_29->R_29;
		}
		if(TMP_29->Data_29>Node_29->Data_29)
			TMP_29->L_29=Node_29;
		else
			TMP_29->R_29=Node_29;
	}	
	return Tr_29;
}
NodeList *Input(NodeList *Tr_29, int n_29)
{
	for(int i=1;i<=n_29;++i)
	{
		fflush(stdin);
		NodeList *Node_29= new NodeList();
		printf("\n Nhap so thu %d: " ,i);
		scanf("%d" ,&Node_29->Data_29);
		Node_29->L_29=NULL;
		Node_29->R_29=NULL;
		Tr_29=Add_Node(Tr_29,Node_29);
	}
	return Tr_29;
}
void display(NodeList *Tr_29)
{
	if(Tr_29!=NULL)
	{
		display(Tr_29->L_29);
		printf(" %d ",Tr_29->Data_29);
		display(Tr_29->R_29);
	}
}
NodeList *Search_Tr(NodeList *Tr_29,int info)
{
	if(Tr_29==NULL)
		return NULL;
	else
	{
		NodeList *tmp_29=Tr_29;
		while(tmp_29!=NULL && tmp_29->Data_29!=info)
		{
			if(tmp_29->Data_29>info)
				tmp_29=tmp_29->L_29;
			else
				tmp_29=tmp_29->R_29;
		}
		if(tmp_29!=NULL)
			return tmp_29;
		else
			return NULL;
	}
}
NodeList *XoaGoc(NodeList *Tr_29, NodeList *tmp_29)
{
	NodeList *R_29;
	if(tmp_29->L_29!=NULL)
	{
		Tr_29=Tr_29->L_29;
		R_29=tmp_29->R_29;
		tmp_29->L_29=NULL;
		tmp_29->R_29=NULL;
		NodeList *tmp_29=Tr_29;
		while(tmp_29->R_29!=NULL)
			tmp_29=tmp_29->R_29;
		tmp_29->R_29=R_29;			
	}
	else
	{
		Tr_29=tmp_29->R_29;
		tmp_29->R_29=NULL;
	}
	return Tr_29;
}
NodeList *XoaLa(NodeList *Tr_29, NodeList *tmp_29)
{
	NodeList *t_29=Tr_29;
	while(t_29->L_29!=tmp_29 && t_29->R_29!=tmp_29)
	{
		if(t_29->Data_29>tmp_29->Data_29)
			t_29=t_29->L_29;
		else
			t_29=t_29->R_29;
	}
	if(t_29->L_29==tmp_29)
		t_29->L_29=NULL;
	else
		t_29->R_29=NULL;
	return Tr_29;
}

NodeList *XoaKoL(NodeList *Tr_29, NodeList *tmp_29)
{
	NodeList *t_29=Tr_29;
	while(t_29->L_29!=tmp_29 && t_29->R_29!=tmp_29)
	{
		if(t_29->Data_29>tmp_29->Data_29)
			t_29=t_29->L_29;
		else
			t_29=t_29->R_29;
	}
	if(t_29->L_29==tmp_29)
		t_29->L_29=tmp_29->R_29;
	else
		t_29->R_29=tmp_29->R_29;
	tmp_29->L_29=NULL;
	tmp_29->R_29=NULL;
	return Tr_29;
}

NodeList *XoaKoR(NodeList *Tr_29, NodeList *tmp_29)
{
	NodeList *t_29=Tr_29;
	while(t_29->L_29!=tmp_29 && t_29->R_29!=tmp_29)
	{
		if(t_29->Data_29>tmp_29->Data_29)
			t_29=t_29->L_29;
		else
			t_29=t_29->R_29;
	}
	if(t_29->L_29==tmp_29)
		t_29->L_29=tmp_29->L_29;
	else
		t_29->R_29=tmp_29->L_29;
	tmp_29->L_29=NULL;
	tmp_29->R_29=NULL;
	return Tr_29;
}
NodeList *XoaCoLR(NodeList *Tr_29, NodeList *tmp_29)
{
	NodeList *t_29=Tr_29;
	while(t_29->L_29!=tmp_29 && t_29->R_29!=tmp_29)
	{
		if(t_29->Data_29>tmp_29->Data_29)
			t_29=t_29->L_29;
		else
			t_29=t_29->R_29;
	}
	if(t_29->L_29==tmp_29)
	{
		t_29->L_29=tmp_29->L_29;
		t_29=t_29->L_29;	
	}
	else{
		t_29->R_29=tmp_29->L_29;
		t_29=t_29->R_29;	
	}
	while(t_29->R_29!=NULL)
		t_29=t_29->R_29;
	t_29->R_29=tmp_29->R_29;
	tmp_29->L_29=NULL;
	tmp_29->R_29=NULL;
	return Tr_29;
}
NodeList *Xoa(NodeList *Tr_29, int info)
{
	NodeList *tmp_29= Search_Tr(Tr_29,info);
	if(tmp_29==Tr_29)
		Tr_29=XoaGoc(Tr_29,tmp_29);
	else
	{
		if(tmp_29->L_29==NULL && tmp_29->R_29==NULL)
			Tr_29=XoaLa(Tr_29,tmp_29);
		else{
			if(tmp_29->L_29!=NULL && tmp_29->R_29!=NULL)
				Tr_29=XoaCoLR(Tr_29,tmp_29);
			else {
				if(tmp_29->L_29!=NULL && tmp_29->R_29==NULL)
					Tr_29=XoaKoR(Tr_29,tmp_29);		
				else
					Tr_29=XoaKoL(Tr_29,tmp_29);
			}
		}
	}
	return Tr_29;
}
main()
{
	NodeList *Tr_29,*c;
	int n_29,info;
	printf(" Nhap so phan tu: ");
	scanf("%d" ,&n_29);
	Tr_29=Input(NULL,n_29);
	printf("\n");
	display(Tr_29);
	printf("\n\nNhap so can xoa: ");
	scanf("%d" ,&info);
	Tr_29=Xoa(Tr_29,info);
	printf("\n");
	display(Tr_29);
}
