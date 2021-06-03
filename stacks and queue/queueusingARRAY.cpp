


template<typename T>
class queueusingARRAY{
	T* data;
	int nextindex;
	int firstindex;
	int size;
	int capacity;
public:
	queueusingARRAY(){
		data = new T[4];
		nextindex = 0 ;
		firstindex = -1;
		size = 0;
		capacity = 4;
	}

	int getsize() {
		return size;
	}

	bool isEmpty(){
		return size==0;
	}

	// insert an element
	void enqueue(T element){
		if(size == capacity){
			// cout<<"QUEUE IS FULL !!"<<endl;
			T* newdata = new T[capacity*2];
			for(int i = 0 ; i<capacity ; i++){
				newdata[i] = data[firstindex];
				firstindex = (firstindex+1)%capacity;
			}
			firstindex = 0;
			nextindex = capacity ;
			delete [] data;
			data = newdata;
			capacity*=2;
			return enqueue(element);
		}

		data[nextindex] = element;
		nextindex = (nextindex+1)%capacity;

		if(firstindex==-1) firstindex = 0;
		size++;
	}

	//front element
	T front(){
		if(isEmpty()) 
		{
			cout<<"QUEUE IS EMPTY !!"<<endl;
			return 0;
		}
		return data[firstindex];
	}

	//delete element
	T dequeue(){
		if(isEmpty()){
			cout<<"QUEUE IS EMPTY !!"<<endl;
			firstindex = -1;
			nextindex = 0;
			return 0;
		}
		T answer = data[firstindex];
		firstindex = (firstindex+1)%capacity;
		size--;
		return answer;
	}

};



