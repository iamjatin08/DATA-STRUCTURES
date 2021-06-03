#include<iostream>
#include<queue>
#include<vector>
using namespace std;




int main(int argc, char const *argv[])
{
	// for getting min element
	priority_queue<int,vector<int>,greater<int>> p;
	p.push(100);
	p.push(10);
	p.push(15);
	p.push(4);
	p.push(17);
	p.push(21);
	p.push(67);

	cout<<"SIZE:"<<p.size()<<endl;
	while(!p.empty()){
		cout<<p.top()<<" ";
		p.pop();
	}
	cout<<endl;

	// for getting max element
	priority_queue<int> pq;
	pq.push(100);
	pq.push(10);
	pq.push(15);
	pq.push(4);
	pq.push(17);
	pq.push(21);
	pq.push(67);

	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;

	return 0;
}