#include<string>
using namespace std;
class vehicle{
private:
	int maxSpeed;
protected:
	int numTyres;
public:
	string color;

	// vehicle(){
	// 	cout<<"VEHICLE default CONSTRUCTOR CALLED"<<endl;
	// }
	// vehicle(int n){
	// 	maxSpeed = n;
	// 	cout<<"VEHICLE CONSTRUCTOR CALLED"<<endl;
	// }
	// ~vehicle(){
	// 	cout<<"VEHICLE DESTRUCTOR CALLED"<<endl;
	// }
	void print(){
		cout<<"vehicle"<<endl;
	}
	
};