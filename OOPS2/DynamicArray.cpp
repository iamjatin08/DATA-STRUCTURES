class DynamicArray{
	int *data;
	int nextIndex;
	int capacity; // total size

public:
	DynamicArray(){
		data = new int[5];
		nextIndex = 0;
		capacity = 5;
	}

void add(int element){
	if(nextIndex == capacity){
		int *newdata = new int[2*capacity];
		for(int i = 0; i<capacity ; i++){
			newdata[i] = data[i];
		}
		delete [] data;
		data = newdata;
		capacity*=2;
	}
	data[nextIndex] = element;
	nextIndex++;
}

int get(int i) const{
	if(i<nextIndex){
		return data[i];
	}
	else return -1;
}
void add(int index, int element){
	if(index<nextIndex){
		data[index] = element;
	}
	else if(index==nextIndex) {
		add(element);
	}
	else return;
}

void print() const 
{
	for(int i = 0 ; i<nextIndex ; i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}
	DynamicArray(DynamicArray const &d){
		// this->data = d.data; // shallow copy

		//deep copy
		this->data = new int[d.capacity];
		for(int i = 0 ; i<d.nextIndex ; i++){
			this->data[i] = d.data[i];
		}
		this->nextIndex = d.nextIndex;
		this->capacity = d.capacity;
	}

	void operator=(DynamicArray const &d){
		//deep copy
		this->data = new int[d.capacity];
		for(int i = 0 ; i<d.nextIndex ; i++){
			this->data[i] = d.data[i];
		}
		this->nextIndex = d.nextIndex;
		this->capacity = d.capacity;
	}
	void getcapacity(){
		cout<<"capacity:"<<capacity<<endl;
	}
	void size(){
		cout<<"size:"<<nextIndex<<endl;
	}


};