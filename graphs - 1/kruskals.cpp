#include<bits/stdc++.h>
using namespace std;
class Edge{
public:
	int source;
	int dest;
	int weight;
};

bool compare(Edge e1 , Edge e2){
	return e1.weight < e2.weight;
}

int findparent(int v , vector<int> parent){
	if(parent[v]==v) return v;
	return findparent(parent[v],parent);
}

void kruskals(vector<Edge> input, int n, int E){

	sort(input.begin(),input.end(),compare);

	vector<Edge> output(n-1);
	vector<int> parent(n);
	for(int i = 0 ; i<n ; i++) parent[i] = i;
	int count = 0 ;
	int i = 0;
	while(count!=n-1){
		Edge currentEdge = input[i];

		//check if we can add the currentEdge in MST or not
		int sourceparent = findparent(currentEdge.source,parent);
		int destparent = findparent(currentEdge.dest,parent);
		if(sourceparent!=destparent){
			output[count] = currentEdge;
			count++;
			parent[sourceparent] = destparent;
		}
		i++;
	}

	// print
	for(int i = 0 ; i<n-1 ; i++){
		if(output[i].source<output[i].dest){
		cout<<output[i].dest<<" "<<output[i].source
		<<" "<<output[i].weight<<endl;
	
		}
		cout<<output[i].source<<" "<<output[i].dest
		<<" "<<output[i].weight<<endl;
	}
}




int main()
{
	int n , E;
	cin>>n>>E;
	vector<Edge> input;
	for(int i = 0 ; i<E ;i++){
		int s,d,w;
		cin>>s>>d>>w;
		Edge e;
        e.source=s;
        e.dest=d;
        e.weight=w;
        input.push_back(e);
	}
	kruskals(input,n,E);
	

	return 0;
}