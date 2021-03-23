#include<stdio.h>
#include<conio.h>
#include<string.h>

void Nenchuoi(char str1[],char str2[])
{
	char kytu[2];
	int dem=0, demkytu=1;
	for(int i=0;i<strlen(str1);i++)
	{
		
		if(str1[i]==str1[i+1])
			demkytu=demkytu+1;
		else
		{
			sprintf(kytu,"%d",demkytu);
			if(demkytu!=1)
			{
				str2[dem]=kytu[0];
				str2[dem+1]=str1[i];
				dem=dem+2;
			}
			else
			{
				str2[dem]=str1[i];
				dem=dem+1;
			}
			demkytu=1;
		}
	}
	str2[dem]='\0';
}
main()
{
	char str1[30],str2[30];
	fflush(stdin);
	printf("Nhap chuoi:");
	gets(str1);
	Nenchuoi(str1,str2);
	printf("Chuoi da nen: %s",str2);
	getch();
}

