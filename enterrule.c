#include <stdio.h>
#include<string.h>

int main()
{
   FILE*file=fopen("shell.sh","a+");
   if(file==NULL){
       printf("unable to open file");
       return 0;
   }
   fseek(file,0,SEEK_END);
   int n = ftell(file);
   rewind(file);
   feof(file);
    
   char str[30];
   printf("enter the command:");
   gets(str);
   fputs("\n",file);
   fputs(str,file);
   fclose(file);
}

