#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7
typedef int index;
typedef index position;
typedef struct hash_entry cell;
typedef struct H_table* Hashtable;
enum entry { Legitimate, Empty, Deleted };
struct hash_entry
{
 int data;
 enum entry info;
};
struct H_table
{
 int table_size;
 cell* cell_array;
};
int next_prime(int table_size)
{
 int i=table_size,f;
 while(1)
 {
 f=1;
 for(int j=2;j<i;j++)
 {
 if(i%j==0)
 {
 f=0;
 break;
 }
 }
 if(f==1)
 return i;
 i++;
 }
}
index Hash(int key,int table_size)
{
 return key % table_size;
}
Hashtable Create_table(int table_size)
{
 Hashtable H;
 if(table_size < MINSIZE)
 {
 printf("Table size too small");
 return NULL;
 }
 H=(Hashtable)malloc(sizeof(struct H_table));
 if(H==NULL)
 {
 printf("Out of space");
 return NULL;
 }
 H->table_size = next_prime(table_size);
 H->cell_array = (cell*) malloc(sizeof(cell) * H->table_size); 
 if(H->cell_array==NULL)
 {
 printf("Out of space");
 return NULL;
 } 
 for(int i=0;i< H->table_size;i++)
 {
 H->cell_array[i].info=Empty;
 }
 return H;
}
position find(int key,Hashtable H)
{
 position cur;
 int collision=0;
 cur=Hash(key,H->table_size);
 while(H->cell_array[cur].info!=Empty && H->cell_array[cur].data != key)
 {
 cur=(cur+1) % H->table_size;
 }
 return cur;
}
void insert(int key,Hashtable H)
{
 position pos=find(key,H);
 if(H->cell_array[pos].info!=Legitimate)
 {
 H->cell_array[pos].info=Legitimate;
 H->cell_array[pos].data=key;
 }
}
void display(Hashtable H)
{
 for(int i=0;i<H->table_size;i++)
 {
 printf("%d => %d\n",i,H->cell_array[i].data);
 }
}
int isFull(Hashtable H)
{
 int count=0;
 for(int i=0;i<H->table_size;i++)
 {
 if(H->cell_array[i].info==Legitimate)
 count++;
 } 
 if(count==H->table_size) return 1;
 else
 return 0;
}
void main()
{
 int size;
 printf("Enter size of the table: ");
 scanf("%d",&size);
 Hashtable H1=Create_table(size);
 printf("Hash table size: %d\n",H1->table_size);
 if(H1!=NULL)
 {
 int d,op;
 do
 {
 printf("\nChoose operation: 1) Insert 2) Display: ");
 scanf("%d",&op);
 
 switch(op)
 {
 case 1:
 if(isFull(H1))
 {
 printf("Hash Table is full...\n");
 break;
 }
 printf("Enter the data to be inserted: ");
 scanf("%d",&d);
 insert(d,H1);
 break; 
 case 2:
 printf("\nLinear probing hash table\n\n");
 display(H1);
 break; 
 case 0:
 printf("Operation terminated");
 break; 
 default:
 printf("Invalid operation...\n");
 } 
 }while(op);
 }
 }







#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7
typedef int index;
typedef index position;
typedef struct hash_entry cell;
typedef struct H_table* Hashtable;
enum entry { Legitimate, Empty, Deleted };
struct hash_entry
{
 int data;
 enum entry info;
};
struct H_table {
 int table_size;
 cell* cell_array;
};
int next_prime(int table_size) {
 int i=table_size,f;
 while(1)
 {
 f=1;
 for(int j=2;j<i;j++)
 {
 if(i%j==0)
 {
 f=0;
 break;
 }
 }
 if(f==1)
 return i;
 i++;
 } }
