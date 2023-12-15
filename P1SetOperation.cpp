#include<iostream>
using namespace std;
int main()
{
int a[3][3],b[3][3],c[10][10],i,j,op;
int addi(int a[3][3],int b[3][3]);
int multi(int a[3][3],int b[3][3]);
int trans(int a[3][3]);
cout<<"\n Enter first column:";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cin>>a[i][j];
}
}
cout<<"\n Enter second column:";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cin>>b[i][j];
}
}
do
{
cout<<"\n 1.Addition of Matrices";
cout<<"\n 2.Multiplication of Matrices";
cout<<"\n 3.Transpose of Matrices";
cout<<"\n 4.Exit";
cout<<"\n 5.Enter option:";
cin>>op;
switch(op)
{
case 1: addi(a,b);
break;
case 2: multi(a,b);
break;
case 3: trans(a);
break;
case 4:break;
}
}while(op<4);
}

int addi(int a[3][3],int b[3][3])
{
int c[10][10], i,j;
for(i=0;i<3;i++){

for(j=0;j<3;j++){
c[i][j]=a[i][j]+b[i][j];
}
}
cout<<"\n Addition two matrix";
for(i=0;i<3;i++){
for(j=0;j<3;j++){
cout<<"\t"<<c[i][j];
}
cout<<"\n";
}
}
int multi(int a[3][3],int b[3][3])
{
int i,j,k,c[3][3];
for(i=0;i<3;i++){
for(j=0;j<3;j++){
c[i][j]=0;
for(k=0;k<3;k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}
cout<<"\n Multiplication of two matrix";
for(i=0;i<3;i++){
for(j=0;j<3;j++){
cout<<"\t"<<a[j][i];
}
cout<<"\n";
}
}
int trans(int a[3][3])
{
int i,j;
cout<<"\n Trans of matrix";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++){
cout<<"\t"<<a[j][i];
}
cout<<"\n";
}
}