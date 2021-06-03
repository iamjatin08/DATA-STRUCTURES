#include<climits>
using namespace std;
template<typename T>
class stackusingArray{
private:
	int nextindex;
	T *data ;
	int capacity;

public:
	stackusingArray(){
		data  = new T[5];
		nextindex = 0;
		capacity = 5;
	}
	// capacity funtion
	// int getcapacity() {
	// 	return capacity;
	// }
	// return number of elements present in stack
	T size(){
		return nextindex;
	}

	//empty function
	bool isEmpty(){
		return nextindex == 0;
	}

  
  	//insert element
  	void push(T element){
  		if(nextindex==capacity){
  			T *newData = new T[capacity*2];
  			for(auto i = 0; i<capacity;i++){
  				newData[i] = data[i];
  			}
  			capacity*=2;
  			delete [] data;
  			data = newData;
  			return push(element);
  		}
  		else{
  			data[nextindex] = element;
  			nextindex++;
  		}
  	}

  	// top most element
  	T top(){
  		if(isEmpty()){
  			cout<<"STACK IS EMPTY"<<endl;
  			return 0;
  		}
  		else{
  			return data[nextindex-1];
  		}
  	}

  	 // delete an element
  	T pop(){
  		if(isEmpty()){
  		cout<<"STACK IS EMPTY"<<endl;
  			return 0;
		}
		else{
			nextindex--;
			return data[nextindex];
			
		}
  	}
};