index Hash(int key,int table_size)
{
 return key % table_size;
}
Hashtable Create_table(int table_size)
{
 Hashtable H;
 if(table_size < MINSIZE)
 {
 printf("Table size too small");
 return NULL;
 }
 H=(Hashtable)malloc(sizeof(struct H_table));
 if(H==NULL)
 {
 printf("Out of space");
 return NULL;
 }
 H->table_size = next_prime(table_size);
 H->cell_array = (cell*) malloc(sizeof(cell) * H->table_size); 
 if(H->cell_array==NULL)
 {
 printf("Out of space");
 return NULL;
 } 
 for(int i=0;i< H->table_size;i++)
 {
 H->cell_array[i].info=Empty;
 }
 return H;
}
position find(int key,Hashtable H)
{
 position cur;
 int collision=0;
 cur=Hash(key,H->table_size);
 while(H->cell_array[cur].info!=Empty && H->cell_array[cur].data != key)
 {
 cur=(cur+(2*(++collision)-1)) % H->table_size;
 }
 return cur;
}
void insert(int key,Hashtable H)
{
 position pos=find(key,H);
 if(H->cell_array[pos].info!=Legitimate)
 {
 H->cell_array[pos].info=Legitimate;
 H->cell_array[pos].data=key;
 }
}
void display(Hashtable H)
{
 for(int i=0;i<H->table_size;i++)
 {
 printf("%d => %d\n",i,H->cell_array[i].data);
 }
}
int isFull(Hashtable H)
{
 int count=0;
 for(int i=0;i<H->table_size;i++)
 {
 if(H->cell_array[i].info==Legitimate)
 count++;
 } 
 if(count==H->table_size) return 1;
 else
 return 0;
}
void main()
{
 int size;
 printf("Enter size of the table: ");
 scanf("%d",&size);
 Hashtable H1=Create_table(size);
 printf("Hash table size: %d\n",H1->table_size);
 if(H1!=NULL)
 {
 int d,op;
 do
 {
 printf("\nChoose operation: 1) Insert 2) Display: ");
 scanf("%d",&op); 
 switch(op)
 {
 case 1:
 if(isFull(H1))
 {
 printf("Hash Table is full...\n");
 break;
 }
 printf("Enter the data to be inserted: ");
 scanf("%d",&d);
 insert(d,H1);
 break; 
 case 2:
 printf("\nQuadratic probing hash table\n\n");
 display(H1);
 break; 
 case 0:
 printf("Operation terminated");
 break; 
 default:
 printf("Invalid operation...\n");
 } 
 }while(op);
 }
}









#include <stdio.h>
#include<stdlib.h>
#define MINSIZE 7
typedef int index;
typedef index position;
typedef struct hash_entry cell;
typedef struct H_table* Hashtable;
enum entry { Legitimate, Empty, Deleted };
struct hash_entry {
 int data;
 enum entry info;
};
struct H_table {
 int table_size;
 cell* cell_array;
};
int next_prime(int table_size) {
 int i=table_size,f;
 while(1)
 {
 f=1;
 for(int j=2;j<i;j++)
 {
 if(i%j==0)
 {
 f=0;
 break;
 }
 }
 if(f==1)
 return i;
 i++;
 }
}
int isFull(Hashtable H)
{
 int count=0;
 for(int i=0;i<H->table_size;i++)
 {
 if(H->cell_array[i].info==Legitimate)
 count++;
 } 
 if(count>H->table_size*0.75) return 1;
 else
 return 0;
}
index Hash(int key,int table_size)
{
 return key % table_size;
}
Hashtable Create_table(int table_size)
{
 Hashtable H;
 if(table_size < MINSIZE)
 {
 printf("Table size too small");
 return NULL;
 }
 H=(Hashtable)malloc(sizeof(struct H_table));
 if(H==NULL)
 {
 printf("Out of space");
 return NULL;
 }
 H->table_size = next_prime(table_size);
 H->cell_array = (cell*) malloc(sizeof(cell) * H->table_size); 
 if(H->cell_array==NULL)
 {
 printf("Out of space");
 return NULL;
 } 
 for(int i=0;i< H->table_size;i++)
 {
 H->cell_array[i].info=Empty;
 }
 return H; }
position find(int key,Hashtable H)
{
 position cur;
 int collision=0;
 cur=Hash(key,H->table_size);
 while(H->cell_array[cur].info!=Empty && H->cell_array[cur].data != key)
 {
 cur=(cur+1) % H->table_size;
 }
 return cur;
}
void insert(int key,Hashtable H)
{
 position pos=find(key,H);
 if(H->cell_array[pos].info!=Legitimate)
 {
 H->cell_array[pos].info=Legitimate;
 H->cell_array[pos].data=key;
 }
}
Hashtable Rehash(Hashtable H1)
{
 Hashtable H2=Create_table(H1->table_size*2);
 for(int i=0;i<H1->table_size;i++)
 {
 if(H1->cell_array[i].info==Legitimate)
 insert(H1->cell_array[i].data,H2);
 }
 return H2;
}
void display(Hashtable H)
{
 for(int i=0;i<H->table_size;i++)
 {
 printf("%d => %d\n",i,H->cell_array[i].data);
 }
}
void main()
{
 int size;
 printf("Enter size of the table: ");
 scanf("%d",&size);
 Hashtable H1=Create_table(size);
 printf("Hash table size: %d\n",H1->table_size);
 if(H1!=NULL)
 {
 int d,op;
 do
 {
 printf("\nChoose operation: 1) Insert 2) Display: ");
 scanf("%d",&op);
 switch(op)
 {
 case 1:
 if(isFull(H1))
 {
 printf("\nRehashing the table from %d to",H1->table_size);
 H1=Rehash(H1);
 printf(" %d...\n\n",H1->table_size);
 }
 printf("Enter the data to be inserted: ");
 scanf("%d",&d);
 insert(d,H1);
 break; 
 case 2:
 printf("\nLinear probing hash table\n\n");
 display(H1);
 break;
 
 case 0:
 printf("Operation terminated");
 break; 
 default:
 printf("Invalid operation...\n");
 } 
 }while(op);
 }
}