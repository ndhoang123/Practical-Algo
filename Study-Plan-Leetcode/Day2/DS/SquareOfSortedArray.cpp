#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());
    int begin = 0, end = nums.size() - 1;
    for(int i = result.size() - 1; i >= 0; i--){
        if(abs(nums[begin]) > abs(nums[end])){
            result[i] = nums[begin] * nums[begin++];
        }
        else{
            result[i] = nums[end] * nums[end--];
        }
    }
    return result;
}

int main() {
    vector<int> nums2 {-4,-1,0,3,10};
    vector<int> result;
    result = sortedSquares(nums2);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}