#include<iostream>
#include <climits>
using namespace std;

int findminVertex(int* distance, bool* visited , int n){
	int minVertex = -1;
	for(int i = 0 ; i<n ;i++){
		if(!visited[i] and (minVertex==-1 or distance[i]<distance[minVertex]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int**edges,int n){
	int* distance = new int[n];
	bool* visited = new bool[n];
	for(int i = 0 ; i<n ;i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[0] = 0;

	for(int i = 0; i<n-1; i++){
		int minVertex = findminVertex(distance,visited,n);
		for(int j = 0 ; j<n ; j++){
			if(edges[minVertex][j]!=0 and !visited[i]){
				int dist = distance[minVertex]+edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(int i = 0 ; i<n ;i++){
		cout<<i<<" "<<distance[i]<<endl;
	}


	delete [] visited;
	delete [] distance;
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
	dijkstra(edges,n);

	for(int i = 0 ; i<n ;i++){
		delete [] edges[i];
	}
	delete [] edges;

	return 0;
}