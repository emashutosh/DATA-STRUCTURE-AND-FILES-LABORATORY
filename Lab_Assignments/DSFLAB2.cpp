#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int priority;
	char name[20];
	struct node *next;
};

class queue
{
 node *front;
 public :
 queue()
  {
   front=NULL;	
  }	
 void insert();
 void remove();
 void display(); 
};


int main()
{
	int choice;
	queue q;
	do
	{
	cout<<"Enter choice : 1. Insert 2. Remove 3. Display 4.Exit\n";
	cin>>choice;
	 switch(choice)
	 {
	  case 1: q.insert();
	          break;
	  case 2: q.remove();
	          break;
	 case 3: q.display();
	          break;
    case 4: cout<<"Exit\n";
	          break;
	default: cout<<"Wrong choice";
	          break;			  		  		  	
	 } 
    }while(choice!=4);
}

void queue::insert()
{
	node *newnode=new  node;
	node *temp, *prev;
	cout<<"Enter name of patient\n";
	cin>>newnode->name;
	cout<<"Enter the priority from 1. General Checkup 2. Non-Serious 3. Serious\n";
	cin>>newnode->priority;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=newnode;
	}
	else
	{
		temp=front;
		while(temp!=NULL && newnode->priority <= temp->priority)
		{
		 prev=temp;
		 temp=temp->next;	
		}
    //add at begining
	    if(temp==front)	
		{
		 newnode->next=front;
		 front=newnode;	
		}	
	//add in between or at end	
	    else
	    {
	    	newnode->next=temp;
	    	prev->next=newnode;
		}
	}
}
void queue::remove()
{
	node *temp;
	temp=front;
	if(front==NULL)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
	switch(temp->priority)
	{
		case 1: cout<<"General Checkup\n";
		        break;
			case 2: cout<<"Non-Serious\n";
		        break;
					case 3: cout<<"Serious\n";
		        break; 
			default: cout<<"Unknown";
			   break;	       
	}
	front=front->next;
	cout<<"Patient Name who got treatment is"<<temp->name<<endl;
	free(temp);
  }
}
void queue::display()
{
node *temp;
temp=front;
 if(front==NULL)
  {
		cout<<"Queue is Empty\n";
  }
else
{  
cout<<"Patients waiting in queue\n";
cout<<"\nName"<<"\tPriority\n";
while(temp!=NULL)
{
	cout<<temp->name<<"\t"<<temp->priority<<endl;
	temp=temp->next;
}
}
}


