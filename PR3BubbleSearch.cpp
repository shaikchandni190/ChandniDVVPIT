#include<iostream>
#include<string.h>
using namespace std;
int op,i,j,n,position;
typedef struct student1
{
char name[20];
long mobileNo;
float  billNo;
}student;
int main()
{
char name,uname[10];
long mobileNo;
float  billNo;
student St[10];
int create(student St[],int n);
int display(student St[],int n);
int bubble(student St[],int n);
int selection(student St[],int n);
int binary(student St[],char uname[10],int n);
do
{
cout<<"\n 1.create database";
cout<< "\n 2.display database";
cout<<"\n 3.bubble sort";
cout<<"\n 4.selection sort";
cout<<"\n 5.binary";
cout<<"\n enter option :";
cin>>op;
switch(op)
{
case 1:
cout<<"\n Enter no.of users:";
cin>>n;
create(St,n);
break;
case 2:display(St,n);
break;
case 3:bubble(St,n);
break;
case 4:selection(St,n);
break;
case 5:binary(St,uname,n);
break;
case 6:break;
}

}while(op<6);
}

int create(student St[],int n)
{
int i;
cout<<"\n enter the name,mobileno,billno :";
for(i=0;i<n;i++)
{
cin>>St[i].name;
cin>>St[i].mobileNo;
cin>>St[i].billNo;
}

}
int display(student St[],int n)
{
int i;
cout<<"\nname of student:"<<"\t"<<"mobileNo:"<<"\t"<<"billNo:"<<"\n";
for(i=0;i<n;i++)
{
cout<<"\t"<<"\t"<<St[i].name<<"\t";
cout<<"\t"<<St[i].mobileNo;
cout<<"\t"<<St[i].billNo;
cout<<"\n";
}

}
int bubble(student St[],int n)
{
student temp;

for(i=0;i<n;i++)
{
	if(strcmp(St[i].name,St[i+1].name)>0)
	{
                          temp=St[i+1];
		St[i+1]=St[i];
		 St[i]=temp;
	}
}
}

int selection(student St[],int n)
{
student temp;
int k;
k=i;
for(i=0;i<n;i++)
{
	if(strcmp(St[i].name,St[i+1].name)>0)
	
	{
                          temp=St[i+1];
		St[i+1]=St[i];
		 St[i]=temp;
	}
}

}
int binary(student St[],char uname[10],int n)
{
}