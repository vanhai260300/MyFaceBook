#include <stdio.h>
#include <string.h>
char *TimKiem (char *s1 ,char *s2){

int n = 0;
   int m = 0;
   int times = 0;
   int len = strlen(s2);      // bien luu giu do dai cua chuoi can tim kiem

   while(s1[n] != '\0') {

      if(s1[n] == s2[m]) {     // neu ky tu dau tien la giong nhau

         // tiep tuc tim kiem

         while(s1[n] == s2[m]  && s1[n] !='\0') {
            n++;
            m++;
         }

         // Neu day ky tu nay co do dai bang chuoi tim kiem
         if(m == len && (s1[n] == ' ' || s1[n] == '\0')) {

            // Chuc mung ban da tim ra chuoi can tim
            times++;
         }
      }else {            // Neu ky tu dau tien khong giong nhau
         while(s1[n] != ' ') {        //bo qua, tiep tuc tim kiem tu tiep theo
            n++;
            if(s1[n] == '\0')
            break;
         }
      }
		
      n++;
      m=0;  // reset bien dem.
   }

   if(times > 0) {
      printf("Chuoi '%s' xuat hien %d lan\n", s2, times);
   }else {
      printf("Chuoi '%s' khong co mat trong cau.\n", s2);
   }

   return 0;
}
 main() {
   char s1[] = "nhom 7 _tim kiem chuoi ";
   char s2[] = "nhom 8";
   printf (" ",TimKiem (s1 ,s2));
}
