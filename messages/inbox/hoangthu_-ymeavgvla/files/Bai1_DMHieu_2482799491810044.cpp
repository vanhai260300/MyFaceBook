#include <stdio.h>

struct Node_List
{
	int data;
	Node_List *Adr_ItAf;
};

Node_List *Add_Af(Node_List *Hd, Node_List *It)
{
	if(Hd==NULL)
		Hd=It;
	else
		{
			Node_List *tmp;
			tmp=Hd;
			while(tmp->Adr_ItAf!=NULL)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=It;
		}
	return Hd;
}

main()
{
	int n;
	Node_List *Hd,*It,*tmp;
	Hd=NULL;
	printf("Nhap so ptu: ");
	scanf("%d" ,&n);
	for(int i=1;i<=n;++i)
	{
		It= new Node_List;
		printf("Nhap so thu %d: " ,i);
		scanf("%d" ,&It->data);
		if(It->data==0)
			break;
		It->Adr_ItAf=NULL;
		Hd=Add_Af(Hd,It);
	}
	tmp=Hd;
	while(tmp!=NULL)
		{
			printf("\t%d\t " ,tmp->data);
			tmp=tmp->Adr_ItAf;	
		}	
}
