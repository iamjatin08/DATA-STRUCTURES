#include <iostream>
#include"Pair.cpp"
using namespace std;



int main(int argc, char const *argv[])
{
	Pair<int,int> p;
	p.setX(10);
	p.setY(20);
	Pair<int,double> q;
	q.setX(100.34);
	q.setY(34.21);
	cout<<"X : " <<q.getX()<<" || Y : "<<q.getY()<<endl;	
	cout<<"X : " <<p.getX()<<" || Y : "<<p.getY()<<endl;
	


	// making triplet with the help of pair class
	Pair<int,int> p4;
	p4.setX(15);
	p4.setY(16);
	
	Pair<Pair<int,int>,int> p2; 
	p2.setY(10);
	p2.setX(p4);
	cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY ()<<endl;
	return 0;
}