#include<iostream>
#include<algorithm>
#include<new>

using namespace std;


struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *p;
};

struct node *root=NULL;


struct node * t_min(struct node *temp){
	while(temp->left!=NULL)
	temp=temp->left;
	return temp;
}

struct node * t_max(struct node *temp){
	while(temp->right!=NULL)
	temp=temp->right;
	
	return temp;
}

void transplant(struct node * u,struct node *v){
	if(u.p==NULL)
		root=v;
	else if(u==u.p.left)
	u.p.left=v;
	else
	u.p.right=v;
	if(v!=NULL)
	v.p=u.p;
}


int del(struct node *temp){
	if(temp->left==NULL)
		transplant(temp,temp->right);
	else if(temp->right==NULL)
		transplant(temp,temp->left);
	else{
		struct node * y =t_min(temp->right);
		if(y.p!=temp){
			transplant(y,y->right);
			y.right=z.right;
			r.right.p=y;
		}
		transplant(z,y);
		y.left=z.left;
		y.left.p=y;
	}	
				
}




/*int succ(struct node * temp){
	if(temp->right!=NULL)
}*/


void inorder(struct node * temp){
	if(temp!=NULL){
		inorder(temp->left);
		cout<<temp->data<<' ';
		inorder(temp->right);
	}
}

struct node * insert(int a){
	struct node *temp,*x,*y;
	temp=new node();
	temp->data=a;
	temp->left=NULL;
	temp->right=NULL;
	temp->p=NULL;
	y=NULL;
	x=root;
	while(x!=NULL){
		y=x;
		if(temp->data<x->data){
			x=x->left;
		}
		else
			x=x->right;	
	}
	temp->p=y;
	if(y==NULL)
		root=temp;
	else if(temp->data<y->data)	
		y->left=temp;
	else
		y->right=temp;		
		
}



int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		insert(a);
	}	
	inorder(root);
	cout<<t_min(root)<<'\n';
	cout<<t_max(root)<<'\n';
	
}
