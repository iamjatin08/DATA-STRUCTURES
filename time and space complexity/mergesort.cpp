#include<iostream>
#include<sys/time.h>
using namespace std;


long getTimeMicroSeconds(){

	struct timeval start;
	gettimeofday(&start , NULL);
	return start.tv_sec * 1000000 + start.tv_usec;

}

void merge(int arr[] , int start, int mid , int end){
	int temp[end-start];
	int i = start;
	int j = mid+1;
	int k  = 0 ;

	while(i<=mid and j<=end){
		if(arr[i]<arr[j]){
			temp[k++]= arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	if(i<=mid){
		while(i<=mid){
			temp[k++] = arr[i++];
		}
	}
	else if (j<= end){
		while(j<=end){
			temp[k++] = arr[j++];
		}
	}
	k = 0; 
	for(int l = start ; l<=end ;l++){
		arr[l] = temp[k++];
	}

}

void mergesort(int arr[] ,int start, int end){
	if(start>=end) return ;
	int mid = start + (end-start)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,mid,end);
}



int main(int argc, char const *argv[])
{
	for(int n = 0 ; n<=1000000 ; n*=10){
		int *arr = new int[n];m
		long starttime , endtime;
		for(int i = 0 ; i<n ;i++){
			arr[i] = arr[n-i];
		}
	
	starttime = getTimeMicroSeconds();
	mergesort(arr,0,n-1);
	endtime = getTimeMicroSeconds();
	cout<<"merge sort n = "<<n<<" time "<<endtime-starttime<<endl;
}

	// int arr[] = {2,43,45,6,7,3,1};
	// mergesort(arr,0,6);
	// for(int i  = 0 ; i<7 ;i++){
	// 	cout<<arr[i]<<" ";
	// }
	return 0;
}

