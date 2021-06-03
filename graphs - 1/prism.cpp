#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int* weight,bool* visted, int n){
	int minVertex = -1;
	for(int i = 0 ; i<n ; i++){
		if(!visted[i] and (minVertex == -1 ||  weight[i]<weight[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}


void prims(int** edges, int n){

	int* parent = new int[n];
	int* weight = new int[n];
	bool* visted = new bool[n];
	for(int i = 0 ; i<n ;i++){
		visted[i] = false;
		weight[i] = INT_MAX;
	}
	parent[0] = -1;
	weight[0] = 0;

	for(int i = 0; i<n-1 ; i++){
		// find min vertex
		int minVertex = findMinVertex(weight,visted,n);
		visted[minVertex] = true;
		//explore un visited neighbour
		for(int j = 0 ; j<n ;j++){
			if(edges[minVertex][j]!=0 and !visted[j]){
				if(edges[minVertex][j]<weight[j]){
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	for(int i = 1 ; i<n ; i++){
		if(parent[i]<i){
			cout<<parent[i]<<" "<<i<<" "<<weight[i];
		}
		else{
			cout<<i<<" "<<parent[i]<<" "<<weight[i];
		}
		cout<<endl;
	}
	delete [] visted;
	delete [] parent;
	delete [] weight;
}






int main(int argc, char const *argv[])
{
	int n,e;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i = 0 ; i<n ; i++){
		edges[i] = new int[n];
		for(int j = 0; j<n ;j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 0 ; i<e ;i++){
		int f,s,weight;
		cin>>f>>s>>weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout<<endl;
	prims(edges,n);

	for(int i = 0 ; i<n ;i++){
		delete [] edges[i];
	}
	delete [] edges;

	return 0;
}