#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(vector<int> &nums, int target){
	int first = 0;
	int last = nums.size() - 1;
	while(first <= last){
		int temp = (first + last) / 2;
		if(nums[temp] < target){
			first = temp + 1;
		}
		if(nums[temp] > target){
			last = temp - 1;
		}
		if(nums[temp] == target){
			return temp;
		}
	}
	return -1;
}

int main(){
	vector<int> nums { -1,0,3,5,9,12};
	int value = BinarySearch(nums, 2);
	cout << value;
	return 0;
}
