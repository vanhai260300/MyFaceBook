#include<stdio.h>
struct Node{
	int data;
	Node *L_52, *R_52;
};
Node *Add_Node(Node *Tr, Node *node)
{
	Node *tmp, *TMP;
	if(Tr==NULL)
		Tr=node;
	else
	{
		tmp= Tr;
		while(tmp!=NULL)
		{
			TMP= tmp;
			if(tmp->data>node->data)
				tmp=tmp->L_52;
			else
				tmp=tmp->R_52;
		}
		if(TMP->data>node->data)
			TMP->L_52=node;
		else
			TMP->R_52=node;
	}
	return Tr;
}
void Nhap(Node *&Tr)
{
	Tr=NULL;
	int n;
	printf("Nhap bao nhieu so: ");
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		Node *p= new Node;
		printf("Nhap so thu %d: ", i);
		fflush(stdin);
		scanf("%d",&p->data);
		p->L_52=NULL;
		p->R_52=NULL;
		Tr=Add_Node(Tr,p);
	}
}
void In(Node *Tr)
{
	if(Tr!=NULL)
	{
		In(Tr->L_52);
		printf(" %d ",Tr->data);
		In(Tr->R_52);
	}
}
Node *Search(Node *Tr, int info)
{
	Node *tmp;
	if(Tr==NULL)
		return NULL;
	else
	{
		tmp=Tr;
		while(tmp!=NULL && tmp->data!= info)
			if(tmp->data>info)
				tmp=tmp->L_52;
			else
				tmp=tmp->R_52;
		if(tmp!=NULL)
			return tmp;
		else
			return NULL;
	}
}
Node *XoaGoc(Node *Tr, int info)
{
	Node *tmp, *R;
	while(Search(Tr,info)!=NULL)
	{
		tmp=Search(Tr,info);
		if(tmp==Tr)
		{
			if(tmp->L_52!=NULL)
			{
				R=Tr->R_52;
				Tr=Tr->L_52;
				
				tmp->L_52=NULL;
				tmp->R_52=NULL;
				tmp=Tr;
				
				while(tmp->R_52!=NULL)
					tmp=tmp->R_52;
				tmp->R_52=R;
			}
			else
			{
				Tr=Tr->R_52;
				tmp->R_52=NULL;
			}
		}
	}
	return Tr;
}
Node *XoaLa(Node *Tr, int info)
{
	Node *tmp, *t;
	while(Search(Tr,info)!=NULL)
	{
		tmp=Search(Tr,info);
		if(tmp!=Tr)
		{
			t=Tr;
			while(t->L_52!=tmp && t->R_52!=tmp)
			{
				if(t->data>info)
					t=t->L_52;
				else
					t=t->R_52;
			}
			if(tmp->L_52==NULL && tmp->R_52==NULL)
				if(t->R_52==tmp)
					t->R_52=NULL;
				else
					t->L_52=NULL;
		}
	}
	return Tr;
}
Node *CayConKoBenTrai(Node *Tr, int info)
{
	Node *tmp, *t, *R;
	while(Search(Tr,info)!=NULL)
	{
		tmp=Search(Tr,info);
		if(tmp!=Tr)
		{
			t=Tr;
			while(t->L_52!=tmp && t->R_52!=tmp)
			{
				if(t->data>info)
					t=t->L_52;
				else
					t=t->R_52;
			}
			if(tmp->L_52==NULL)
			{
				R=tmp->R_52;
				if(t->L_52==tmp)
					t->L_52=R;
				else
					t->R_52=R;
				tmp->R_52=NULL;
			}	
		}
	}
	return Tr;
}
Node *CayConKoBenPhai(Node *Tr, int info)
{
	Node *tmp, *t, *L;
	while(Search(Tr,info)!=NULL)
	{
		tmp=Search(Tr,info);
		if(tmp!=Tr)
		{
			t=Tr;
			while(t->L_52!=tmp && t->R_52!=tmp)
			{
				if(t->data>info)
					t=t->L_52;
				else
					t=t->R_52;
			}
			if(tmp->R_52==NULL)
			{
				L=tmp->L_52;
				if(t->L_52==tmp)
					t->L_52=L;
				else
					t->R_52=L;
				tmp->L_52=NULL;
			}
		}
	}
	return Tr;
}
Node *CayConCoHaiBen(Node *Tr, int info)
{
	Node *tmp, *t;
	while(Search(Tr,info)!=NULL)
	{
		tmp=Search(Tr,info);
		if(tmp!=Tr)
		{
			t=Tr;
			while(t->L_52!=tmp && t->R_52!=tmp)
			{
				if(t->data>info)
					t=t->L_52;
				else
					t=t->R_52;
			}
			if(t->L_52==tmp)
			{
				t->L_52=tmp->L_52;
				t=t->L_52;
			}
			else
			{
				t->R_52=tmp->L_52;
				t=t->R_52;
			}
			while(t->R_52!=NULL)
				t=t->R_52;
			t->R_52=tmp->R_52;
			tmp->R_52=NULL;
			tmp->L_52=NULL;	
		}
	}
	return Tr;
}
main()
{
	Node *Tree, *Tree1, *Tree2, *Tree3, *Tree4, *Tree5;
	Nhap(Tree);
	In(Tree);
	printf("\n 1. Ham xoa node goc.");
	printf("\n 2. Ham xoa node la.");
	printf("\n 3. Ham xoa node ko co cay con trai.");
	printf("\n 4. Ham xoa node ko co cay con phai.");
	printf("\n 5. Ham xoa node co du 2 cay con.");
	int num;
	while(true)
	{
		printf("\n Nhap so de chom ham: ");
		scanf("%d", &num);
		switch(num)
		{
			case 1:{
				int so;
				printf(" => Nhap node goc can xoa: ");
				scanf("%d", &so);
				Tree=XoaGoc(Tree,so);
				In(Tree);
			};break;
			case 2:{
				int so1;
				printf(" => Nhap node la can xoa: ");
				scanf("%d",&so1);
				Tree=XoaLa(Tree,so1);
				In(Tree);
			};break;
			case 3:{
				int so2;
				printf(" => Nhap node ko co cay con ben trai xoa: ");
				scanf("%d",&so2);
				Tree=CayConKoBenTrai(Tree,so2);
				In(Tree);
			} break;
			case 4: {
				int so3;
				printf(" => Nhap node ko co cay con ben phai xoa: ");
				scanf("%d",&so3);
				Tree=CayConKoBenPhai(Tree,so3);
				In(Tree);
				
			}break;
			case 5:{
				int so4;
				printf(" => Nhap node co du 2 cay con de xoa: ");
				scanf("%d",&so4);
				Tree=CayConCoHaiBen(Tree,so4);
				In(Tree);
			}break;
		}
	}
}
