#include<stdio.h>
#include<stdlib.h>
int stack[30];
char str[30];
int top=-1;
void push(int num)
{
 top++;
 stack[top]=num;
}
int pop()
{
 int last=stack[top];
 top--;
 if(top!=-2) return last;
 else
 {
 printf("Invalid expression...");
 exit(-1);
 }
}
int evaluate(int num1,int num2,char op)
{
 switch(op)
 {
 case '+':
 return num1+num2;
 break;
 case '-':
 return num1-num2;
 break;
 
 case '*':
 return num1*num2;
 break;
 
 case '/':
 return num1/num2;
 break;
 
 case '%':
 return num1%num2;
 break;
 }
}
void main()
{
 int temp=0,i;
 printf("Enter equation: ");
 scanf("%[^\n]s",str);
 for(i=0;str[i]!='\0';i++)
 {
 if(str[i]>='0'&& str[i]<='9')
 temp=temp*10+((int)(str[i]-'0'));
 
 else if(str[i]==' ')
 {
 push(temp);
 temp=0;
 }
 else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
 {
 int num2=pop();
 int num1=pop();
 int result=evaluate(num1,num2,str[i]);
 push(result);
 i++;
 }
 }
 
 if(str[i-1]>='0'&& str[i+1]<='9' || top!=0)
 {
 printf("Invalid expression...");
 exit(-1);
 }
 
 printf("Result = %d",pop());
}