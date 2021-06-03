using namespace std;

template<typename T>
class Node{
public:
	T data;
	Node<T>* next;
	Node(T data){
		this->data = data;
		next = NULL;
	}

};

template<typename T>
class Stack{
	Node<T>* head;
	int size;
public:
	Stack(){
		head = NULL;
		size = 0;
	}
	int getsize(){
		return size;
	}
	bool isEmpty(){
		return size==0;
	}
	void push(int element){
		Node<T> * newNode = new Node<T>(element);
		if(head==NULL){
			head = newNode;
		}
		else{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	T pop(){
		if(isEmpty()){
			cout<<"STACK IS EMPTY"<<endl;
			return 0;
		}
		T data = head->data;
		Node<T> * temp = head;
		head = head->next;
		delete temp;
		size--;
		return data;
	}
	T top(){
		if(isEmpty()){
			cout<<"STACK IS EMPTY"<<endl;
			return 0;
		}
		return head->data;
	}
};
