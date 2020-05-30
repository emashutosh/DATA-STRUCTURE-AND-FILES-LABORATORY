#include<iostream>
#include<fstream>
#define size 10
using namespace std;


struct student 
{
int rn;
char name[20];
};

class DAFile
{
char fname[20];
public:
void create(int data[size],int flag[size],int chain[size]);
void Hashing(int i,int data[size],int flag[size],int chain[size],int rn);
void display(int data[size],int flag[size],int chain[size]);
void add(int n,int data[size],int flag[size],int chain[size]);
int search(int data[size],int flag[size],int chain[size],int rn);
//void print();
void modify(int data[size],int flag[size],int chain[size],int rn);
};

int n=0;

int main()
{
int choice,i,rn,loc;
int k, data[size],flag[size],chain[size];
student s;
DAFile d;
for(k=0; k<size;k++)
{
flag[k]=0;
chain[k]=-1;
}
  do
  {
   cout<<"Enter your choice from\n";
   cout<<"1. Create 2.Display 3.Search 4.Add 5.Modify 6.exit\n";
   cin>>choice;
   switch(choice)
     {
   case 1:d.create(data,flag,chain);
          break;
   case 2: d.display(data, flag, chain);
          break;
     case 3: cout<<"Enter roll no to be searched \n";
          cin>>rn;
        loc=d.search(data, flag, chain,rn);
          if(loc==-1)
          cout<<"No.found\n";
          else
          cout<<"RollNo found at location:"<<loc<<"\n";
          break;  
        
   case 4: d.add(n,data, flag, chain);
         break;
    case 5: cout<<"Enter roll no to be modofied \n";
          cin>>rn;
        d.modify(data, flag, chain,rn);
          break;
    case 6:cout<<"Exit\n";   
         break; 
   default:cout<<"Wrong Choice\n";
     }      
  }while(choice !=6);
return 0;
}

void DAFile :: create(int data[size],int flag[size],int chain[size])
{
 ofstream fp;
 student s;
DAFile obj;
int pos;
char option;
cout<<"Enter file name\n";
cin>>fname;
fp.open(fname);
do
{
 cout<<"Enter student roll no & Name\n";
 cin>>s.rn>>s.name;
obj.Hashing(n,data,flag,chain,s.rn);
fp.write((char*)(&s), sizeof(s));
cout<<"Do you want to insert more?(y/n):\n";
cin>>option;
}while(option=='y');
 fp.close();
//print();
}

void DAFile::Hashing(int i,int data[size],int flag[size],int chain[size],int rn)
{
//int data[size], flag[size], chain[size];
int pos,j;
pos=rn%size;
while(flag[pos]==1 && i<size)
{
  if(data[pos]%size==rn%size)
  break;
 i++;
pos=(pos+1)%size;
}
if(i==size)
{
cout<<"Table is full\n";
return;
}

while(chain[pos]!=-1)
pos=chain[pos];

j=pos;
while(flag[j]==1 && i<size)
{
j=(j+1)%size;
i++;
}
if(i==size)
{
cout<<"Hash table is full\n";
return;
}
data[j]=rn;
flag[j]=1;
if(j!=pos)
chain[pos]=j;
}

void DAFile:: display(int data[size],int flag[size],int chain[size])
{
ifstream fp;
int i;
student s;
fp.open(fname);
cout<<"Index\troll no \t chain\n";
for(i=0; i<size; i++)
{
if(flag[i]==1)
cout<<i<<"\t"<<data[i]<<"\t"<<chain[i]<<"\n";
else
cout<<i<<"\t"<<"--"<<"\t"<<chain[i]<<"\n";
}
 
}
/*void DAFile::print()
{
ifstream fp;
student s;
fp.open(fname);
cout<<"RollNo\t Name\n";
fp.read((char*)(&s), sizeof(s));
while(!fp.eof())
{
 cout<<s.rn<<"\t"<<s.name<<"\n";
 fp.read((char*)(&s), sizeof(s));
}
fp.close();
}
*/
void DAFile :: add(int n,int data[size],int flag[size],int chain[size])
{
 ofstream fp;
 student s;
DAFile obj;
int pos;

fp.open(fname, ios::app);

cout<<"Enter more student info :\n";
cout<<"Enter Roll no & Name\n";
cin>>s.rn>>s.name;
obj.Hashing(n,data,flag,chain,s.rn);
fp.write((char*)(&s), sizeof(s));

 fp.close();
//print();
}
int DAFile::search(int data[], int flag[], int chain[],int rn)
{
int i=0, j;
j=rn%size;
while(i<=size)
{
 if(data[j]==rn)
  {
    return j;
    break;
   }
  else
   {
    j=(j+1)%size;
    }
i++;
}
return -1;
}

void DAFile::modify(int data[], int flag[], int chain[],int rn)
{
int i=0, j;
ifstream fp2;
j=rn%size;
while(i<=size)
{
 if(data[j]==rn)
  {
     flag[j]=0;
    add(j, data, flag, chain);
    break; 
   }
  else
   {
    j=(j+1)%size;
    }
i++;
}
}