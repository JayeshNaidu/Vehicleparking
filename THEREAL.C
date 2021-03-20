#include<stdio.h>
#include<conio.h>
#include<string.h>
int count=0,carc=0,scooc=0;
struct node
{
int num,data;
char name[50];
struct node *link;
};
struct node *head=NULL,*new1=NULL,*temp=NULL,*prev=NULL,*next=NULL;
void park()
{
count++;
new1=(struct node*)malloc(sizeof(struct node));
printf("ENTER VEHICLE NUMBER\n");
scanf("%d",&new1->num);
printf("ENTER CUSTOMER NAME\n");
scanf("%s",new1->name);
temp=head;
if(head==NULL)
{
head=new1;
}
else
{
while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=new1;
}
}

void display()
{
temp=head;
while(temp!=NULL)
{
printf("%d  ",temp->num);
printf("%s\n",temp->name);
temp=temp->link;
}
}


void dep()
{

int depnum;
count--;
printf("ENTER VEHICLE NUMBER TO BE DEPARTED\n");
scanf("%d",&depnum);
temp=head;
if(temp!= NULL && temp->num==depnum)
{
head=temp->link;
free(temp);
}
while(temp!=NULL && temp->num!=depnum)
{
prev=temp;
temp=temp->link;
}
printf("VEHICLE NUMBER: %d HAS BEEN DEPAERTED\n",depnum);
prev->link=temp->link;
free(temp);
}


void main()
{
int sel=0;
char ch;
clrscr();
printf("\n\t\t   WELCOME TO CAR PARKING SYSTEM\n\n");
printf("\t\t\tSELECT YOUR CHOICE:\n\n");
do
{
printf("1.PARK OF VEHICLE\n2.DEPARTURE OF VEHICLE\n3.DISPLAY\n4.TOTAL NUMBER OF VEHICLES\n");
scanf("%d",&sel);
if(sel==1)
{
park();
}
else if(sel==2)
{
dep();
}
else if(sel==3)
{
display();
}
else if(sel==4)
{
printf("%d \n",count);
}
else
{
printf("PLEASE RETRY\n\n");
}
printf("DO YOU WISH TO CONTINUE ?\n\n");
ch=getch();
}
while(ch=='y' || ch=='Y');
getch();
}