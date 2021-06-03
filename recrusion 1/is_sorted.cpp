#include<iostream>
using namespace std;


bool is_sorted2( int a[] , int size){
	if(size==0 || size == 1) return true;
	bool iisSmallerOutput = is_sorted2(a+1 , size-1);
	if(!iisSmallerOutput) return false;
	if(a[0]>a[1]){
		return false;
	}
	else return true;

}


bool is_sorted(int *a , int size){
	if(size == 0 or size == 1) return true;

	if(a[0]>a[1]) return false;
	return is_sorted(a+1,size-1);
}

int main(){
	
	int arr[] = {1,2,3,4,5};
	int n = 5;
	cout<<is_sorted(arr,n)<<endl;
	cout<<is_sorted2(arr,n)<<endl;

	return 0;
}