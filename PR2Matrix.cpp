#include<iostream>
#define 10 10
void main()
{
int option;
 int a[10][10],b[10][10],z[10][10],i,j,k,r1,c1,r2,c2;
void addm(int a[10][10] , int b[10][10], int r1,int c1,int r2,int c2);
void multm(int a[10][10] , int b[10][10], int r1,int c1,int r2,int c2);
 void transm(int a[10][10] , int r1,int c1);
 void saddlepoint(int a[10][10],int r1,int c1);
do
{
cout<<"\n1. READ";
 cout<<"\n2. ADDITION";
cout<<"\n3. MULTIPLICATION";
cout<<"\n4. TRANSPOSE";
 cout<<“\n 5. SADDLEPOINT”;
cout<<"\n 6. EXIT";
cout<<"\n\t\t Enter your option";
cin>>ption;
switch(option)
{
case 1: cout<<"\n.........Enter size of row & col of A matrix";
cin>>r1>>c1;
 cout<<"\n.........Enter size of row & col of B matrix";
cin>>r2>>c2;
 cout<<"\n.........Enter the elements of matrix A rowwise\t";
for(i=0;i<r1;++i)
 { 
for(j=0;j<c1;++j)
{
 cin>>a[i][j];
 }
 }
cout<<"\n.........Enter the elements of matrix B rowwise\t";
for(i=0;i<r2;++i)
 { 
for(j=0;j<c2;++j)
{
 cin>>b[i][j];
 }
 }
 break;
 case 2: addm(a,b,r1,c1,r2,c2);
 break;
case 3: multm(a,b,r1,c1,r2,c2);
 break;
 case 4: transm(a,r1,c1);
 break;
case 5:break;

}
}while(option<4);
getch();
}
void addm(int a[10][10] , int b[10][10], int r1,int c1,int r2,int c2)
{ int i,j,k,z[10][10];
// addition with pointer
if(r1!= r2 || c1!=c2 )
{
cout<<(" Cannot be added");
}
 else
 {
 for(i=0;i<r1;++i)
{ for(j=0;j<c1;++j)
{
 z[i][j]=a[i][j]+b[i][j];
}
}
cout<<("\nThe addition of given matrices is");
for(i=0;i<r1;++i)
{
for(j=0;j<c1;++j)
{
 cout<<"\t"<<z[i][j];
}
 cout<<"\n";
}
}
}
void multm(int a[10][10] , int b[10][10], int r1,int c1,int r2,int c2)
{ int z[10][10],i,j,k;
if(c1!=r2)
{
 cout<<"\n\tRows of first and Columns of second are not 
matching";
}
else
 {
for(i=0;i<r1;++i)
{ for(j=0;j<c2;++j)
{ z[i][j]=0;
for(k=0;k<r2;++k)
z[i][j]=a[i][k]*b[k][j]+z[i][j];
}
}
cout<<"\n The matrix multiplication is";
for(i=0;i<r1;++i)
{ cout<<("\n");
for(j=0;j<c2;++j)
{
 cout<<”\t"<<z[i][j];
}
}
}
}
void transm(int a[10][10],int r1,int c1)
{ int i,j,k;
 
if(r1!= c1)
{
cout<<" Row and column must be same ";
}
else
{
cout<<"\n Transpose is:";
for(i=0;i<c1;++i)
{
for(j=0;j<r1;++j)
{
cout<<"\t"<< a[j][i];
}
cout<<"\n";
}
 }
}