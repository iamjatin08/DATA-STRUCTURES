#include "BinaryTreeNode.h"
class BST{
	BinaryTreeNode<int>* root;

public:
	BST(){
		root == NULL;
	}

	~BST(){
		delete root;
	}
private:
	
	BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node){
		if(node==NULL) return NULL;
		else if(node->data==data){
			if(node->left == NULL and node->right ==NULL ){
				delete node;
				return NULL;
			}
			else if(node->left == NULL){
				BinaryTreeNode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			}
			else if(node->right == NULL){
				BinaryTreeNode<int>* temp = node->left;
				node->left = NULL;
				delete node;
				return temp;

			}
			else{
				BinaryTreeNode<int>* minNode = node->right;
				while(minNode->left!=NULL){
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node = deleteData(rightMin,node->right);
				return node;
			}
		}
		else if(node->data>data){
			node->left = deleteData(data,node->left);
		}
		else{
			node->right = deleteData(data,node->right);
		}
		return node;
	}

public:

	void deleteData(int data){
		root = deleteData(data,root);
	}
private:

	BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node){
	if(node==NULL){
		BinaryTreeNode<int>* newNode = new  BinaryTreeNode<int>(data);
		return newNode;
	}
	else if(node->data>data) node->left = insert(data,node->left);
	else	node->right = insert(data,node->right);
	return node;
	}

public:

	void insert(int data){
		root = insert(data,root);
	}

private:
	bool hasData(int data,BinaryTreeNode<int>* node){
		if(node==NULL) return false;
		if(node->data == data) return true;
		else if(node->data>data) return hasData(data ,node->left);
		else return hasData(node->right);
	}

public:	

	bool hasData(int data){
		return hasData(data,root);
	}

private:
	void printTree(BinaryTreeNode<int>* node){
	if(root==NULL) return ;
	cout<<root->data<<" :";
	if(root->left!=NULL){
		cout<<" L-"<<root->left->data<<",";
	}
	if(root->right!=NULL){
		cout<<" R-"<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
	}

public:
	void printTree(){
		printTree(root);
	}
};