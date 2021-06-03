#include<iostream>
using namespace std;

void bubbleSORT(int *arr,int n){
	for(int i = 0 ; i<n ; i++){
		for(int  j = i ;j< n ; j++){
			if(arr[i]>arr[j]) swap(arr[i],arr[j]);
		}
	}
	return ;
}


int main(){

	int arr[] = {12,23,4,5,3,2,4,5,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSORT(arr,n);
	for(int i = 0 ; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;


	return 0;
}