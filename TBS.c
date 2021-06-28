#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int prizecg(int price);
int confirm(int amt);
void reservation(int *array,int price,int select);
int choice1();
void cancel(int *array);
void ticket1(int choice,char name[10],int id2,int price);
void ticket2(int choice,char name[10],int id2,int price);
void ticket3(int choice,char name[10],int id2,int price);
int cmovie();
int movie();
void det();
struct moviedetails
{
char name[25];
char phone[15];
int seat;
int id;
};
struct moviedetails person[300];
int c=0;
int id2=1000;
int stp[10];
long phone;
int main()
{
int **seat,choice,select,i,price=250,amt;
seat=(int**)calloc(101,sizeof(int*));
for (i=0;i<3;i++)
*(seat+i)=(int *)calloc(101,sizeof(int));
printf("\t\t\tTHE PRICE OF A TICKET IS RS %d\n\n",price);
while(choice!=6)
{
choice=choice1();
switch(choice)
{
case 1:
price=prizecg(price);
break;
case 2:
det();
break;
case 3:
confirm(amt);
break;
case 4:
select=movie();
reservation(seat[select-1],price,select);
c++;
break;
case 5:
select=cmovie();
cancel(seat[select-1]);
break;
case 6:
printf("******System EXITED Successfully******");
break;
default:
printf("******CHOICE NOT AVAILABLE******");
system("PAUSE");
system("CLS");
break;
}
}
}
int prizecg(int prize)
{
char pass[10],check[10]="psap";
printf("Go ahead to change the prize of Ticket");
printf("PASSWORD: ");
scanf("%s",&pass);
if(strcmp(pass,check)==0)
{
printf("Enter new price of ticket: ");
scanf("%d",&prize);
system("PAUSE");
system("CLS");
}
else
printf("*****ENTERED PASSWORD IS WRONG*****\n");
return prize;
}
void det()
{
int i;
char pas[10],chk[10]="psap";
printf("Enter the password to see details: ");
scanf("%s",&pas);
if(strcmp(pas,chk)==0)
{
for(i=0;i<c;i++)
{
printf("Seat no: %d is booked by %s, booking id is %d\n",person[i].seat,person[i].name,person[i].id);
}
}
else
{
printf("******Entered password is wrong******\n");
printf("******PLEASE TRY AGAIN******");
}
system("PAUSE");
system("CLS");
}
int confirm(int amt)
{
int b,d;
char pa[10],ch[10]="psap";
printf("Go ahead to Confirm Payment of Ticket\n");
printf("PASSWORD: ");
scanf("%s",&pa);
if(strcmp(pa,ch)==0)
{
printf("Enter Seat no and Booking id of Customer: ");
scanf("%d",&b);
printf("::");
scanf("%d",&d);
printf("Enter the amount paid: ");
scanf("%d",&amt);
if(amt==250)
{
printf("Seat booking confirmed\n");
printf("Amount of 250 Rs has been Paid for Seat no %d at Booking id %d\n",b,d);
}
else
printf("Insufficient amount paid\n");
}
else
printf("*****ENTERED PASSWORD IS WRONG*****\n");
system("PAUSE");
system("CLS");
}
int movie()
{
int a;
system("cls");
printf("ENTER THE MOVIE YOU WANT TO SEE\n");
printf("*******************************\n");
printf("Choice 1:- AVENGERS\n");
printf("Choice 2:- JUSTICE LEAGUE\n");
printf("Choice 3:- JOKER\n");
scanf("%d",&a);
system("pause");
system("cls");
return a;
}
void reservation(int *array,int price,int select)
{
int i,j;
printf("\t\t\tR indicates Reserved seats\n");
printf("\t\tIf seat is vacant,Seat number is displayed\n\n");
printf("\n--------------------------- SCREEN THIS WAY ----------------------------\n\n\n");
for (i=1;i<=100;i++)
{
if (array[i]==0)
printf("%d\t",i);
else
printf("R\t",i);
if(i%10==0)
printf("\n\n");
}
printf("Please Enter Your NAME: ");
scanf("%s",&person[c].name);
printf("Please Enter Your PHONE NO: ");
scanf("%ld",&phone);
if(phone>999999999&&phone<10000000000)
{
printf("Please Enter the REQUIRED SEAT NO: ");
scanf("%d",&j);
if (j>100||j<1)
{
printf("Seat number is unavailable in this theater\n");
printf("Please re-enter seat number: ");
scanf("%d",&j);
}
if (array[j]==1)
{
printf("SORRY<THIS SEAT IS BOOKED>\n");
printf("PLEASE SELECT ANOTHER SEAT");
scanf("%d",&j);
}
else
array[j]=1;
person[c].seat=j;
if (select==1)
ticket1(j,person[c].name,id2,price);
else if (select==2)
ticket2(j,person[c].name,id2,price);
else
ticket3(j,person[c].name,id2,price);
id2++;
}
else
printf("INVALID NUMBER ****PLEASE RETRY****");
}
int cmovie()
{
int a;
system("cls");
printf("THE MOVIE TO BE CANCELLED IS\n");
printf("*************************\n");
printf("Opt 1:AVENGERS\n");
printf("Opt 2:JUSTICE LEAGUE\n");
printf("Opt 3:JOKER\n");
scanf("%d",&a);
system("pause");
system("cls");
return a;
}
void cancel(int *array)
{
int Cseat,i,stop;
printf("Please Enter Ticket id: ");
scanf("%d",&Cseat);
for (i=0;i<300;i++)
{
if(Cseat==person[i].id)
{
stop=5;
system("cls");
printf("\t\t%s Your seat %d is Cancelled\n\n",person[i].name,person[i].seat);
array[person[i].seat]=0;
i=300;
}
}
if (stop!=5)
{
printf("TICKET ID IS INCORRECT \n");
printf("PLEASE ENTER CORRECT TICKET ID: ");
}
}
int choice1(void)
{
int choice;
printf("      -*-*-* Pay Later Ticket Booking System for Cinema Theatre -*-*-*- \n");
printf(" \n    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n \n");
printf("                  *** You have the following choices ****          \n\n");
printf("         -- Press 1 to Edit the price of the tickets [ONLY ADMIN]--\n\n");
printf("         -- Press 2 to View reserved tickets         [ONLY ADMIN]--\n\n");
printf("         -- Press 3 to Confirm payment               [ONLY ADMIN]--\n\n");
printf("         -- Press 4 to Purchase a ticket                         --\n\n");
printf("         -- Press 5 to Cancel the seat                           --\n\n");
printf("         -- Press 6 to Exit the System                           --\n\n");
printf("  -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n ");
printf("NOTE: ONCE YOUR TICKET IS BOOKED YOU NEED TO CONFIRM YOUR TICKET BY PAYING TO ADMIN 10 MINUTES BEFORE THE SHOW\n");
printf("                               ****  ELSE TICKET WOULD BE CANCELLED BY THE ADMIN  ****                      \n");
printf("\n Please enter your CHOICE :");
scanf("%d",&choice);
return choice ;
}
void ticket1(int choice, char name[10], int id2, int price)
{
        system("cls");
        printf("========= Pay Later Ticket Booking System for Cinema Theatre =========\n");
        printf("*  Booking ID : %d                                                    \n",id2);
        printf("*  Show Name  : Avengers(Marvel Universe)                             \n");
        printf("*  Customer   : %s                                                    \n",name );
        printf("*                             Date : 24/04/2021                       \n");
        printf("*                             Time : 6:00 PM                          \n");
        printf("*                             Hall : 1                                \n");
        printf("*                             Seat No. : %d                          \n",choice);
        printf("*                             Price . : %d                            \n",price);
        printf("======================================================================\n");
        printf("\n\tPLEASE TAKE SCREENSHOT OF THIS TICKET FOR CONFIRMATION\n");
        person[c].id=id2;
        system("pause");
        system("cls");
        return;
}
void ticket2(int choice, char name[10], int id2, int price)
{
        system("cls");
        printf("========= Pay Later Ticket Booking System for Cinema Theatre =========\n");
        printf("*  Booking ID : %d                                                    \n",id2+1000);
        printf("*  Show Name  : Justice League(DC Universe)                           \n");
        printf("*  Customer   : %s                                                    \n",name );
        printf("*                             Date : 24/04/2021                       \n");
        printf("*                             Time : 6:00 PM                          \n");
        printf("*                             Hall : 2                                \n");
        printf("*                             Seat No. : %d                          \n",choice);
        printf("*                             Price . : %d                            \n",price);
        printf("======================================================================\n");
        printf("\n\tPLEASE TAKE SCREENSHOT OF THIS TICKET FOR CONFIRMATION\n" );
        person[c].id=id2+1000;
        system("pause");
        system("cls");
        return;
}
void ticket3(int choice, char name[10], int id2, int price)
{
        system("cls");
        printf("========= Pay Later Ticket Booking System for Cinema Theatre =========\n");
        printf(" * Booking ID : %d                                                    \n",id2+2000);
        printf(" * Show Name  : Joker(DC Universe)                                    \n");
        printf(" * Customer   : %s                                                    \n",name );
        printf(" *                            Date : 24/04/2021                       \n");
        printf(" *                            Time : 6:00 PM                          \n");
        printf(" *                            Hall : 3                                \n");
        printf(" *                            Seat No. : %d                          \n",choice);
        printf(" *                            Price . : %d                            \n",price);
        printf("======================================================================\n");
        person[c].id=id2+2000;
        printf("\n\tPLEASE TAKE SCREENSHOT OF THIS TICKET FOR CONFIRMATION\n");
        system("pause");
        system("cls");
        return;
}
