#include<stdio.h>
struct Node_BnTr{
	int data;
	Node_BnTr *L,*R;
};
Node_BnTr *Add(Node_BnTr *Tr, Node_BnTr *node)
{
	Node_BnTr *tmp, *TMP;
	if(Tr==NULL)
		Tr=node;
	else
	{
		tmp=Tr;
		while(tmp!=NULL)
		{
			TMP=tmp;
			if(tmp->data>node->data)
				tmp=tmp->L;
			else
				tmp=tmp->R;
		}
		if(TMP->data>node->data)
			TMP->L=node;
		else
			TMP->R=node;		
	}
	return Tr;
}
Node_BnTr *Input(Node_BnTr *Tr, int n)
{
	Node_BnTr *p;
	for(int i=1;i<=n;i++)
	{
		p=new Node_BnTr;
		printf("Nhap Phan Tu Thu %d: ",i);
		scanf("%d",&p->data);
		p->L=NULL;
		p->R=NULL;
		Tr=Add(Tr,p);		
	}
	return Tr;
}
void BRW(Node_BnTr *Tr)
{
	if(Tr!=NULL)
	{
		BRW(Tr->R);
		BRW(Tr->L);
		printf("%d\t",Tr->data);	
	}	
}
Node_BnTr *Search(Node_BnTr *Tr,int x)
{
	Node_BnTr *tmp;
	if(Tr==NULL)
		return NULL;
	else
	{
		tmp=Tr;
		while(tmp!=NULL&&tmp->data!=x)
			if(tmp->data>x)
				tmp=tmp->L;
			else
				tmp=tmp->R;
		if(tmp!=NULL)
			return tmp;
		else
			return NULL;
	}
}
Node_BnTr *Delete(Node_BnTr *Tr, int x)
{
	Node_BnTr *tmp,*R,*t,*L;
	while(Search(Tr,x)!=NULL)
	{
		tmp=search(Tr,x);
		if(tmp==Tr)
		{
			if(tmp->L!=NULL)
			{
				R=Tr->R;
				Tr=Tr->L;
				tmp->L=NULL;
				tmp->R=NULL;
				tmp=Tr;
				while(tmp->R!=NULL)
					tmp=tmp->R;
				tmp->R=R;
			}
			else
			{
				T=Tr->R;
				tmp->R=NULL;
			}
		}
		else
		{
			t=Tr;
			while(t->R!=tmp&&t->L=tmp)
				if(t->data>x)
		}
	}
}
main()
{
	Node_BnTr *Tree;
	Tree=NULL;
	int spt;
	printf("Nhap so phan tu: ");
	scanf("%d",&spt);
	Tree=Input(Tree,spt);
	printf("cay da nhap la: ");
	BRW(Tree);
	
}
