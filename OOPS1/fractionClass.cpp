class fraction {
private:
	int numerator;
	int denominator;
public:
	fraction(int numerator, int denominator){
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void print() const{
		cout<<numerator<<"/"<<denominator<<endl;
	}

	void simplify(){
		int gcd = 1;
		for(int i = 1 ; i<=min(this->numerator,this->denominator);i++){
			if(numerator%i==0 and denominator%i==0){
				gcd = i;
			}
		}
		numerator = numerator /gcd;
		denominator = denominator /gcd;

	}

	fraction add(fraction const &f2){
		int lcm = denominator * f2.denominator;
		int x = lcm /denominator;
		int y =  lcm /f2.denominator;
		int num = x *numerator + (y*f2.numerator);
		fraction fnew(num,lcm);
		fnew.simplify();
		return fnew;
	}

	fraction operator+(fraction const &f2) const{
		int lcm = denominator * f2.denominator;
		int x = lcm /denominator;
		int y =  lcm /f2.denominator;
		int num = x *numerator + (y*f2.numerator);
		fraction fnew(num,lcm);
		fnew.simplify();
		return fnew;
	}

	void multiply(fraction const &f2){
		numerator = numerator *f2.numerator;
		denominator = denominator * f2.denominator;
		simplify();
	}

	fraction operator*(fraction const &f2) {
		numerator = numerator *f2.numerator;
		denominator = denominator * f2.denominator;
		fraction fnew(numerator,denominator);
		fnew.simplify();
		return fnew;
	}
	bool operator==(fraction const &f2){
	//	this->simplify();
	//	f2.simplify();
		return (this->numerator == f2.numerator and this->denominator == f2.denominator);

	}
	// pre -increment
	fraction& operator++(){
		numerator = numerator + denominator;
		simplify();
		return *this;
	}
	// post-increment
	fraction operator++(int){
		fraction fnew(numerator,denominator);
		numerator = numerator + denominator;
		simplify();
		fnew.simplify();
		return fnew;
	}
	fraction& operator+=(fraction const &f2){
		int lcm = denominator * f2.denominator;
		int x = lcm /denominator;
		int y =  lcm /f2.denominator;
		int num = x *numerator + (y*f2.numerator);
		numerator = num;
		denominator = lcm;
		simplify();
		return *this;
	}

	int getnumerator() const {
		return numerator;
	}
	int getdenominator() const {
		return denominator;
	}
	void setnumerator(int n){
		numerator = n;
	}
	void setdenominator(int n) {
		if(n!=0){
			denominator = n;
		}
		else return ;
	}

};