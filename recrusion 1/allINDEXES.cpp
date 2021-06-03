#include<iostream>
#include<vector>
using namespace std;


int allINDICES(int arr[] , int size, int number){
	if(size==0) return 0;
	int ans = allINDICES(arr,size-1,number);
	if(arr[size-1]==number) return ans+1;
}


// int *output2(int *arr , int end, int number, int start , int i , int *ans){
// 	if(start>end) return ans;
// 	if(arr[start]== number){
// 		ans[i] = start ;
// 		return output2(arr,end,number,start+1,i+1);
// 	} 
// 	else{
// 		return output2(arr,end,number,start+1,i);
// 	}
// }

// int * output(int *arr,int size, int number){
// 	int ans[50] = {0};
// 	return output2(arr , size -1 , number , 0 ,0 , ans);
// }


int main(int argc, char const *argv[])
{

	int arr[] = {5,5,5,5,7,7,7,6,6,6,7,7,7,7,7,9,9,9,5,5,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int number =8;
	int answer = allINDICES(arr,n,number);
	cout<<answer<<endl;
	return 0;
}