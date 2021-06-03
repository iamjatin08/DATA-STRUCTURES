#include <iostream>
#include<queue>
using namespace std;

#include"BinarySearchTree.h"

BinaryTreeNode<int>* takeinput(){
	int rootData;
	cout<<"ENTER DATA ";
	cin>>rootData;
	if(rootData==-1) return NULL;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = takeinput();
	root->right = takeinput();
	return root;
}

BinaryTreeNode<int>* takeinputLevelWise(){
	int rootData;
	cout<<"ENTER ROOT DATA : ";
	cin>>rootData;
	if(rootData == -1) return NULL;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"LEFT CHILD OF "<<front->data<<" : ";
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!=-1) {
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		cout<<"RIGHT CHILD OF "<<front->data<<" : ";
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!=-1) {
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
			
	}
	return root;

}

int countNodes(BinaryTreeNode<int>* root){
	if(root==NULL) return 0;
	int leftnodes = countNodes(root->left);
	int rightnodes = countNodes(root->right);
	return leftnodes+rightnodes+1;
}

void printTree(BinaryTreeNode<int>* root){
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


void printTreeLevelWise(BinaryTreeNode<int>* root){
	 if(root == NULL) return;
	 queue<BinaryTreeNode<int>*> pendingNodes;
	 pendingNodes.push(root);
	 while(!pendingNodes.empty()){
	 	BinaryTreeNode<int>* front = pendingNodes.front();
	 	pendingNodes.pop();
	 	cout<<front->data<<" : ";
	 	if(front->left){
	 		cout<<"L-"<<front->left->data<<", ";
	 		pendingNodes.push(front->left);
	 	}
	 	if(front->right){
	 		cout<<"R-"<<front->right->data;
	 		pendingNodes.push(front->right);
	 	}
	 	cout<<endl;

	 }
}
void inorder(BinaryTreeNode<int>* root){
	if(root == NULL) return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
	
}



BinaryTreeNode<int>* buildTreeHelper(int* in ,int* pre, int inS ,int inE,int preS, int preE){
	if(inS>inE) return NULL;

	int rootData = pre[preS];
	int rootindex = -1;
	for(int i = inS ; i<=inE ; i++){
		if(in[i] == rootData){
			rootindex = i;
			break;
		}
	}
	
	int linS  = inS;
	int linE  = rootindex - 1;
	int lpreS = preS + 1;
	int lpreE = linE - linS + lpreS;
	int rpreS =	lpreE + 1;
	int rpreE = preE;
	int rinS  = rootindex + 1;
	int rinE  = inE;



	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left  = buildTreeHelper(in,pre,linS,linE,lpreS,lpreE);
	root->right = buildTreeHelper(in,pre,rinS,rinE,rpreS,rpreE);
	return root;

}

BinaryTreeNode<int>* buildTree(int *in ,int* pre ,int size){
	return buildTreeHelper(in ,pre,0,size-1,0,size-1);
}

int height(BinaryTreeNode<int>* root){
	if(root == NULL) return 0;
	return 1 + max(height(root->left),height(root->right));
}

int diameterofTree(BinaryTreeNode<int>* root){
	if(root == NULL) return 0;
	int option1 = height(root->left)+height(root->right);
	int option2 = diameterofTree(root->left);
	int option3 = diameterofTree(root->right);
	return max(option1,max(option2,option3));

}

pair<int,int>heightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<int,int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int,int> leftANS = heightDiameter(root->left);
	pair<int,int> rightANS = heightDiameter(root->right);
	int ld = leftANS.second;
	int lh = leftANS.first;
	int rd = rightANS.second;
	int rh = rightANS.first;
	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh,max(ld,rd));
	pair<int,int> p;
	p.first = height;
	p.second = diameter;
	return p;
}


void preorder(BinaryTreeNode<int>* root){
	if(root == NULL) return; 
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root){
	if(root == NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}



int main(int argc, char const *argv[])
{
	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	// root->left = node1;
	// root->right = node2;
	// int in[]  = {4,2,5,1,8,6,9,3,7};
	// int pre[] = {1,2,4,5,3,6,8,9,7};
	// BinaryTreeNode<int>* root = buildTree(in,pre,9);
	// cout<<endl;
	// printTreeLevelWise(root);
	// cout<<endl;
	// cout<<"TOTAL NODES : "<<countNodes(root)<<endl;
	// cout<<endl;
	// cout<<"INORDER : ";
	// inorder(root);
	// cout<<endl;
	// cout<<"PREORDER : ";
	// preorder(root);
	// cout<<endl;
	// cout<<"POSTORDER :";
	// postorder(root);

	BST b;
	b.insert(10);
	b.insert(5);	
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTree();



	return 0;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
