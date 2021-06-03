#include<iostream>
#include<queue>
using namespace std;

bool haspathDFS(int**edges, int n, int sv, int ev , bool* visited){
	if(edges[sv][ev]==1) return true;
	for(int i = 0 ; i<n ; i++){
		if(edges[sv][i] and !visited[i]){
			visited[i]= true;
			if(haspathDFS(edges,n,i,ev,visited)) return true;
		}
	}
	return false;
}

bool haspathBFS(int** edges , int n ,int sv , int ev){
	bool* visited = new bool[n];
	for(int i = 0 ; i<n ; i++) visited[i] = false;
	queue<int> remaining;
	remaining.push(sv);
	visited[sv] = true;
	while(!remaining.empty()){
		int current = remaining.front();
		remaining.pop();
		for(int i = 0 ; i< n ; i++){
			if(edges[current][i] and !visited[i]){
				remaining.push(i);
				visited[i] = true;
				if(i == ev ) return true;
			}
		}
	}
	return false;
	delete [] visited;
}




// BFS (breadth first search)
void printBFS(int**edges ,int n , int sv, bool* visited){
	queue<int> pendingvertices;
	pendingvertices.push(sv);
	visited[sv] = true;

	while(!pendingvertices.empty()){
		sv= pendingvertices.front();
		pendingvertices.pop();
		cout<<sv<<endl;
		for(int i = 0 ; i<n ;i++){
			if(edges[sv][i] and !visited[i]){
				visited[i] = true;
				pendingvertices.push(i);

			}
		}
	}
	return;
}

// DFS (depth first search)
void printDFS(int**edges,int n , int sv, bool* visited){

	cout<<sv<<endl;
	visited[sv] = true;
	for(int i = 0 ; i<n ; i++ ){
		if(i == sv) continue;
		if(edges[sv][i] and !visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
	return;
}

void BFS(int**edges , int n){
	bool* visited  = new bool[n];
	for(int i = 0 ; i<n ; i++)
		visited[i] = false;
	for(int i = 0 ; i<n ;i++){
		if(!visited[i]) printBFS(edges,n,i,visited);
	}
	delete [] visited;
	return;
}

void DFS(int** edges,int n){
	bool* visited = new bool[n];
	for(int i = 0 ; i<n ; i++) visited[i] = false;
	for(int i = 0 ;  i<n ; i++){
		if(!visited[i]) printDFS(edges,n,i,visited);
	}
	delete [] visited;
	return;
}


vector<int>* getpathDFS(int**edges,int n ,int sv, int ev , bool*visited ){
	if(edges[sv][ev]==1){
		vector<int>* ans  = new vector<int>();
		ans->push_back(ev);
		ans->push_back(sv);
		return ans;
	}
	for(int i = 0 ; i<n ; i++){
		if(i == sv) continue;
		if(edges[sv][i]==1 and !visited[i]){
			visited[i] = true;
			vector<int>* temp = getpathDFS(edges,n,i,ev,visited);
			if(temp!=NULL){
				temp->push_back(sv);
				return temp;
			}


		}
	}
	return NULL;
}

void isconnectedhelper(int**edges, int n , int sv, bool* visited){
	visited[sv] = true;
	for(int i = 0 ; i<n ;i++){
		if(edges[sv][i] and !visited[i]){
			visited[i] = true;
			isconnectedhelper(edges,n,i,visited);
		}
	}
}

bool isconnected(int**edges, int n){
	bool* visited = new bool[n];
	for(int i = 0 ; i<n ; i++) visited[i] = false;
	isconnectedhelper(edges,n,0,visited);
	for(int i = 0 ; i<n ; i++){
		if(!visited[i]) return false;
	}
	return true;
}

void connectedcomponentshelper(int**edges, int n , int sv, bool* visited , vector<int>* ans){
	ans->push_back(sv);
	visited[sv] = true;
	for(int i = 0 ; i<n ;i++){
		if(edges[sv][i] and !visited[i]){
			visited[i] = true;
			connectedcomponentshelper(edges,n,i,visited,ans);
		}
	}
	return;
}

vector<vector<int>*>* connectedcomponents(int**edges, int n){
	bool* visited = new bool[n];
	for(int i = 0 ; i<n ;i++) visited[i] = false;
	vector<vector<int>*>* output = new vector<vector<int>*>();
	for(int i = 0 ; i< n;i++){
		if(!visited[i]){
			vector<int>* ans  = new vector<int>();
			connectedcomponentshelper(edges,n,i,visited,ans);
			output->push_back(ans);

		}
	}
	delete [] visited;
	return output;
}
	


int main(int argc, char const *argv[])
{
	int n;
	int e;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i = 0 ; i<n ; i++){
		edges[i] = new int[n];
		for(int j = 0 ; j<n ; j++){
			edges[i][j] = 0;
		}
	}
	for(int i = 0 ; i<e ;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}


	cout<<"DFS"<<endl;
	DFS(edges,n);
	cout<<"BFS"<<endl;
	BFS(edges,n);
	int sv,ev;
	// cout<<"ENTER STARTING AND ENDING VERTEX: ";
	// cin>>sv>>ev;
	// bool* visited = new bool[n];
	// for(int i = 0 ; i<n ; i++) visited[i] = false;
	// // visited[sv] = true;
	// if(haspathDFS(edges,n,sv,ev,visited)){
	// 	cout<<"PATH EXIST"<<endl;
	// }
	// else{
	// 	cout<<"PATH DOES NOT EXIST"<<endl;
	// }
	// vector<int>* ans = getpathDFS(edges,n,sv,ev,visited);
	
	// if(ans!=NULL){
	// 	for(int i = ans->size()-1 ; i>=0 ; i--){
	// 		cout<<ans->at(i)<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	cout<<"CONNECTED COMPONENTS"<<endl;
	vector<vector<int>*>* output = connectedcomponents(edges,n);

	for(int i = 0 ; i<output->size() ; i++){
		vector<int>* ans  = output->at(i);
		for(int j = 0 ; j<ans->size() ; j++){
			cout<<ans->at(j)<<" ";
		}
		cout<<endl;
	}




	if(isconnected(edges,n)){
		cout<<"GRAPH IS CONNECTED"<<endl;
	}
	else{
		cout<<"GRAPH IS NOT CONNECTED"<<endl;
	}

	if(haspathBFS(edges,n,sv,ev)){
		cout<<"PATH EXIST"<<endl;
	}
	else{
		cout<<"PATH DOES NOT EXIST"<<endl;
	}
	
	// delete all memory
	for(int i = 0 ; i<output->size() ; i++){
		delete output->at(i);
	}
	delete output;



	for(int i = 0 ; i<n ;i++){
		delete [] edges[i];
	}
	// delete [] ans;
	// delete [] visited;
	delete []  edges;
	return 0;
}

// 8 9 0 4 0 5 4 3 5 6 3 2 3 1 2 1 2 6 6 7
