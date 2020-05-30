		//MST using Prim's Algorithm
#include<iostream>
#include<string.h>
using namespace std;

class Graph
{
	char Vnames[10][10];
	int cost[10][10],n;
public:
	Graph();
	void creat_graph();
	void display();
	int Position(char[]);
	void prims();
};
Graph::Graph()
{
n=0;
for(int i=0;i<10;i++)
for(int j=0;j<10;j++)
 {
 cost[i][j]=999;
 }
}
void Graph::creat_graph()
{
char ans,Start[10],End[10];
int wt,i,j;
cout<<"Enter number of ndes";
cin>>n;
cout<<"\n Enter vertex name:";
for(i=0;i<n;i++)
          cin>>Vnames[i];
do
{
cout<<"\nEnter Start and end point of edge";
cin>>Start>>End;
cout<<"Enter weight";
cin>>wt;
i=Position(Start);
j=Position(End);
cost[i][j]=cost[j][i]=wt;
cout<<"\nMore Edges ";
cin>>ans;
}while(ans=='y' || ans=='Y');
}
void Graph::display()
{
int i,j;
for(i=0;i<n;i++)
{
 cout<<"\n";
 for(j=0;j<n;j++)
	 cout<<"\t"<<cost[i][j];
}
}
int Graph::Position(char key[10])
{
int i;
for(i=0;i<n;i++)
	if(strcmp(Vnames[i],key)==0)
		return i;
return -1;
}
void Graph::prims()
{
 int cnt=1,b,i,j,x,y,Total_cost=0,min,v[10]={0};
 char start[10];
 cout<<"\nStarting node=";
 cin>>start;
 x=Position(start);
 v[x]=1;
 while(cnt<n)
 {
 min=999;
 for(i=0;i<n;i++)
 {
 	if(v[i]==1)
 	{
		 for(j=0;j<n;j++)
		 {
			  if(cost[i][j]<min && v[j]==0)
			  {
				 min=cost[i][j];
				 x=i;
				 y=j;
			  }
		 }
	 }
}
cout<<"\n"<<Vnames[x]<<"\t"<<Vnames[y]<<"\t"<<min;
Total_cost=Total_cost+min;
cost[x][y]=cost[y][x]=999;
v[y]=1;
cnt++;
}
cout<<"\nTotal cost=>"<<Total_cost;
}
int main()
{
Graph ob;
ob.creat_graph();
ob.display();
ob.prims();
}












