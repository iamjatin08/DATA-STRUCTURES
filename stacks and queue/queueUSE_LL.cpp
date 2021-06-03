#include<iostream>
using namespace std;
#include"queueUsingLL.cpp"

int main(int argc, char const *argv[])
{
	queueUsingLL<int> q;
	for(int i = 1 ; i<=100 ;i++){
		q.enqueue(i*10);
	}
	cout<<q.getsize()<<endl;
	while(!q.isEmpty()){
		cout<<q.front()<<endl;
		q.dequeue();
	}
	q.dequeue();
	return 0;
}