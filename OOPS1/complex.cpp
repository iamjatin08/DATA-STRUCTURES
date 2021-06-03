class complexNumber{
private:
	int realpart;
	int imaginarypart;

public:
	complexNumber(int realpart,int imaginarypart){
		this->realpart = realpart;
		this->imaginarypart = imaginarypart;
	}
	void plus(complexNumber const &c2){
		realpart = realpart + c2.realpart;
		imaginarypart = imaginarypart + c2.imaginarypart;
	}
	void multiply(complexNumber const &c2){
		realpart = (realpart*c2.realpart) - (imaginarypart*c2.imaginarypart);
		imaginarypart = (realpart*c2.imaginarypart)+(c2.realpart*imaginarypart);
	}
	void print(){
		cout<<realpart<<"+"<<imaginarypart<<"i"<<endl;
	}


};