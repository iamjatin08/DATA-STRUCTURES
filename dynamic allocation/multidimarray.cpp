#include<iostream>
using namespace std;

int main(){
	
	int m ,n;
	cin>>m>>n;
	int **p =new int*[m];
	for(int i =0 ; i<m;i++){
		p[i] = new int[i+1];
		for(int j = 0 ; j<n; j++){
			cout<<"Enter value of";
			cin>>p[i][j];
		}
	}


	return 0 ;
}