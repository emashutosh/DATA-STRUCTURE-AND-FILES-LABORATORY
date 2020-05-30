#include<iostream.h>
#include<string.h>
#include<conio.h>

class graph
{
 char Vnames[10][10];
 int i,j,n,cost[10][10],flag[10];
public:
 graph();
 int Position(char key[10]);
 void creat_graph();
 void display();
 void Dijkstra();
};

graph::graph()
{
n=0;
for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	 {
		 if(i==j)
			 cost[i][j]=0;
		 else
			 cost[i][j]=999;
	 }
}


void graph::creat_graph()
{
char ans,Start[10],End[10];
int wt,i,j;
cout<<"Enter number of nodes";
cin>>n;
cout<<"\n Enter vertex name:";
for(i=0;i<n;i++)
{
	cin>>Vnames[i];
	flag[i]=0;
}
do
{
cout<<"\nEnter Start and end point of edge";
cin>>Start>>End;
cout<<"Enter weight";
cin>>wt;
i=Position(Start);
j=Position(End);
cost[i][j]=cost[j][i]=wt;
//cost[i][j]=wt;
cout<<"\nMore Edges ";
cin>>ans;
}while(ans=='y' || ans=='Y');
}

void graph::display()
{
int i,j;
 for(i=0;i<n;i++)
	{
	 cout<<"\n";
	 for(j=0;j<n;j++)
		 cout<<"\t"<<cost[i][j];
	}
}

int graph::Position(char key[10])
{
for(int i=0;i<10;i++)
	if(strcmp(Vnames[i],key)==0)
		return i;
return -1;
}

void graph::Dijkstra()
{
int x,dis[10]={0},flag[10]={0};
char visit[10][10]={0};
int i,j,v,sor,min,mnode,k;
char Start[10];

cout<<"\nEnter Source: ";
cin>>Start;
sor=Position(Start);
flag[sor]=1; //init.
dis[sor]=0;

for(v=0;v<n;v++)  // initial distance matrix
	 dis[v]=cost[sor][v];

//visit[0]=sor;
strcpy(visit[0],Vnames[sor]);

i=0;
cout<<"\n";
for(x=0;x<=i;x++)
cout<<"  "<<visit[x];
for(x=i+1;x<n;x++)
cout<<"  -";
cout<<"  : ";
for(x=0;x<n;x++)
cout<<"  "<<dis[x];

/*main loop*/
for(i=1;i<n;i++)
{   min=999;

    for(k=0;k<n;k++)
    {
	 if(flag[k]==0 && dis[k] < min) //find min. distance
	 {
		   min=dis[k];
		   mnode=k;
	 }
     }
     flag[mnode]=1;
//   visit[i]=mnode;
     strcpy(visit[i],Vnames[mnode]);
  for(j=0;j<n;j++)
   {  if(flag[j]==0 && cost[mnode][j]!=999)
	{  if(dis[j]>dis[mnode]+cost[mnode][j])
	     dis[j]=dis[mnode]+cost[mnode][j];
	 }
     }
cout<<"\n";
for(x=0;x<=i;x++)
 cout<<"  "<<visit[x];
for(x=i+1;x<n;x++)
cout<<"  -";
cout<<"  : ";
for(x=0;x<n;x++)
cout<<"  "<<dis[x];
getch();
}
}

void main()
{
graph obj;
clrscr();
obj.creat_graph();
obj.display();
obj.Dijkstra();
getch();
}










