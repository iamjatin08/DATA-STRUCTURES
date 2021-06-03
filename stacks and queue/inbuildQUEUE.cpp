#include<iostream>
using namespace std;
#include<queue>



int main(int argc, char const *argv[])
{
	//our queue - inbuild queue
	//void enqueue() - void push()
	// T front() - T front()
	// T dequeue() -void pop()
	//int getsize() - int size()
	//bool isEmpty() -bool empty()

	queue<int> q;
	for(int i = 1 ; i<=100; i++) q.push(i*10);
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}


	return 0;
}