//AVL.cpp
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include "AVL.h"

using namespace std;

// Helper function to find the height
// of a given node in the binary tree
int AVL::findHeightUtil(node* root, char* x,
                   int& height)
{
    // Base Case
    if (root == NULL) {
        return -1;
    }
 
    // Store the maximum height of
    // the left and right subtree
    int leftHeight = findHeightUtil(
        root->left, x, height);
 
    int rightHeight
        = findHeightUtil(
            root->right, x, height);
 
    // Update height of the current node
    int ans = max(leftHeight, rightHeight) + 1;
 
    // If current node is the required node
    if (strcmp(root->key,x)==0)
        height = ans;
 
    return ans;
}
 
// Function to find the height of
// a given node in a Binary Tree
int AVL::findHeight(node* root, char* x)
{
    // Store the height of
    // the given node
    int h = -1;
 
    // Stores height of the Tree
    int maxHeight = findHeightUtil(root, x, h);
 
    // Return the height
    return h;
}

void AVL::grandchild(node*  p)
{
	 int rrh,rlh,llh,lrh;
	if (p!=NULL)
	{
	      cout<<"\n\n\n  inside node   "<<p->key;cout<<"            heights:  ";
		  node* r=p->right;
	      node* l=p->left;
	      if(r!=NULL)
	      {
	      	 node* rr=r->right;
	      	 if(rr!=NULL)
	      	 {
			        //rrh=rr->height;
			        
			        rrh=findHeight(p,rr->key);
			        cout<<rrh<<"  rrh              ";
			        
			   }
	      	 node* rl=r->left;
	      	  if(rl!=NULL)
	      	 {
	      	 	  //rlh=rl->height;
	      	 	   rlh=findHeight(p,rl->key);
	      	 	   cout<<rlh<<" rlh                ";
	      	 }
			        
		  }
		  if(l!=NULL)
	      {
	      	node* lr=l->right;
	      	 if(lr!=NULL)
	      	 {
			       
			        //lrh=lr->height;
			         lrh=findHeight(p,lr->key);
			          cout<<lrh<<" lrh                  ";
			   }
	      	 node* ll=l->left;
	      	  if(ll!=NULL)
	      	 {
			        //llh=ll->height;
			         llh=findHeight(p,ll->key);
			          cout<<llh<<" llh              ";
		      }
		  }
	      
	      if(llh==lrh)
	      {
	      	if(rlh==rrh)
	      	{
	      		if(rrh==lrh)
	      		{
	      			cout<<" all of key: "<<p->key<<" address: "<<p<<"  's grandchildren are at height "<<rrh;
				  }
			  }
		  }
	      
	 grandchild(p->left);
	  grandchild(p->right);
	}
}

		
int AVL::count(node *p)
{
    int c =  1;             //Node itself should be counted
    if (p ==NULL)
        return 0;
    else
    {
        c += count(p->left);
        c += count(p->right);
        return c;
    }
}
void AVL::preorder(node*  p)
{
	if (p!=NULL)
	{
	    cout<<"         "<<p->key;
	  preorder(p->left);
	  preorder(p->right);
	}
}
		
  void AVL::printlongestpath(node*  t)  
  {
  	int rh=-1,lh=-1;
  	    if(t==NULL)
  	    {
  	    	return;
		  }
		  cout<<"  "<<t->key<<"  ";
		  if(t->right!=NULL)
		  {
		        rh=t->right->height;
	       }
	       if(t->left!=NULL)
	       {
		       lh=t->left->height ;
			}
			if(rh>lh)
			{
				 printlongestpath(t->right);
			}
			else
			{
				printlongestpath(t->left);
			}
  	    
  }



