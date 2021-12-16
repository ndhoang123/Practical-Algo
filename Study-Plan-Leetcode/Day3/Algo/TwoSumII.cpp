// The question: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Using two pointer to calculate the sum
// If sum equals the target, return value.
// If sum more than the target, decrease the j.
// If sum less than the target, increate the i.
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while(i < j){
        if((numbers[i] + numbers[j]) == target){
            return {i+1, j+1};
        }
        if((numbers[i] + numbers[j]) > target){
            j--;
        }
        if((numbers[i] + numbers[j]) < target){
            i++;
        }
    }
    return {};
}

int main(){
    vector<int> numbers{2,3,4};
    vector<int> result = twoSum(numbers, 6);
    for(auto it: result){
        cout << it << " ";
    }
    return 0;
}