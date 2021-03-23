#include <stdio.h>
#include <string.h>
int main(){
   char a[100],b[100],c[200];
   char t;
	printf("Nhap chuoi ki tu a:");
	gets(a);
	printf("Nhap chuoi ki tu b:");
	gets(b);
	size_t len1 = strlen(a);
   	size_t len2 = strlen(b);
   	strcpy(c,a);
   	strcat(c,b);
   int i, j;
   for (i = 0; i <strlen(c); i++) {
      for (j = i+1; j < strlen(c); j++) {
         if (c[i] > c[j]) {
            t = c[i];
            c[i] = c[j];
            c[j] = t;
         }
      }
   }
   
   printf("\nChuoi sau khi sap xep %s \n", c);
   return 0;
}
