#include<iostream>
using namespace std;

int firstIndex(int arr[] , int end , int number , int start = 0){
	if(start==end) return -1;
	if(arr[start]==number) return start;
	return firstIndex(arr,end,number,start+1);
}
int lastIndex(int arr[] , int end , int number , int start=0){
	if(end < start) return -1;
	if(arr[end-1] == number) return end-1;
	return lastIndex(arr, end-1, number ,start);

}


int main(){
	int arr[] = {5,5,5,5,7,7,7,6,6,6,7,7,7,7,7,9,9,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int number = 10;
	cout<<firstIndex(arr,n,number)<<endl;
	cout<<lastIndex(arr,n,number)<<endl;
	


	return 0;
}