//WAP toImplement Infix to postfix
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
class stack{
private:
typedef struct stack1{
int data;
struct stack1*next;
}node;
node*top;
public:
stack();
~stack();
void push (char,node**);
int pop(node**);
int stackempty(node*);
void postfix();
void eval();
};
int main(){
int ch;
stack st;
do{
cout<<"\n1.infix to postfix\n2.Evaluation of postfix exp.\n3.Exit";
cout<<"\n.Enter your choice";
cin>>ch;
switch(ch)
{
case 1:st.postfix();
break;
case 2:st.eval();
break;
case 3:break;

}
}while(ch!=3);
}
stack::stack()
{
top=NULL;
}
stack::~stack()
{
node*temp;
temp=top;
if(temp==NULL)
delete temp;
else{
while(temp!=NULL
)
{
temp=temp->next;
top=NULL;
top=temp;
}
delete temp;
}
}
void stack::push(char x,node**top){
node*newnode;
newnode=new node;
newnode->next=NULL;
newnode->data=x;
newnode->next=*top;
*top=newnode;
}
int stack::pop(node**top)
{
int x;
node*temp;
x=(*top)->data;
temp=*top;
*top=(*top)->next;
delete temp;
return x;
}
int stack::stackempty(node*temp)
{
if(temp==NULL)
return 1;
else
return 0;
}
void stack::postfix()
{
char exp[40];
int length,j,l;
char ch;
char post[40];
j=0;
cout<<"\nenter exp";
cin>>exp;
length=strlen(exp);
cout<<"\n\nThe postfix is:";
for(int i=0;i<=length-1;i++){
ch=exp[i];
if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/')
push(ch,&top);
else if(ch!=')')
{
post[j]=ch;
j++;
cout<<ch;
}
else
{
do
{
ch=pop(&top);
if(ch!='(')
{
post[j]=ch;
j++;
cout<<ch;
}
}while(ch!='(');
}
}
post[j]='$';
}
void stack::eval()
{
char exp[40];
int length,val,a,b,c,l;
char ch;
char post[40];
int j=0,i=0;
cout<<"\nenter exp";
cin>>exp;
length=strlen(exp);
exp[length]='$';
for(i=0;i<=length;i++){
ch=exp[i];
if(ch=='^'||ch=='+'||ch=='-'||ch=='*'||ch=='/')
{
b=pop(&top);
a=pop(&top);
switch(ch)
{
case'+':c=a+b;break;
case'-':c=a-b;break;
case'*':c=a*b;break;
case'/':c=a/b;break;
case'^':c=pow(a,b);break;
}
push(c,&top);
}
else
if(ch!='$')
{
val=ch-96;
push(val,&top);
}
}
c=pop(&top);
cout<<"\n result:"<<c;
}