class student {
static int totalStudents;
public:
	int rollNumber;
	int age;

 //total number of students present
student(){
	totalStudents++;
}

int getrollNumber(){
	return rollNumber;
}
static int getTotalStudents(){
	return totalStudents;
}

};

int student :: totalStudents = 0;//initialze static data members
