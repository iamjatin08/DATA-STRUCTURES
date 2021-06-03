using namespace std;
template<typename T>
class node{
public:
	T data;
	node* next ;
	node(T data){
		this->data = data;
		this->next = NULL;
	}
};




template<typename T>
class queueUsingLL{
	node<T>* head;
	node<T>* tail;	
	int size;
public:
	queueUsingLL(){
		head = NULL;
		tail = NULL;
		size = 0;
	}

	// size function
	int getsize(){
		return size;
	}

	// empty
	bool isEmpty(){
		return size==0;
	}
	//insert an element
	void enqueue(T element){
		node<T>* n = new node<T>(element);
		if(head==NULL){
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
			tail = n;
		}
		size++;

	}
 	// first element;
	T front(){
		if(isEmpty()){
			cout<<"QUEUE IS EMPTY"<<endl;
			return 0;
		}
		return head->data;
	}
	// delete an element
	T dequeue(){
		if(isEmpty()){
			cout<<"QUEUE IS EMPTY"<<endl;
			return 0;
		}
		T ans = head->data;
		node<T>* temp = head;
		head = head->next;
		delete temp;
		size--;
		return ans;

	}
};