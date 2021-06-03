class polynomial{
	int *degCoeff;
	int capacity;
public:
	//default constructor
	polynomial(){
		degCoeff = new int[5] ;

		capacity = 5;
		for(int i = 0; i<capacity; i++){
			degCoeff[i]= 0;
		}
	}


	//copy constructor
	polynomial (polynomial const &p){
		this->degCoeff = new int[p.capacity];
		//deep copy
		for(int i = 0 ; i<capacity; i++){
			this->degCoeff[i] = p.degCoeff[i];
		}
		capacity = p.capacity;
		// cout<<"copy constructor called!!"<<endl;
	}




	// copy assignment operator
	void operator=(polynomial const &p1){
		this->degCoeff = new int[p1.capacity];
		for(int i = 0 ; i<capacity ;i++){
			this->degCoeff[i] = p1.degCoeff[i];
		}
		this->capacity = p1.capacity;
	}


	// print
	void print(){
		for(int i = 0 ; i<capacity-1;i++){
			cout<<degCoeff[i]<<"x^"<<i<<"+";
		}
		cout<<degCoeff[capacity-1]<<"x^"<<capacity-1;
		cout<<endl;
	}
	void setzero(int arr[] ,int size){
		for(int i = 0  ; i<size;i++){
			arr[i] = 0;
		}
	}


	// set coefficient 
	void set(int degree ,int coefficient){
		while(degree>capacity){
			int *newdegreecoeff = new int[2*capacity];
			setzero(newdegreecoeff,2*capacity);
			for(int i = 0 ; i< capacity ; i++){
				newdegreecoeff[i] = degCoeff[i];
			}
			delete [] degCoeff;
			degCoeff = newdegreecoeff;
			capacity*=2;
		}
		degCoeff[degree] = coefficient;
		return;
	}



	// +
	polynomial operator+(polynomial const &p1){
		polynomial pnew;
		int maxcap = max(this->capacity,p1.capacity);
		for(int i = 0 ; i<maxcap ; i++){
			int sum = this->degCoeff[i]+p1.degCoeff[i];
			pnew.set(i,sum);
		}
		return pnew;

	}


	// -
	polynomial operator-(polynomial const &p1){
		polynomial pnew;
		int maxcap = max(this->capacity,p1.capacity);
		for(int i = 0 ; i<maxcap ; i++){
			int sum = this->degCoeff[i]-p1.degCoeff[i];
			pnew.set(i,sum);
		}
		return pnew;

	}

	// *



};