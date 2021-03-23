#include <stdio.h>

struct Node_List
{
	int soMu, coSo;
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
		printf("Nhap co so cua ptu %d: " ,i);
		scanf("%d" ,&It->coSo);
		printf("Nhap so mu cua ptu %d:" ,i);
		scanf("%d" ,&It->soMu);
		printf("\n");
		It->Adr_ItAf=NULL;
		Hd=Add_Af(Hd,It);
	}
	tmp=Hd;
	while(tmp!=NULL)
		{
			if(tmp->coSo%2==0)
				printf(" (%dX)^%d + " ,tmp->coSo ,tmp->soMu);
			tmp=tmp->Adr_ItAf;
		}	
	printf("0");
}
