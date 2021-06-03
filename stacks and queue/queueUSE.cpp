#include <iostream>
using namespace std;
#include "queueusingARRAY.cpp"

int main(int argc, char const *argv[])
{
	queueusingARRAY<int> q;
	for(int i = 1 ; i<=100 ; i++){
		q.enqueue(i*10);
	}
	cout<<"SIZE : "<<q.getsize()<<endl;
	q.enqueue(1010);
	cout<<"SIZE : "<<q.getsize()<<endl;
	
	while(!q.isEmpty()){
		cout<<q.dequeue()<<endl;
	}
	cout<<"SIZE : "<<q.getsize()<<endl;
	q.dequeue();
	return 0;
}