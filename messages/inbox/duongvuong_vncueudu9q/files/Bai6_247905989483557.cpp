#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node_List {
	int data;
	Node_List *Adr_ItAf;	
};

Node_List *Add_It(Node_List *H, Node_List *p)
{
	if(H==NULL)
		H=p;
	else
	{
		Node_List *tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=p;
		return H;
	}
}

int Search_It(Node_List *H,int n)
{
	Node_List *tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data==n)
			return 1;
		tmp=tmp->Adr_ItAf;
	}
	return 0;
}

Node_List *Input(Node_List *H,int n)
{
	srand((int)time(0));
	for(int i=1;i<=n;++i)
	{
		fflush(stdin);
		Node_List *It=new Node_List;
		do
		{
			It->data=rand()%n+1;
		}
		while(Search_It(H,It->data)==1);
		It->Adr_ItAf=NULL;
		H=Add_It(H,It);
	}
	return H;
}

void display(Node_List *H)
{
	Node_List *tmp=H;
	if(H==NULL)
		printf("\n\nDanh sach NULL\n\n");
	while(tmp!=NULL)
	{
		printf("[%d] ",tmp->data);
		tmp=tmp->Adr_ItAf;
	}
}

main()
{
	Node_List *Hd;
	int n;
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	Hd=Input(NULL,n);
	display(Hd);
}
