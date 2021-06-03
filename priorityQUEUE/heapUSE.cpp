#include<iostream>
#include "priorityQueue.cpp"




int main(int argc, char const *argv[])
{
	PriorityQueue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout<<"SIZE:"<<p.getsize()<<endl;
	cout<<"MIN:"<<p.getmin()<<endl;

	while(!p.isEmpty()){
		cout<<p.removemin()<<" ";
	}

	return 0;
}