#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
//#include<iostream.h>
void admisn();
void admisn()
{ char *rg,ip[7]="indian",iq[7]="INDIAN",*ic="india",*ib="INDIA";
char *name,g[10],f[15],m[5]="MALE",n[10]="female",o[10]="FEMALE",p[10]="male";
printf("\n enter your name \t");
scanf("%s",name);
printf("\n enter male sund naav\n");
gets(f);
printf("enetr ur gender\n");
scanf("%s",g);
while( (strcmp(m,g)!=0 && strcmp(n,g)!=0 && strcmp(p,g)!=0 && strcmp(o,g)!=0)==1)
{
if(strcmp(m,g)!=0 && strcmp(n,g)!=0 && strcmp(p,g)!=0 && strcmp(o,g)!=0)
{
printf("\nerror in gender \n enter correct gender\t");
scanf("%s",g);
}
}
puts("enter ur region\n");
scanf("%s",rg);
if(strcmp(rg,iq)==0|| strcmp(rg,ip)==0||strcmp(rg,ic)==0||strcmp(rg,ib)==0)
{
printf("u shit hole indian go back\nINDIAN Dogs r not allowed here");
}
else{
struct date
{
  int d,m,y;

};
struct date d1;
printf("enter Dob in form 24/04/1999>>>>>:::::::\t");
scanf("%d/%d/%d",&d1.d,&d1.m,&d1.y);

if(d1.y > 2000 || d1.m>12 || d1.d>31)
 {
if(d1.d>31||d1.m>12)
{
if(d1.d>31&&d1.m>12)
printf("error in both day and month u enterd\n");
else
{
if(d1.m>12==1)
printf("error in month\n");
else
printf("error in day\n");
}
printf("error either in day or month\n");
}
else{
printf("U  not mature to join this course\n");
printf("U SHOULD COME in %d year i.e, after years ",17+d1.y);  printf("=%d",d1.y-1999);
}    }

else{
printf(" u have been registerd sucessfully");
printf("\n U WANT TO CONTUNIUE WITH THIS INFO\t");
printf("name=%s,PARENTAGE== %s,,,, DOB: %d/%d/%d  gender=%s\t\t     \n U WILL BE INFORMDED WHWN EXAM DATES WILL BE ANOUNCED:::::----",name,f,d1.d,d1.m,d1.y,g);
}
}
}


int main()
{
while(1)
{
int choice,i;

clrscr();
printf(	"WELCOME TO ADNANS ROYAL ACADEMY OF COMPUTER SCIENCE\t");
printf("\n1. for admisson\t");
printf("\n2.for fee structure\t");
printf("\n3. for eligiblity\t");
printf("\n4. for contact detail\t");
printf("\n5. enter 0 to exit\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
admisn();
break;

case 2:
printf("FEE STRUCTURE OF THE GIVEN SELECTED COURSE\t   is   RS 1000\nSCHOLARSHIP WILL BE PR0VIDED FOR PHYSICALLY HANDICAPED STUDENTS");
break;
case 3:
printf("ELIGIBLITY TO JOIN THE COURSE IS \n 12 th qualify with percantage of 65%\n");
break;
case 4:
printf("contact details C0TACT COORDINATOR =9622840886 EMAIL :-SHEIKHADNAN886@GMAIL.COM\n");
break;
case 5:
   exit(0);
   break;
default:
printf("INVALID CHOICE");
break;
 }
 getch();
}
}












































































