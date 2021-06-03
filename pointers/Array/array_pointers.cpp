#include<iostream>
using namespace std;


int main(){
	
int a[] = {1,2,3,4,5,6,7,8,9,10};
cout<<a<<endl;
cout<<&a[0]<<endl;
cout<<a[0]<<endl;
cout<<*a<<endl;
cout<<a+1<<endl;
cout<<*(a+1)<<endl;
// int * p = a+1;
// cout<<p<<endl;
// for(int i = 0 ; i<10;i++){
	// cout<<*(a+i)<<endl;
// }
int i = 3;
cout<<i[a]<<endl;
cout<<"size->"<<sizeof(a)<<endl;
int *p = &a[0];
cout<<p<<endl;
cout<<&p<<endl;
cout<<&a<<endl;
cout<<sizeof(p)<<endl;
cout<<sizeof(a)<<endl;
// a = a+1;
p = p+1;
// a++;


	return 0 ;
}