#include<iostream>
using namespace std;
#include <vector>


int main(int argc, char const *argv[])
{
	int arr[5][5];
	for(int i = 0 ; i<5 ; i++){
		for(int j = 0 ; j<5 ; j++){
			cin>>arr[i][j];
		}
	}
	int temp[5][5];
	for(int i = 0 ; i<5 ;i++){
		for(int j = 0 ;j<5; j++){
			temp[i][j] = arr[j][i];
		}
	}
	cout<<endl;
	for(int i = 0 ; i<5 ;i++){
		for(int j = 0 ; j<5 ; j++){
			cout<<temp[i][j]<<" ";

		}
		cout<<endl;
	}
	return 0;
}