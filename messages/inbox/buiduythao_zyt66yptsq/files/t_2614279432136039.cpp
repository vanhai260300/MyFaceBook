#include <stdio.h>
#include <string.h>
Out(char s1[],char s2[])
{
	char *tro;
	tro=strstr(s1,s2);
	if(tro !=NULL)
		printf("Chuoi con < %s > co trong chuoi < %s >",s2,s1);
	else
		printf("khong tim thay chuoi  < %s > can tim trong chuoi < %s >",s2,s1);
}
main()
{
	char s1[100],s2[100];
	printf("Nhap chuoi ban dau : \n");
	fflush(stdin);
	gets(s1);
	printf("Nhap chuoi can tim trong chuoi ban dau : \n");
	gets(s2);
	Out(s1,s2);
}
