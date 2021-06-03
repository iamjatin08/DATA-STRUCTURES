#include <iostream>
using namespace std;

void selectionSort(int arr[] , int n){
	for(int j = 0 ; j<n-1;j++){
		int min = arr[j];
		int pos = j;
		for(int i = j+1 ; i<n ; i++){
			if(arr[i]<min){
				min = arr[i];
				swap(arr[i],arr[j]);
			}
		
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,23,4,5,2,1,6,7,43};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	for(int i = 0 ; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}