int AVL::depth(node* root, char* x)
{
 
    if (root == NULL)
        return -1;
 
   
    int dist = -1;
 
   
    if (strcmp(root->key,x)==0 || (dist = depth(root->left, x)) >= 0 || (dist = depth(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;
}

int AVL :: height(node*& T)
{
	int lh , rh;
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->height;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->height;
	if(lh>rh)
		return lh;
	return rh;
}

int AVL :: BF(node*& T)
{
	int lh , rh;
	if(T==NULL)
		return 0;
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->height;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->height;
	return (lh-rh);
}

node*& AVL :: right_right(node *&T)
{
	T=left_rotate(T);
	return T;
}
node*& AVL :: left_left(node *&T)
{
	T=right_rotate(T);
	return T;
}

node*& AVL :: left_right(node*& T)
{
		T->left=left_rotate(T->left);
		T=right_rotate(T);
		return T;
}

node*& AVL :: right_left(node*& T)
{
		T->right=right_rotate(T->right);
		T=left_rotate(T);
		return T;
}

node* AVL :: right_rotate(node*& x)
{
	node *y ;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=height(x);
	y->height=height(y);
	return y;
}

node* AVL :: left_rotate(node*& x)
{
	node *y ;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->height=height(x);
	y->height=height(y);
	return y;
}

node*& AVL :: min(node *&q)
{
	while(q->left != NULL)
	{
		q = q->left;
	}
	return q;
}
node* AVL :: insert(char* key , char* value , node* T)
{

	int cmp;
	if(T==NULL)
	{
		
		T=new node;
		T->left=NULL;
		T->right=NULL;
		strcpy(T->key , key);
		strcpy(T->value , value);
	

	}
	else
	{
		cmp=strcasecmp( key , T->key);
		if(cmp<0)
			{
				T->left=insert(key ,value,T->left);
				if(BF(T)==2)
				{
					if(strcasecmp( key , T->left->key)<0)
						T=left_left(T);
					else
						T=left_right(T);
				}
			}

		else if(cmp>0)
		{
			T->right =insert(key ,value ,T->right);
			if(BF(T)==-2)
			{
				if(strcasecmp( key , T->right->key)>0)
					T=right_right(T);
				else
					T=right_left(T);
			}

		}
		else
		{
			cout<<"key already exists"<<endl;
		}
	}
		T->height=height(T);

return T;
}

void AVL ::inorder(node* head)
{

	if(head!=NULL)
	{
		inorder(head->left);
		cout<<"\n\n     key   :  "<<head->key<<"          value   :   "<<head->value<<"\n\n";
		inorder(head->right);
	}

}
int AVL :: search(node* head , char *str)
{

	while(head!=NULL)
	{
		int cmp=strcasecmp( str , head->key);
		if(cmp==0)
		{
			cout<<"\n\n\n    found entry   \n\n";
			cout<<"\n\n    key is :\t"<<head->key<<endl;
			
			head->freq++;
			cout<<"\n\n    value is :\t"<<head->value<<endl;
			
			return 1;

		}
		else if(cmp<0)
			{
				head=head->left;
			}
		else if(cmp>0)
		{
			head=head->right;
		}

	}

	return -1;
}


void AVL :: searchpartial(node*& head , char *str)
{

	    if(head==NULL) return; 
	    else
	    {int i=0,count=0;
		while(str[i]!='\0' && (head->key)[i]!='\0' )
		{
			if(str[i]==(head->key)[i]) 
			{
				count++;
			}
			i++;
		}

		if(count>=3)
		{
			cout<<"\n\n            "<<head->key<<"\n";
			
		}
		searchpartial(head->right,str);
		searchpartial(head->left,str);
	}
	      
}

void AVL::findauntanddel(node*&  p,char* val)
{
	if (p!=NULL)
	{
	     findaunt(p,val);
	     p=delete_node(p,val);
	}
}


node* AVL :: delete_node(node* T , char* str )
{
	node *temp;
	int cmp;
	cmp=strcasecmp(str , T->key); 
	if(T==NULL)
	{
			cout<<"no entries created"<<endl;
			return T;
	}

	else if(cmp<0)
		{
			T->left=delete_node(T->left , str);
			if(BF(T)==-2)
			{
				if(BF(T->right)<=0)
				T=right_right(T);
				else
				T=right_left(T);
			}
		}

		else if(cmp>0)
				{
					T->right=delete_node(T->right , str);
					if(BF(T)==2)
					{
						if(BF(T->left)>=0)
						T=left_left(T);
						else
						T=left_right(T);
					}
				}
		else
		{
			if(T->right!=NULL)
			{
				temp=T->right;
				while(temp->left!=NULL)
					temp=temp->left;
				strcpy(T->key , temp->key);
				T->freq=temp->freq;
				strcpy(T->value , temp->value);
				T->right=delete_node(T->right , temp->key);
				if(BF(T)==2)
				{
					if(BF(T->left)>=0)
						T=left_left(T);
					else
						T=left_right(T);

				}
			}
			else
			{
				return T->left;
				cout<<"\nsorry entered element not found\n"<<endl;

			}

		}
	T->height=height(T);
	return T;
}

void AVL :: update(node*& head ,char *key)
{
		char new_value[256];
	if(head==NULL)
	{
		return ;
	}
	else{
	

	
		
		if(strcmp(key,head->key)==0)
		{
			cout<<"\n\n\n      Enter the  new value      ";
			cout<<"       ";cin>>new_value;
			strcpy(head->value , new_value);
			cout<<"\n\n       updated sucessfully\n\n";
			return;
			
		
		}
	
			update(head->right,key);
			update(head->left,key);

	
}

}





    void AVL::tree_to_vect(node* a,vector<node*>& temp)
    {
	       
	       if(a==NULL) return;
	       temp.push_back(a);
	       tree_to_vect(a->right,temp);
	       tree_to_vect(a->left,temp);
	       
	}
	
	
	
	
	
	
	

vector<node*> AVL::longestPath(node* root)
{
 
    
    if (root == NULL) {
        vector<node*> temp
            = {};
        return temp;
    }
 
   
    vector<node*> rightvect
        = longestPath(root->right);
 
    
    vector<node*> leftvect
        = longestPath(root->left);
 
    
    if (leftvect.size() > rightvect.size())
        {
		leftvect.push_back(root);
        return leftvect;
    }
   else
        {
		rightvect.push_back(root);
        return rightvect;
    }
 
    
   
}



vector<node*>AVL::ancestors(node *y,char str[])
	{
		 node *x=y;
		 
	
		 vector<node*> vec={};
		 while(x!=NULL)
		 {
		 
		 if(strcmp(x->key,str)<0)
		 {
		 	
		 	 vec.push_back(x);
	         x=x->right;
		 }
		 else if(strcmp(x->key,str)>0)
		 {
		 
			   vec.push_back(x);
	         x=x->left;
		 }
		    else
		    { 
				  vec.push_back(x);
		          break;
		          
			}
		 
		 
	       }
	       return vec;
		 
		 
	}
	
	
	
	 int partialmatch(char* a,char* b) 
	  {
	  	  if(a[0]==b[0])
	  	  {
	  	  	   if(a[1]==b[1])
	  	  	   {
	  	  	   	     if(a[2]=b[2])
	  	  	   	     {
	  	  	   	     	   return 1; 
					}
				}
			}
			return 0;
	  }
  void AVL::matchoptions(node*  t,char* val)
    {
        if(t == NULL)
            return;
        matchoptions(t->left,val);
        if(partialmatch(t->key,val))
        {
        	 cout<<"\n   "<<t->key<<"\n    ";
        	
        }
        matchoptions(t->right,val);
    } 
    
     void AVL::makeEmpty(node* t) 
{ 
    if (t == NULL) return; 
  
   
    makeEmpty(t->left); 
    makeEmpty(t->right); 
      
   
    cout << "\n\n          Deleting node:        " << t->key; 
    delete t;
} 


	int AVL::findDepth(node* root, char* x)
{
    // Base case
    if (root == NULL)
        return -1;
 
    // Initialize distance as -1
    int dist = -1;
 
    // Check if x is current node=
    if (strcmp(root->key,x)==0
 
        // Otherwise, check if x is
        // present in the left subtree
        || (dist = findDepth(root->left, x)) >= 0
 
        // Otherwise, check if x is
        // present in the right subtree
        || (dist = findDepth(root->right, x)) >= 0)
 
        // Return depth of the node
        return dist + 1;
 
    return dist;
}
        
        
		  
void AVL::treetoarray(node* p,node* arr[])
{
     static int index=0;
	if (p!=NULL)
	{
	   arr[index++]=p;
	  treetoarray(p->left,arr);
	  treetoarray(p->right,arr);
	}
}  



void AVL::findaunt(node*  p,char* val)
{
	if (p!=NULL)
	{
	      node* r=p->right;
	      node* l=p->left;
	      if(r!=NULL)
	      {
	      	 node* rr=r->right;
	      	 if(rr!=NULL)
	      	 {
			         if(strcmp(rr->key,val)==0)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<r->key<<" at address "<<r;
			        	
						if(l!=NULL)
						{
						cout<<"\n\n aunt is : "<<l->key<<" at address "<<l;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
	      	 node* rl=r->left;
	      	  if(rl!=NULL)
	      	 {
			         if(strcmp(rl->key,val)==0)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<r->key<<" at address "<<r;
			        	
						if(l!=NULL)
						{
						cout<<"\n\n aunt is : "<<l->key<<" at address "<<l;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
		  }
		  if(l!=NULL)
	      {
	      	node* lr=l->right;
	      	 if(lr!=NULL)
	      	 {
			        if(strcmp(lr->key,val)==0)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<l->key<<" at address "<<l;
			        	
						if(r!=NULL)
						{
						cout<<"\n\n aunt is : "<<r->key<<" at address "<<r;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
	      	 node* ll=l->left;
	      	  if(ll!=NULL)
	      	 {
			        if(strcmp(ll->key,val)==0)
			        {
			        	cout<<"\n\n grandparent is  :  "<<p->key<<" at address "<<p;
						cout<<"\n\n parent is  :  "<<l->key<<" at address "<<l;
			        	
						if(r!=NULL)
						{
						cout<<"\n\n aunt is : "<<r->key<<" at address "<<r;
				        	}
				        	else
				        	{
				        		cout<<"\n\n aunt doesnt exsist \n\n ";
							}
					}
			        
			   }
		  }
	      
	 findaunt(p->left,val);
	  findaunt(p->right,val);
	}
}
      

