#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int excecute(){

    int status=system("./shell.sh");
    if (status==1){printf("command excecuted successfully");}
    
    else{printf("error\n");}
}

int passwrd(char*ptr)
{ char arr[15]="amma@123";
int n=0;
  for(int i=0;i<8;i++)
  {if(*(ptr+i)==arr[i])
  {n++;}
  }
  if (n==8)
  {return 1;}
  else {printf("wrong password");
  return -1;}
  }
  
void portinfo(){
char c;
FILE *f1=fopen("portsinfo.txt","r");
if(f1==NULL){
printf("error in file");
}
while((c=getc(f1))!=EOF){
            printf("%c", c);
        }
} 

void ipaddr(char *ipa){
int n;
int i=0;
printf("enter the number for the website u need to block\n1--yahoo\n2--duckduckgo\n enter ur choice;;;");
scanf("%d",&n);
FILE *f1=fopen("ipadd.txt","r");
for(int i=0;i<n;i++)
{fscanf(f1, "%*d %s",ipa) ;
}
		printf("%s\n",ipa);
		
}
void input(char *ipa)
{
char arr[100],mani[20],str[30],prot[10]; 
int n,l;
printf("enter the choice\n1--accept\n2--reject\n3--drop");
scanf("%d",&n);
switch (n){
case 1:   strcpy(mani,"ACCEPT"); break;
case 2:   strcpy(mani,"REJECT"); break;
case 3:   strcpy(mani,"DROP"); break;
default : printf("number is wrong enter the number correctly");}
FILE *f1=fopen("shell.sh","w");
printf("enter the choice\n1--append\n2--delete\n");
scanf("%d",&n);
switch (n){
case 1: fprintf(f1,"sudo iptables -A INPUT"); break;
case 2:  fprintf(f1,"sudo iptables -D INPUT"); break;
default : printf("number is wrong enter the number correctly");}

fclose(f1);
f1=fopen("shell.sh","a+");
printf("enter the way to do \n1--port no \n 2--with ip address \n ");
scanf("%d",&n);
switch (n){
case 1:printf("enter the protocol");
scanf("%s",prot); 
printf("enter the port number");
int k;
scanf("%d",&k);
fprintf(f1," -p %s --dport %d -j %s",prot,k,mani);
 break;
case 2: printf("enter the ip address choice of filling \n1-- manual\n2-- choose now from data table of ip addresses to websites ");
scanf("%d",&l);
if(l==1){
printf("enter the ip address");
scanf("%s",str);
fprintf(f1," -s %s -j %s ",str,mani);}
else{ ipaddr(ipa);
fprintf(f1," -s %s -j %s ",ipa,mani);}
break;
default : printf("number is wrong enter the number correctly");}
fclose(f1);
excecute();}

void output(char *ipa)
{
char arr[100],mani[20],str[30],prot[20]; 
int n,l;
printf("enter the choice\n1--accept\n2--reject\n3--drop");
scanf("%d",&n);
switch (n){
case 1:   strcpy(mani,"ACCEPT"); break;
case 2:   strcpy(mani,"REJECT"); break;
case 3:   strcpy(mani,"DROP"); break;
default : printf("number is wrong enter the number correctly");}
FILE *f1=fopen("shell.sh","w");
printf("enter the choice\n1--append\n2--delete\n");
scanf("%d",&n);
switch (n){
case 1: fprintf(f1,"sudo iptables -A OUTPUT"); break;
case 2:  fprintf(f1,"sudo iptables -D OUTPUT"); break;
default : printf("number is wrong enter the number correctly");}

fclose(f1);
f1=fopen("shell.sh","a+");
printf("enter the way to do \n1--port no \n 2--with ip address \n ");
scanf("%d",&n);

switch (n){
case 1:printf("enter the protocol");
scanf("%s",prot); 
printf("enter the port number");
int k;
scanf("%d",&k);
fprintf(f1," -p %s --dport %d -j %s",prot,k,mani);
 break;
case 2: printf("enter the ip address choice of filling \n1-- manual\n2-- choose now from data table of ip addresses to websites ");
scanf("%d",&l);
if(l==1){
printf("enter the ip address");
scanf("%s",str);
fprintf(f1," -d %s -j %s ",str,mani);}
else{ ipaddr(ipa);
fprintf(f1," -d %s -j %s ",ipa,mani);}
break;
default : printf("number is wrong enter the number correctly");}
fclose(f1);
excecute();}

int main()
{ char ptr[20];
char*ipa;
int n;
ipa=(char*)malloc(30*sizeof(char));
printf("enter the choice for which u want\n 1--directly manupulate with port or ip address\n2--check info about the ports\n");
scanf("%d",&n);
switch (n){
case 1: break;
case 2: portinfo(); break;
default : printf("number is wrong enter the number correctly");
}
printf("enter the choice for which chain u want to manipulate \n 1--INPUT\n 2--OUTPUT\n3--flush out all rules from the ip table");
scanf("%d",&n);
switch (n){
case 1: input(ipa); break;
case 2: output(ipa); break;
case 3:{printf("to flush out u need to have admin access so please enter the acccess key---");
scanf("%s",ptr);
int g=passwrd(ptr);

if(g==1){
char command[100]="sudo iptables -F";

int status = system(command);

    if (status == -1) {
        printf("Failed to execute the command.\n");
    } else {
        printf("Command executed successfully.\n");
        break;
    }}
    else printf("the password was wrong!!!!");}
    break;
    
default : printf("number is wrong enter the number correctly");}
char command[100]="sudo iptables -L";

int status = system(command);

    if (status == -1) {
        printf("Failed to execute the command.\n");
    } else {
        printf("Command executed successfully.\n");
       
    }


}


