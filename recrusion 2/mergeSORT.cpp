#include<iostream>
using namespace std;

void merge(int arr[] ,int start , int mid,  int end){
	int n1 = mid - start +1;
	int n2 = end - mid ;
	int L[n1] , R[n2];
	for(int i = 0 ; i<n1;i++){
		L[i] = arr[start+i];
	}
	for(int j = 0 ; j<n2; j++){
		R[j]=arr[mid+1+j];
	}
	int i = 0 , j = 0 , k = start;
	while(i<n1  and j<n2){
		if(L[i]>R[j]){
			arr[k] = R[j];
			
			j++;
		}
		else{
			arr[k] = L[i];
			i++;

		}
		k++;
	}
	while(i<n1){
		arr[k] = L[i];
		k++;
		i++;
	}
	while(j<n2){
		arr[k] = R[j];
		k++;
		j++;
	}
}

void mergeSORT(int *arr, int start , int end){
	if(start>=end) return;
	int mid = ((end-start)/2)+start;
	mergeSORT(arr,start ,mid) ;
	mergeSORT(arr,mid+1,end);
	merge(arr,start,mid,end);
}


int main(int argc, char const *argv[])
{
	int arr[] = {1,4,2,3,5,7,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int end = n-1;
	int start = 0;
	mergeSORT(arr,start,end);
	

	for(int i = 0 ; i<=end ;i++){m
		cout<<arr[i]<<" ";
	}

	return 0;
}