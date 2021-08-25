//AVL.h


#pragma once
#include<vector>
using namespace std;
class node
{
public:
	char key[128] ,value[256];
	int freq=0;
	class node *left;
	class node *right;
	int height;
	 operator=(node& b)
    {
    	strcpy(key,b.key);
    	strcpy(value,b.value);
    	freq=b.freq;
	}

};

class AVL
{
public:
		 
	node* root;
	node* insert(char* ,char*, node*);
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
int count(node *p);
void grandchild(node*  p);
	int search(node* , char*);
	node*& min(node*&);
	node* delete_node(node* , char*);
	void update(node*& , char*);
	int height(node*&);
	int BF(node*&);
	node*& left_right(node*&);
	node*& left_left(node*&);
	node*& right_left(node*&);
	node*& right_right(node*&);
	node* left_rotate(node*&);
	node* right_rotate(node*&);
	void searchpartial(node*&, char *);
	void tree_to_vect(node* a,vector<node*>& temp);
	  void printlongestpath(node*  t) ;
	int depth(node*,char*);
	tree()
	{
		root=NULL;
	}
	vector<node*>ancestors(node *y,char str[]);
	vector<node*>longestPath(node* );
	void matchoptions(node*  t,char* val);
	 void makeEmpty(node* t) ;
	 
	 int findHeightUtil(node* root, char* x,int& height);
	 int findHeight(node* root, char* x);
	void findauntanddel(node*&  p,char* val);
	void findaunt(node*  p,char* val);
		int findDepth(node* root, char* x);
		void treetoarray(node* p,node* arr[]);
	
	
};

