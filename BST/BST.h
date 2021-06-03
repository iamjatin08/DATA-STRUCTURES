template<typename T>
class BST{

public:
	T data;
	BST* left;
	BST* right;

	BST(T data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~BST(){
		delete left;
		delete right;
	}
};