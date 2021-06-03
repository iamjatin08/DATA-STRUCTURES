#include<iostream>
using namespace std;

class AVL{
public:
	int data;
	AVL* right;
	AVL* left;
	int height;
	AVL(int data){
		this->data = data;
		left = NULL;
		right = NULL;
		height = 1;
	}
};



int height(AVL* root){
	if(root==NULL) return 0;
	return root->height;
}


AVL* rightRotate(AVL* y){
	AVL* x = y->left;
	AVL* T2 =  x->right;

	//perform rotation
	x->right = y;
	y->left = T2;

	// update heights
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	return x;
}

AVL* leftRotate(AVL* x){
	AVL* y = x->right;
	AVL* T2 = y->left;

	y->left = x;
	x->right = T2;
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	return y;
	
}

//get balanced
int getbalanced(AVL* root){
	if(root==NULL) return 0;
	return height(root->left) - height (root->right);
}

// insert function

AVL* insert(AVL* root,int data){
	if(root==NULL){
		AVL* newRoot = new AVL(data);
		return newRoot;
	}
	if(data<root->data){
		root->left = insert(root->left,data);
	}else if(data>root->data){
		root->right = insert(root->right,data);
	}else{
		// equal data is not allowed
		return root;
	}

	int balance = getbalanced(root);

	//left left case
	if(balance>1 and data<root->left->data)
		return rightRotate(root);


	// right right case
	if(balance<-11 and data>root->left->data)
		return leftRotate(root);

	//left right case
	if(balance>1 and data > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//right left case
	if(balance<-1 and data<root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


void preOrder(AVL* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
    AVL *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
     
    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
     
    return 0;
}