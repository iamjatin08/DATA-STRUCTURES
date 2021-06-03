
class HondaCity : public car{
public:
	HondaCity(int x , int y):car(x,y){
		cout<<"HondaCity constructor"<<endl;
	}
	~HondaCity(){
		cout<<"HondaCity destuctor"<<endl;
	}


};