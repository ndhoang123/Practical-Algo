// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <bits/stdc++.h>

using namespace std;

int findPairs(vector<int> &nums, int k)
{
    int count = 0;
    bool isDuplicate = false;
    int lastElement = INT_MIN;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-1; i++){
        isDuplicate = false;
        if(nums[i] != lastElement){
            lastElement = nums[i];
        }
        else{
            continue;
        }
        for(int j = i+1; j < nums.size(); j++){
            if(abs(nums[i] - nums[j]) == k && isDuplicate == false){
                count++;
                isDuplicate = true;
            }
            else if(abs(nums[i] - nums[j]) > k || isDuplicate == true){
                break;
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums{1,3,1,5,4};
    int result = findPairs(nums, 0);
    cout << result;
    return 0;
}