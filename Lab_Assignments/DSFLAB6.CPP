#include<iostream>
#include<conio.h>
#include<string.h>
#define MAX 10
using namespace std;

class Graph
{
    struct node
     {
	int Visit;
	char Name[10],dob[10];
	int no_Of_comments;
	node *next;
	node()
	{
	   next=NULL;
	   Visit=-1;
	   no_Of_comments=0;
	}
     };
    node Head[10];
    int n;
    public:
	   void Create();
	    int Position(char[]);
	    void Display();
	    void BFS();		//maximum and minimum comment
	    void DFS();		//user having birthday in given month
	    void friends();		//maximum friends
};

int Graph::Position(char key[10])
{
for(int i=0;i<10;i++)
	if(strcmp(Head[i].Name,key)==0)
	    return i;
return -1;
}

void  Graph::Create()
{
node *Node1,*Node2,*Temp;
int i,Pos;
char Friend[10],op;
cout<<"\nEnter number of nodes=";
cin>>n;

for(i=0;i<n;i++)
{
  cout<<"\nEnter User Name: ";
  cin>>Head[i].Name;
  cout<<"\nEnter date of Birth(mm/dd/yyyy): ";
  cin>>Head[i].dob;
  cout<<"\nNumber of Comments";
  cin>>Head[i].no_Of_comments;
}

for(i=0;i<n;i++)
{
cout<<"Enter Friend list of "<<Head[i].Name;
do
{
cout<<"\nEnter Frind Name";
cin>>Friend;
Pos=Position(Friend);

Node1=new node;
Node1->Visit=Pos;
for(Temp=&Head[i];Temp->Visit!= Pos && Temp->next!=NULL;Temp=Temp->next);
	if(Temp->Visit!=Pos)
		Temp->next=Node1;
Node2=new node;
Node2->Visit=i;
for(Temp=&Head[Pos];Temp->Visit!=i && Temp->next!=NULL;Temp=Temp->next);
	 if(Temp->Visit!=i)
		Temp->next=Node2;

cout<<"Add more Edge for Node....(Y/N)";
cin>>op;
}while(op=='y');
}
}

void Graph::Display()
{
node *Temp;
cout<<"\nHead Nodes";
for(int i=0;i<n;i++)
{
    cout<<" \nName: "<<Head[i].Name;
    cout<<" \nDOB: "<<Head[i].dob;
    cout<<" \tNo of Comments:  "<<Head[i].no_Of_comments;
    cout<<" \n Friend list: ";
    Temp=Head[i].next;
    while(Temp!=NULL)
    {
	 cout<<Head[Temp->Visit].Name<<"\t";
	 Temp=Temp->next;
    }
}
}

void Graph::BFS()
{
node *Temp;
int F=0,R=0,i,Q[10],Max,Min,Max_User,Min_User;
char S[10];
for(i=0;i<n;i++)
	Head[i].Visit=0;
Head[0].Visit=1;
Q[0]=0;
Max=Min=Head[0].no_Of_comments;
Max_User=Min_User=0;
cout<<"\nBFS: \n";
while(F<=R)
  {
     i=Q[F++];
     cout<<Head[i].Name;
     Temp=Head[i].next;
     while(Temp!=NULL)
       {
	  i=Temp->Visit;
	  if(Head[i].Visit!=1)
	       {
		 if(Max<Head[i].no_Of_comments)
		    { Max_User=i; Max=Head[i].no_Of_comments;}
		 else if(Min>Head[i].no_Of_comments)
			 { Min_User=i; Min=Head[i].no_Of_comments;}
		 Q[++R]=i;
		 Head[i].Visit=1;
	       }
	 Temp=Temp->next;
       }
  }
 cout<<"\n\" "<<Head[Max_User].Name<<" \"has post Maximum Comments";
 cout<<"\n\" "<<Head[Min_User].Name<<" \"has post Minimum Comments";
}

void Graph::DFS()
{
int i,Top=-1,Stk[10];
node *Temp;
char Month[2];
for(i=0;i<n;i++)
	Head[i].Visit=0;

cout<<"\nEnter Month: ";
cin>>Month;
Head[0].Visit=1;
Stk[++Top]=0;
while(Top>-1)
  {
    i=Stk[Top--];
    if(strncmp(Month,Head[i].dob,2)==0)
      cout<<"\n"<<Head[i].Name;
    Temp=Head[i].next;
    while(Temp!=NULL)
      {
	 i=Temp->Visit;
	 if(Head[i].Visit!=1)
	   {
	       Stk[++Top]=Temp->Visit;
	       Head[i].Visit=1;
	   }
	 Temp=Temp->next;
      }
  }
}

void Graph::friends()
{
  int i,J,count=0,Max=0,Top=-1,Stk[10],Pos;
  node *Temp;
  for(i=0;i<n;i++)
	Head[i].Visit=0;

  Head[0].Visit=1;
  Stk[++Top]=0;
  while(Top>-1)
   {
    i=Stk[Top--];
    Temp=Head[i].next; count=0;
    while(Temp!=NULL)
      {  count++;
	 J=Temp->Visit;
	 if(Head[J].Visit!=1)
	   {
	       Stk[++Top]=Temp->Visit;
	       Head[J].Visit=1;
	   }
	 Temp=Temp->next;
      }
     if(count>Max)
     {
	  Max=count;
	  Pos=i;
     }
  }
cout<<"\nMaximum Friend User:"<<Head[Pos].Name;
}

int main()
{
  Graph G;
 // clrscr();
  G.Create();
  G.Display();
 G.BFS();
 G.DFS();
 G.friends();
 return 0;
}
