#include<stdio.h>
#include<stdlib.h>
int que[8];
int r;
void insert();
void del();
void show();
 int main()
{
int c;
printf("\n1.insert");
printf("\n2.delete");
printf("\n3.display");
printf("\n4.exit");
printf("\n\nenter your choice");
scanf("%d",&c);
switch(c)
{
case 1:
insert();
break;
case 2:
del();
break;
case 3:
show();
break;
case 4:
exit(0);
break;
default: printf("invalid choice");
}
main();
}
void insert()
{
char ans='y';
if(r>=7)
{
printf("que is full");
main();
}
while(ans=='y'||ans=='Y')
{
printf("\nenter element: ");
scanf("%d",&que[r]);
if(r==7)
{ 
printf("que is full");
  
break;
}
else
r++;
printf("continue[y/n]: ");
scanf("%c",&ans);

}
}
void show()
{
int j;
for(j=0;j<r;j++)
printf("%d ",que[j]);

}
void del()
{
int j;
if(r==0)
{ 
printf("que is empty");
main();
}
for(j=0;j<r;j++)
que[j]=que[j+1];
que[r]=0;
r--;
}
