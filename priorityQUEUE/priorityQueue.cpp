using namespace std;
#include<vector>

class PriorityQueue{
	vector<int> pq;

public:

	PriorityQueue(){
	}

	bool isEmpty(){
		return pq.size() == 0;
	}

	int getsize(){
		return pq.size();
	}

	int getmin(){
		if(isEmpty()) return 0; // priority queue is empty
		return pq[0];
	}


	void insert(int element){
		pq.push_back(element);

		// up - heapify
		int childindex = pq.size()-1;
		while(childindex>0){
			int parentindex = (childindex-1)/2;
			if(pq[childindex]<pq[parentindex]){
				swap(pq[childindex],pq[parentindex]);
			}
			else break;
			childindex = parentindex;
		}
		return;
	}

	int removemin(){
		if(isEmpty()) return 0;
		int ans = pq[0];
		pq[0] = pq[pq.size()-1];
		pq.pop_back();

		// dowm - heapify

		int parentindex = 0;
		int leftchildindex = (2*parentindex)+1;
		int rightchildindex = (2*parentindex)+2;

		while(leftchildindex<pq.size()){
			int minindex = parentindex;
			if(pq[minindex]>pq[leftchildindex]){
				minindex = leftchildindex;
			}
			if(rightchildindex<pq.size() and pq[minindex]>pq[rightchildindex]){
				minindex = rightchildindex;
			}
			if(minindex == parentindex) break;
			swap(pq[minindex],pq[parentindex]);
			parentindex = minindex;
			leftchildindex = (2*parentindex)+1;
			rightchildindex = (2*parentindex)+2;
		}
		return ans;
	}
};


