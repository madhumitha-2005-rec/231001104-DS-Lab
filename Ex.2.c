#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node *next;
 struct node *prev;
};
struct node *l=NULL;
struct node *newnode;
void insert_first(){
 newnode=(struct node*)malloc(sizeof(struct node));
 if(newnode!=NULL){
 printf("Enter the element : ");
 scanf("%d",&newnode->data);
 if (l!=NULL){
 newnode->next=l;
 newnode->prev=NULL;
 l->prev=newnode;
 l=newnode;
 }
 else
 {
 newnode->next=NULL;
 newnode->prev=NULL;
 l=newnode;
 } 
 }
}

void insert_last(){
 newnode=(struct node*)malloc(sizeof(struct node));
 struct node*p;
 if(newnode!=NULL){
 printf("enter no");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 if (l!=NULL){
 p=l;
 while(p->next!=NULL){
 p=p->next;
 }
 newnode->prev=p;
 p->next=newnode;
 
 }
 else
 {
 newnode->prev=NULL;
 l=newnode;
 }
 }
}
void insert_afterp(){
 newnode=(struct node*)malloc(sizeof(struct node));
 struct node *p=l;
 int pos,c=1;
 if(newnode!=NULL){
 printf("Enter the element : ");
 scanf("%d",&newnode->data);
 printf("enter the positon");
 scanf("%d",&pos);

 while(c<pos-1){
 p=p->next;
 c++;
 }
 newnode->next=p->next;
 newnode->prev=p;
 p->next=newnode;
 p->next->prev=newnode;
 } }
void delete_first(){
 struct node*p=l;
 l=l->next;
 l->prev=NULL;
 free(p); }
void delete_last(){
 struct node*p=l;
 struct node*temp;
 while(p->next->next!=NULL){
 p=p->next;
 }
 temp=p->next;
 p->next=NULL;
 free(temp); }
void delete_afterp(){
 struct node*p=l;
 struct node *temp;
 int pos,c=1;
 printf("Enter position : ");

 scanf("%d",&pos);
 while(c<pos){
 p=p->next;
 c++;
 }
 temp=p->next;
 if (temp->next==NULL){
 free(temp);
 p->next=NULL;
 }
 else{
 p->next=temp->next;
 temp->next->prev=p;
 free(temp);
 }
}
void find(){
 struct node *p=l;
 int pos,c=1;
 printf("enter position ");
 scanf("%d",&pos);
 while(c<pos){
 p=p->next;
 c++;
 }
 printf("The element present at the position %d is %d",pos,p->data);
}
void find_next(){
 struct node *p=l;
 int pos,c=1;
 printf("Enter the position : ");
 scanf("%d",&pos);

 while(c<pos){
 p=p->next;
 c++;
 }
 printf("The element present next to the position %d is %d",pos,p->next->data);
}
void find_previous(){
 struct node *p=l;
 int pos,c=1;
 printf("enter position ");
 scanf("%d",&pos);
 while(c<pos){
 p=p->next;
 c++;
 }
 printf("The element present previous to the position %d is %d",pos,p->prev->data);
}
void display(){
 if (l!=NULL){
 struct node*p;
 p=l;
 while(p!=NULL){
 printf("%d",p->data);
 p=p->next;
 }
 }
 else 
 printf("List is empty");
}

void main()
{
 int n;
 struct node *l=NULL;
 printf("options\n1.enter at first\n2.enter at last\n3.insert after p\n4.delete first 
element\n5.delete last\n6.delete after p\n7.find\n8.find next\n9.find 
previous\n10.display\n11.exit\n");
 do
 {
 printf("\nEnter your option:");
 scanf("%d",&n);
 switch(n){
 case 1:
 insert_first();
 break;
 case 2:
 insert_last();
 break;
 case 3:
 insert_afterp();
 break;
 case 4:
 delete_first();
 break;
 case 5:
 delete_last();
 break;
 case 6:
 delete_afterp();
 break;
 case 7:
 find();
 break;
 case 8:
 find_next();
 break;
 case 9:
 find_previous();
 break;
 case 10:
 display();
 break;
 }
 } while(n!=11); 
}
