#include<iostream>
using namespace std;

int linearSEARCH(int *arr, int n , int number){
	for(int i = 0 ; i< n ; i++){
		if(arr[i]==number) return i;
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(arr)/ sizeof(arr[0]);
	int number ;
	cin>>number;
	int answer = linearSEARCH(arr,n,number);
	cout<<answer<<endl;
	return 0;
}