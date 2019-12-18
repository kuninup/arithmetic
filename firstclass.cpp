#include<iostream>
using namespace std;
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int arrlen=0;
    for(int i=1;i<numsSize;i++){
    	if(nums[i]!=nums[arrlen]){
            arrlen++;
    		nums[arrlen]=nums[i];  		
		}	 
	}
    return arrlen+1;
}
int main(){
	int nums[] = {1,1,2};
	int numSize = 3;
	int arrlen = removeDuplicates(nums,numSize);
	for(int i=0;i<arrlen;i++){
		cout<<nums[i]<<endl;
	}
	
}

