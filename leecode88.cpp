class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        	int j=0; 
	for(int i=m;i<m+n;++i){
		nums1[i]=nums2[j];
		j++;
	}
	for(int i=m+n-1;i>0;--i){
		for(int j=0;j<i;++j){
			if(nums1[j]>nums1[j+1]) swap(nums1[j],nums1[j+1]);
			
		}
	}
    }
};
