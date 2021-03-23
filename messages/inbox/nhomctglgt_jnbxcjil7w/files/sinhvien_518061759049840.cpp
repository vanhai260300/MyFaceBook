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
	printf("Nhap so sinh vien can bo sung  : ");
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
int Dem(Node_BnTr*Tr)
{
	if(Tr==NULL)
	  return 0;
	else
	  return 1+Dem(Tr->Adr_TrL) + Dem(Tr->Adr_TrR);
	  
}
Node_BnTr*Search(Node_BnTr*Tr,float info)
{
	Node_BnTr*tmp;
	if(Tr==NULL)
	   return NULL;
	else
	{
		tmp=Tr;
		while(tmp!=NULL&&tmp->data.dtb<=info)
		{
			if(tmp->data.dtb>info)
			   tmp=tmp->Adr_TrL;
			else
			   tmp=tmp->Adr_TrR;
		}
		if(tmp!=NULL)
		    return tmp;
		else
		    return NULL;
	}
}
Node_BnTr *Delete(Node_BnTr*Tr,int info)
{
    Node_BnTr*tmp,*R,*t,*L;
	while(Search(Tr,info)!=NULL)
	{
		tmp=Search(Tr,info);
	    if(Tr==tmp)
	    {
	        if(tmp->Adr_TrL!=NULL)
	        {
	      		R=Tr->Adr_TrR;
				Tr=Tr->Adr_TrL;
				tmp->Adr_TrL=NULL;
				tmp->Adr_TrR=NULL;
				tmp=Tr;
				while(tmp->Adr_TrR!=NULL)
			    	tmp=tmp->Adr_TrR;
				tmp->Adr_TrR=R;
		    }
		    else
		    {
			   Tr=Tr->Adr_TrR;
			   tmp->Adr_TrR=NULL;
		    }
		}
		else
		{
			t=Tr;
			while(t->Adr_TrR!=tmp&&t->Adr_TrL!=tmp)
			{
				if(t->data.dtb>info)
				   t=t->Adr_TrL;
				else
				   t=t->Adr_TrR;
			}
			if(tmp->Adr_TrL==NULL&&tmp->Adr_TrR==NULL)
			    if(t->Adr_TrR==tmp)
			       t->Adr_TrR=NULL;
			    else
			        t->Adr_TrL=NULL;
			else
			    if(tmp->Adr_TrL==NULL)
			    {
			    	R=tmp->Adr_TrR;
					if(t->Adr_TrL==tmp)
				   		t->Adr_TrL=R;
					else
				    	t->Adr_TrR=R;
					tmp->Adr_TrR=NULL;
				}
				else
					if(tmp->Adr_TrR==NULL)
					{
						L=tmp->Adr_TrL;
						if(t->Adr_TrL==tmp)
				    		t->Adr_TrL=L;
						else
				    		t->Adr_TrR=L;
						tmp->Adr_TrL=NULL;
					}
					else
					{
						if(t->Adr_TrL==tmp)
						{
							t->Adr_TrL=tmp->Adr_TrL;
							t=t->Adr_TrL;
						}
						else
						{
							t->Adr_TrR=tmp->Adr_TrL;
							t=t->Adr_TrR;
						}
						while(t->Adr_TrR!=NULL)
		            		t=t->Adr_TrR;
		       			t->Adr_TrR=tmp->Adr_TrR;
		        		tmp->Adr_TrR=NULL;
		        		tmp->Adr_TrL=NULL;
		        	}
		}
	}
	return Tr;
}
		   
main()
{
	int choice,dung,d;
	Node_BnTr*Tree;
	Tree=NULL;
    while(dung!=1)
    {
    	printf("\n================================");
    	printf("\n===============MENU=============");
    	printf("\n================================");
    	printf("\n 1.Bo sung sinh vien vao cay T ");
    	printf("\n 2.Dem trong cay so sinh vien co diem trung binh tren 5,5 ");
    	printf("\n 3.In cay T cac sinh vien co diem trung binh tren 5,5 ");
    	printf("\n 4.Xoa cay T cac sinh vien co diem trung binh tren 5,5 ");
    	printf("\n 5.Exits !");
    	printf("\nMoi lua chon choice 1--->5 : \n");
    	scanf("%d",&choice);
    	switch(choice){
    		case 1:
    			Tree=Input(Tree);
    			printf("\n Danh sach sinh vien trong cay T sau khi bo sung sinh vien la : \n");
    			Out(Tree);
    			d=Dem(Tree);
			    break;
			case 2:
			    printf("\n So sinh vien co dtb lon hon 5,5 trong cay T la : %d",Demdtb(Tree));
			    break;
			case 3:
				printf("\nDanh sach sinh vien co dtb lon hon 5,5 trong cay T la : \n");
				Outdtb(Tree);
			    break;
			case 4:
				Tree=Delete(Tree,5.5);
				if(Dem(Tree)<d)
				{
					printf("\nDanh sach sinh vien co dtb tren 5,5 bi xoa trong cay T la : \n");
					Out(Tree);
				}
				else
				    printf("\n Trong cay T khong co sinh vien co dtb tren 5,5 ");
			    break;
			case 5:
			    dung=1;
			    printf("EXIT !");
		}
	}
}
