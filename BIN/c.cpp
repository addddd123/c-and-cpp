#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next;
}*head=NULL,*temp=NULL,*p=NULL;
struct node  *createlist(int n);
void displaylist();
void displaylistt();
void inatbeg();
void inlast();
void nyp();
void dnode();
void dlast();
void dbeg();
void swap();
int search();
struct node *createlist(int n)
{  
int i=0;
for(i=0;i<n;i++)
{
// create individual node
temp=(struct node *)malloc(sizeof(struct node));
scanf("%d",&(temp->data));
temp->next=NULL;
if(head==NULL)
head=temp;
else
{
 p=head;
 while(p->next!=NULL)
 p=p->next;
 p->next=temp;
 }}  return(head);
}
void displaylist()
{
if(head==NULL)
{
printf("\n::::: list is empty:::::\n");
}
else
{
struct node *p=head;
printf("\n linked list is\n");
while(p!=NULL)
{
printf("  %d ",p->data);
p=p->next;
}
}
}
void inatbeg()
{
temp=(struct node *)malloc(sizeof(struct node));
printf("\n enter data at node of begning which u want to link\n");
scanf("%d",&(temp->data));
temp->next=NULL;
temp->next=head;
head=temp;
}
void inlast()
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
printf("\n enter data at node which u want to link at last\n");
scanf("%d",&(t->data));
t->next=NULL;
while(p->next!=NULL)
p=p->next;
p->next=t;
}
void nyp()
{
int j=1,n;
struct node *nyp;
printf("\nenter the position at which u want to link node\n");
scanf("%d",&n);
nyp=(struct node *)malloc(sizeof(struct node));
printf("enter data at node which u want to link ats pecfic position\n");
scanf("%d",&(nyp->data));
nyp->next=NULL;
struct node *p=head;
for(j=1;j<n-1;j++) 
p=p->next;
nyp->next=p->next;
p->next=nyp;
}
int search(struct node *head)
{
int key,i=1,flag=0;
printf("\n enter element which u want to check in list:\t");
scanf("%d",&key);
struct node *p=head;
while(p!=NULL)
{
if(key==p->data)   {
flag=1;
break;
}
i++;
p=p->next;
}
if(flag==1)
return i;
else
return -1;
}
void dnode(int l)  // l=postion to delete
{
int i=1;
struct node *p=head;
struct node *q=head;
for(i=1;i<l-1;i++)
{
p=p->next;
}
q=p->next;
p->next=q->next;
free(q);
}
void dlast()
{
struct node *p=head,*q;
while(p->next!=NULL)
{
q=p;
p=p->next;
}
q->next=NULL;
free(p);
}
void dbeg()
{
p=head;
head=head->next;
free(p);
displaylist();
}
void swap()
{
int m,n,i=1,j=1,t;
struct node *p,*q;
p=head;
q=head;
printf("\n enter positons at which u want to swap values\n");
scanf("%d %d",&m,&n);
for(i=1;i<m;i++)
p=p->next;
for(j=1;j<n;j++)
q=q->next;
t=p->data;
p->data=q->data;
q->data=t;
}
int main()
{
//clrscr();
int n=1,l=0,choice;
printf("enter how many elements u want to enter\n\t");
scanf("%d",&n);
head=createlist(n);
while(1)
{
 printf("\n1.insert at begning");
 printf("\t2 insert at last");
 printf("\t3 insert at position");
 printf("\n4 display");
 printf("\t5 search");
 printf("\t6 delete at specfic position");
 printf("\n7 delete at last\t");
 printf("\t8 delete at begning");
 printf("\t9 swap");
 printf("\n10 conactenate lists");
 printf("\n11 exit\t");
 scanf("%d",&choice);
 switch(choice)
{
case 1:
inatbeg();
displaylist();

break;
case 2:
inlast();
displaylist();
break;
case 3:
nyp();
displaylist();
break;
case 4:
displaylist();
break;
case 5:
l=search();
if(l!=-1)
printf("\t\t key  found at position %d  \t",l);
else
printf("\t\t sory value not found \n");
break;
case 6:  // delete at specfic position;
int p;
printf("\n enter positi0n to delete\t");
scanf("%d",&p);
dnode(p);
displaylist();
break;
case 7:
dlast();
displaylist();
break;
case 8:
dbeg();
break;
case 9:
swap();
displaylist();
break;
case 10:
//concatenate();
break;
case 11:
exit(0);
break;
deafault:
printf("\n enter valid choice\n");
}
}
getch();
}
