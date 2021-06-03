

class student{
public:
int rollNumber;
private:
int age;

public:

	//default constructor
	~student(){
		cout<<"destructor called !!"<<endl;
	}

	student(){
		cout<<"constructor 1 called !"<<endl;
	}

	// paramaterized constructor
	student(int n){
		cout<<" constructor 2 called !"<<endl;
		rollNumber  = n;
	}
	student (int n , int r){
		cout<<"constructor 3 called !"<<endl;
		rollNumber = r;
		age = n;
	}

	void display(){
		cout<<age<<" "<<rollNumber;
	}

	int getAge(){
		return age;
	}
	void setAge(int n , int pass){
		if(pass !=123) return;
		if(n<=0) return;
		age  = n ;
	}

};




