#include<iostream>
using namespace std;

int partion(int *arr, int start, int end){
	int x = arr[start];
	int smaller_elements = 0;
	for(int i = start ; i<=end ;i++){
		if(arr[i]<x) smaller_elements++;
	}
	int index = start + smaller_elements;
	swap(arr[start],arr[index]);
	int i = start , j = end;
	while(i<=index and j>=index){
		if(arr[i]<x) i++;
		else{
		   	if(arr[j]>=x) j--;
		   	else{
		   		swap(arr[i++] ,arr[j--]);
		   	}
		}
	}
	return index;
}

void quickSORT(int *arr, int start, int end){
	if(start>=end) return;
	int index = partion(arr,start,end);
	quickSORT(arr,start,index-1);
	quickSORT(arr,index+1,end);
}


int main(int argc, char const *argv[])
{
	
	int n;
	cout<<"enter number of elements ";
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n ; i++){
		cin>>arr[i];
	}
	int end = n-1;


	quickSORT(arr,0,end);
	

	for(int i = 0 ; i<=end ;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}