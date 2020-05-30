#include<iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;	
};

class Btree
{
 node *root;
 public:
     Btree()
     {
     	root=NULL;
	 }
	void insert(node *root);
	void display(node *root);
	int MaxDepth(node *root);
	void LeafNode(node *root);
	node *copy(node *root);
};

int main()
{
	int choice,x;
	node *root;
	root=new node;
	node *clone;
	Btree b;
	cout<<"Enter data for root node\n";
	cin>>root->data;
	root->left=NULL;
	root->right=NULL;
	do
	{
	cout<<"\nEnter choice 1. Create  2. Display Preorder 3. Find Depth 4. Display LeafNodes 5.Copy tree 6.Exit\n";
	cin>>choice;
   	switch(choice)
   	{
   	case 1:b.insert(root);
           break;
	case 2:b.display(root);
	       break;
	case 3: x=b.MaxDepth(root);
	        cout<<"Depth of Binary Tree="<<x<<endl;
	       break;   
    case 4:b.LeafNode(root); 
	        break;
	case 5:	cout<<"copied tree is\n";
        	clone=b.copy(root);
         	b.pre(clone);
	        break;   
	case 6: cout<<"Exit\n";
	        break;
	default: cout<<"Wrong choice\n";		       
    }
    }while(choice !=6);
return 0;	
}

void Btree :: insert(node *root)
{
 node *temp;
 char side,op;
node *newnode;
do
{
   newnode=new node;
   cout<<"\n  Enter data=>";
   cin>>newnode->data;
   newnode->left=NULL;
   newnode->right=NULL;

temp=root;
while(1)
{
cout<<"\n  Enter the side for left press 'l' & for right 'r'=>";
cin>>side;
   if(side=='l')
   {
	if(temp->left==NULL)
	{
	   temp->left=newnode;
	   break;
	}
	else
	   temp=temp->left;
   }
   else
   {
	if(side=='r')
	{
	   if(temp->right==NULL)
	   {
	     temp->right=newnode;
	     break;
	   }
	   else
	     temp=temp->right;
	}
   }
}

cout<<"\n  Do u want to continue?";
cin>>op;
}while(op=='y');
}

void Btree :: display(node *root)
{
	node *temp;
	temp=root;
if(temp!=NULL)
{
	cout<<temp->data<<"\t";
	display(temp->left);
	display(temp->right);
}
}

int Btree :: MaxDepth(node *root)
{
 node *temp;
 int Ldepth, Rdepth;
 temp=root;
  if(temp!=NULL)
  {
   Ldepth=MaxDepth(temp->left);
   Rdepth=MaxDepth(temp->right);
  if(Ldepth>Rdepth)
    return (Ldepth+1);
  else
   return (Rdepth+1);	 
  } 		
}

void Btree :: LeafNode(node *root)
{
 node *temp;
 temp=root;
  if(temp->left==NULL && temp->right==NULL)
  {
  cout<<temp->data<<"\n"; 
  } 
  else
  {
  if(temp->left)
  LeafNode(temp->left);
  if(temp->right)
  LeafNode(temp->right);
  }		
}

node *Btree :: copy(node *root)
{
 node *temp,*newnode;
 temp=root;
  if(temp!=NULL)
  {
   newnode=new node;
   newnode->left=copy(temp->left);
   newnode->right=copy(temp->right);
   newnode->data=temp->data;
   return(newnode);
  }	
  else
   return NULL;	
}
