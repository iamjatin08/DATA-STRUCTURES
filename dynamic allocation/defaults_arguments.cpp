#include <iostream>
using namespace std;

int sum(int a[] , int size , int si = 0){
	int ans = 0;
	for(int i = si ; i<size ; i++){
		ans+=a[i];
	}
	return ans;
}


int sum2(int a =0 , int b = 0, int c = 0, int d = 0 ){
	return a+b+c+d;

}

int main(int argc, char const *argv[])
{
	// int a[20];
	// int n = 20;
	// for(int i=0; i<n ; i++){
	// 	cin>>a[i];
	// }

	// cout<< sum(a, 20)<<endl;
	cout<<sum2(1,2,4,5)<<endl;
	return 0;
}