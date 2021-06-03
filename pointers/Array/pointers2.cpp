#include<iostream>
#include<vector>
using namespaces std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int i , j;
        i = 0;
        j = 0;
        vector<int> merge;
        while(i!=m-1 or j!=n-1){
            if(i==n-1){
                for(j ; j<n ; j++){
                    merge.push_back(nums2[j]);
                }
                if(j==m-1){
                    for(i ; i<n ; i++){
                        merge.push_back(nums1[i]);
                    }
                }
                if(nums1[i]>nums2[j]){
                    merge.push_back(nums2[j]);
                    j++;
                }
                else{
                    merge.push_back(nums1[i]);
                    i++;
                }
            }
        }
        
        for( i = 0 ; i<merge.size() ; i++){
            if(i<m){
                nums1[i] = merge[i];
            }
            else{
                nums1.push_back(merge[i]);
            }
        }
        m = merge.size();
        
    }

int main(int argc, char const *argv[])
{
	vector<int> nums1 ;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(4);
	nums1.push_back(6);
	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(5);
	int m , n;
	m = nums1.size();
	n = nums2.size();
	merge(nums1, m , nums2 , n);
	for(int i = 0 ; i<m+n ;i++){
		cout<<nums1[i]<<endl;
	}



	return 0;
}