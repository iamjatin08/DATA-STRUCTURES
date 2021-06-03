#include<iostream>
#include<queue>
#include<climits>
#include "BST.h"
using namespace std;


class node{
public:
	int data;
	node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};



BST<int>* search(BST<int>* root, int data){
	if(root == NULL) return NULL;
	if(root->data == data) return root;
	else if(root->data>data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

BST<int>* takeinputLevelWise(){
	int rootData;
	cout<<"ENTER ROOT DATA : ";
	cin>>rootData;
	if(rootData == -1) return NULL;
	BST<int>* root = new BST<int>(rootData);
	queue<BST<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BST<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"LEFT CHILD OF "<<front->data<<" : ";
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!=-1) {
			BST<int>* leftChild = new BST<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		cout<<"RIGHT CHILD OF "<<front->data<<" : ";
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!=-1) {
			BST<int>* rightChild = new BST<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
			
	}
	return root;

}


void printBetweenK1K2(BST<int>* root ,int k1, int k2){
	if(root == NULL) return ;
	if(root->data>=k1  and root->data<=k2){
		cout<<root->data<<endl;
	}
	if(root->data>k1) return printBetweenK1K2(root->left,k1,k2); 
	else return printBetweenK1K2(root->right,k1,k2);

}

int minmum(BST<int>* root){
	if(root == NULL) return INT_MAX;
	return min(root->data,min(minmum(root->left),minmum(root->right)));
}

int maximum(BST<int>* root){
	if(root==NULL) return INT_MIN;
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}

class IsBSTreturn{
public:
	bool isBST;
	int maximum;
	int minmum;
};

IsBSTreturn isBST2(BST<int>* root){
	if(root == NULL){
		IsBSTreturn output;
		output.isBST = true;
		output.minmum = INT_MAX;
		output.maximum = INT_MIN;
	}

	IsBSTreturn leftoutput = isBST2(root->left);
	IsBSTreturn rightoutput = isBST2(root->right);
	int minmum = min(root->data,min(leftoutput.minmum,rightoutput.minmum));
	int maximum = max(root->data,max(leftoutput.maximum,rightoutput.maximum));

	IsBSTreturn output ;
	output.maximum = maximum;
	output.minmum = minmum;
	bool isBSTfinal = (root->data>leftoutput.maximum) and (root->data<=rightoutput.minmum) and leftoutput.isBST and rightoutput.isBST;
	output.isBST = isBSTfinal;
	return output;
}


bool isBST(BST<int>* root){
	if(root == NULL) return true;
	int leftMax = maximum(root->left);
	int rightMax = minmum(root->right);
	bool output = (root->data>leftMax) and (root->data<=rightMax) and isBST(root->left) and isBST(root->right);
	return output;
}

bool isBST3(BST<int>* root,int min = INT_MIN , int max = INT_MAX){
	if(root  == NULL) return true;
	if(root->data<min and root->data>max) return false;
	bool isleftOK = isBST3(root->left,min,root->data-1);
	bool isrightOK = isBST3(root->right ,root->data,max);
	return (isleftOK and isrightOK);
}

vector<int>* getRootToNodePath(BST<int>* root , int data){
	if(root == NULL) return NULL;
	if(root->data == data){
		vector<int>* output = new vector<int>();
		output->push_back(data);
		return output;
	}

	vector<int>* leftoutput = getRootToNodePath(root->left,data);
	if(leftoutput!=NULL){
		leftoutput->push_back(root->data);
		return leftoutput;
	}
	vector<int>* rightoutput = getRootToNodePath(root->right,data);
	if(rightoutput!=NULL){
		rightoutput->push_back(root->data);
		return rightoutput;
	}
	else return NULL;

	
	
}


pair<node*,node*> LLfromBSThelper(BST<int>* root){
	pair<node*,node*> answer;
	if(root==NULL){
		answer.first = NULL;
		answer.second = NULL;
		return answer;
	}
	pair<node*,node*> leftanswer = LLfromBSThelper(root->left);
	pair<node*,node*> rightanswer = LLfromBSThelper(root->right);

	node* newNode = new node(root->data);
	leftanswer.second->next = newNode;
	newNode->next = rightanswer.first;
	answer.first = leftanswer.first;
	answer.second = rightanswer.second;
	return answer;

}	


node* LLfromBST(BST<int>* root){
	return LLfromBSThelper(root).first;
}







BST<int>* buildBSTfromARRAY(int* arr, int start , int end){
	if(start>end) return NULL;
	int mid = start + (end-start/2);
	int rootData = arr[mid];
	BST<int>* root = new BST<int>(rootData);
	root->left = buildBSTfromARRAY(arr,start,mid-1);
	root->right = buildBSTfromARRAY(arr,mid+1,end);
	return root;
}


int main(int argc, char const *argv[])
{
	
	BST<int>* root = takeinputLevelWise();
	vector<int>* output  =  getRootToNodePath(root,8);
	for(int i  = 0  ; i<output->size() ; i++){
		cout<<output->at(i)<<endl;
	}
	cout<<endl;
	delete output;

	// node* head = LLfromBST(root);
	// while(head!=NULL) {
	// 	cout<<head->data<<" ";
	// 	head = head->next; 
	// }
	// cout<<endl;

	// if(isBST3(root)){
	// 	cout<<"IT IS A BST"<<endl;
	// }
	// else{
	// 	cout<<"IT IS NOT A BST";
	// }
	return 0;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 
