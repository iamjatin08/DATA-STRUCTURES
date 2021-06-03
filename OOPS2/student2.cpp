class student {

	int age;
 	const	int rollnumber;
 	int &x; // age reference variable
 	

public:
 	student(int r,int age) : rollnumber(r) ,age(age), x(this->age){
 		// this->age = age;

 	}

 void display(){
 	cout<<"age:"<<age<<endl;
 	cout<<"rollnumber:"<<rollnumber<<endl;
 }
};