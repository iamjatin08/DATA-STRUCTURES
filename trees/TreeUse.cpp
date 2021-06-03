#include<iostream>
#include<queue>
using namespace std;
#include"TreeNode.h"


TreeNode<int>* takeinput(){
	 int rootData;
	 cout<<"ENTER DATA ";
	 cin>>rootData;
	 TreeNode<int>* root = new TreeNode<int>(rootData);
	 cout<<"ENTER NO. OF CHILDREN ";
	 int n;
	 cin>>n;
	 for(int i = 0 ; i<n ; i++){
	 	TreeNode<int>* child = takeinput();
	 	root->children.push_back(child);
	 }
	 return root;
}

TreeNode<int>* takeinputLevelWise(){
	int rootData;
	cout<<"ENTER ROOT DATA ";
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	 while(!pendingNodes.empty()){
	 	TreeNode<int>* front = pendingNodes.front();
	 	pendingNodes.pop();
	 	cout<<"ENTER NUM OF CHILDREN of "<<front->data<<" : ";
	 	int numchild;
	 	cin>>numchild;
	 	for(int i = 0; i<numchild;i++){
	 		int childData;
	 		cout<<"ENTER "<<i+1<<"th child of "<<front->data<<" : ";
	 		cin>>childData;
	 		TreeNode<int>* child = new TreeNode<int>(childData);
	 		front->children.push_back(child);
	 		pendingNodes.push(child);
	 	}

	 }
	 return root;

}



int numNodes(TreeNode<int>* root){
	if(root == NULL) return 0;
	int ans = 1;
	for(int i = 0 ; i<root->children.size();i++){
		ans+=numNodes(root->children[i]);
	}
	return ans;
}

int heightTree(TreeNode<int>* root){
	if(root == NULL ) return -1;
	int ans = 0;
	for(int i = 0; i<root->children.size() ; i++){
		int height = heightTree(root->children[i]);
		ans = max(height,ans);
	}
	return ans+1;

}

void LevelOrderPrinting(TreeNode<int>* root){
	if(root == NULL) return;

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		cout<<front->data<<" : ";
		pendingNodes.pop();
		for(int i = 0 ; i<front->children.size() ; i++){
			if(i==front->children.size()-1){
				cout<<front->children[i]->data;
			}
			else cout<<front->children[i]->data<<",";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}

void printAtLevelK(TreeNode<int>* root, int k){
	if(root==NULL) return;
	if(k==0){
		cout<<root->data<<",";
		return;
	}
	for(int i = 0 ; i<root->children.size() ; i++){
		printAtLevelK(root->children[i],k-1);
	}
}

void printTree(TreeNode<int>* root){
	// edge case
	if(root == NULL) return;

	cout<<root->data<<" : ";

	// recrusive case
	for(int i  = 0 ; i<(root->children.size());i++){
		if(i == root->children.size()-1){
			cout<<root->children[i]->data;
			break;
		}
		cout<<root->children[i]->data<<",";

	}
	cout<<endl;
	
	for(int i  = 0 ; i<(root->children.size());i++){
		printTree(root->children[i]);
	}
}

int numofLeaf(TreeNode<int>* root){
	if(root == NULL) return 0;
	if(root->children.size()==0) return 1;
	int ans = 0;
	for(int i = 0 ; i<root->children.size(); i++){
		ans+=numofLeaf(root->children[i]);
	}
	return ans;
}

void preorder(TreeNode<int>* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	for(int i  = 0 ; i<(root->children.size());i++){
		preorder(root->children[i]);
	}
}

void deleteTree(TreeNode<int>* root){
	if(root == NULL) return;
	for(int i  = 0 ; i<root->children.size() ; i++){
		deleteTree(root->children[i]);
	}
	delete root;
}


int main(int argc, char const *argv[])
{
	// TreeNode<int>* root = new TreeNode<int>(1);
	// TreeNode<int>* node1 = new TreeNode<int>(2);
	// TreeNode<int>* node2 = new TreeNode<int>(3);
	// root->children.push_back(node1);
	// root->children.push_back(node2);
	TreeNode<int>* root = takeinputLevelWise();
	cout<<endl;
	cout<<"** LevelOrderPrinting **"<<endl;
	LevelOrderPrinting(root);
	cout<<endl;
	cout<<"** printTree **"<<endl;
	// printTree(root);
	cout<<endl;
	cout<<"NUM OF NODES : "<<numNodes(root)<<endl;
	cout<<"HEIGHT OF TREE : "<<heightTree(root)<<endl;
	// cout<<"ENTER K : ";
	// int k;
	// cin>>k;
	// cout<<"PRINT AT LEVEL K : ";
	// printAtLevelK(root,k);
	cout<<endl;
	cout<<"NUM OF LEAF : "<<numofLeaf(root)<<endl;
	
	preorder(root);
	//deleteTree(root);
	delete root;
	return 0;
}
//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0