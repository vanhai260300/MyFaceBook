#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#include<map>
struct Node_List_1
{
		int Data;
		Node_List_1 *Adr_ItAf;
		
};
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
Node_List_1 *Add_Af(Node_List_1 *H,Node_List_1 *It)
{
		Node_List_1 *tmp;
		if(H==NULL)
			H=It;
		else
		{
			tmp=H;
			while(tmp->Adr_ItAf != NULL)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=It;
		}
		return H;
}
void BRW_IT(Node_List_1 *H)
{
	Node_List_1 *tmp;
	if (H==NULL)
	printf("Danh Sach NULL");
	else
	{
		tmp=H;
		while (tmp != NULL)
		{
			printf("%d ",tmp->Data);
			tmp=tmp->Adr_ItAf;
		}
	}
}
main()
{
	Node_List_1 *Hd, *p , *tg;
	int n,i,min,max,r,cnt;
	time_t t;
	Hd=NULL;
	srand((unsigned) time(&t));
	printf("Dinh Ngoc Trang STT:47\n");
	printf("nhap min:");
	scanf("%d",&min);
	printf("nhap max: ");
	scanf("%d",&max);
	do{
    	printf("nhap so luong can random");
        scanf("%d",&cnt);
    }while(cnt > max - min + 1);
    map<int, bool> vis;
    for (i=0;i<=cnt;i++)
    {
	do{
            r = min + rand() % (max + 1 - min);
		p = new Node_List_1;
		p->Data= r;
		p->Adr_ItAf=NULL;
		Hd=Add_Af(Hd,p);
		}while(vis.find(r) != vis.end());
		vis[r]=true;
	}
	BRW_IT(Hd);
}
