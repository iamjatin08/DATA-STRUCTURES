#include <iostream>
using namespace std;



int firstINDEX(int *arr , int end, int number , int start=0){
	if(start>end) return -1;
	if(arr[start] == number ) return start;
	return firstINDEX(arr,end,number,start+1);
}


int lastINDEX(int *arr, int end, int number , int start = 0){
	if(start>end) return -1;
	
	if(arr[start]==number){
	int ans = lastINDEX(arr,end,number,start+1);
	if(ans == -1) return start;
	}


	return lastINDEX(arr,end,number,start+1);
	}








int main(int argc, char const *argv[]) 
{
	int arr[] = {5,5,5,5,7,7,7,6,6,6,7,7,7,7,7,9,9,9,5,5,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int number = 5;
	cout<<lastINDEX(arr,n-1,number)<<endl;
	return 0;
}