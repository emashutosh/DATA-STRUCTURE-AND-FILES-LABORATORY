#include<iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;	
};

int depth(node *root);
void displaylevel(node *root, int level);

class BStree
{
 node *root;
 public:
     BStree()
     {
     	root=NULL;
	 }
	void insert(node *root);
	void display(node *root);
	void search(node *root);
	node *mirror(node *root);
	void levelwise(node *root, int n);
};



int main()
{
	int choice,n;
	node *root;
	root=new node;
	node *clone;
	BStree b;
	cout<<"Enter data for root node\n";
	cin>>root->data;
	root->left=NULL;
	root->right=NULL;
	do
	{
	cout<<"\nEnter choice 1. Create  2. Display Preorder 3. Search 4. mirror image 6.Exit\n";
	cin>>choice;
   	switch(choice)
   	{
   	case 1:b.insert(root);
           break;
	case 2:b.display(root);
	       break;
	case 3: b.search(root);
	        	       break;   
   case 4:	clone=b.mirror(root); 
            cout<<"Mirror image of tree is=\n";
            b.display(clone);
            break;
	case 5:	n=depth(root);
	        b.levelwise(root, n);
	        break;   
	case 6: cout<<"Exit\n";
	        break;
	default: cout<<"Wrong choice\n";		       
    }
    }while(choice !=6);
return 0;	
}

void BStree :: insert(node *root)
{
 node *temp;
 char op;
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
   if(newnode->data<=temp->data)
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
	if(newnode->data>temp->data)
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

void BStree :: display(node *root)
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

void BStree :: search(node *root)
{
	int x, flag=0;
	node *temp;
	temp=root;
cout<<"Enter the value to be searched\n";
cin>>x;
while(temp!=NULL)
{
  if(x==temp->data)
  {
  	flag=1;
  	break;
  }
  else
  if(x<temp->data)
  temp=temp->left;
  else
  temp=temp->right;
}
if(flag==1)
cout<<x<<"\tValue is found found in BST\n";
else
cout<<x<<"\tValue not found\n";
}

node *BStree :: mirror(node *root)
{
	node *temp1, *temp2;
	temp1=root;
	if(temp1!=NULL)
	{
		temp2=temp1->left;
		temp1->left=temp1->right;
		temp1->right=temp2;
	if(temp1->left!=NULL)
	mirror(temp1->left);
	if(temp1->right!=NULL)
	mirror(temp1->right);
   }
 return temp1;  
}
/*
node *BStree :: delet(node *root, int y)
{
  if(root==NULL) return root;
  else
  if(y<root->data)
  root->left=delet(root->left, y);
  else
  if(y>root>data)
  root->right=delet(root->right,data);
  else
  {
  	//to delete leaf node
  	if(root->left==NULL && root->right==NULL)
  	{
	  delete root;
  	root=NULL;
    return root;
	}
	//to delet node ..with only one child
	else
	if(root->left==NULL)
	{
		node *temp=root;
		root=root->right;
		delete temp;
		return root;
	}
	else
	if(root->right==NULL)
	{
		node *temp=root;
		root=root->left;
		delete temp;
		return root;
	}
	//To delete node...with two childs
	else
	{
	node *temp=FindMin(root->right);
	root->data=temp->data;
	root->right=delet(root->right, y)	
	}
  }
  */
  int depth(node *root)
  {
   node *temp;
   int Ldepth, Rdepth;
   temp=root;
   if(temp!=NULL)
   {
   	Ldepth=depth(temp->left);
   	Rdepth=depth(temp->right);
   }    	
   if(Ldepth>Rdepth)
   return (Ldepth+1);
   else
   return (Rdepth+1);
  }
  
  void BStree :: levelwise(node *root, int n)
  {
  	int level;
  	node *temp=root;
  	for(level=1; level<=n; level++)
  	{
  	  displaylevel(temp, level);
	}   	
  }
  
  void displaylevel(node *temp, int level)
  {
  	if(temp==NULL)
  	return;
  	if(level==1)
		cout<<temp->data<<"\t";
	  else
	  if(level>1)
	  {
	  	displaylevel(temp->left, level-1);
	  	displaylevel(temp->right, level-1);
	  }		
  }
