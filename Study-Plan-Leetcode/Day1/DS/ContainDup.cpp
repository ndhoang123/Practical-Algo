#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        if(map.find(nums[i]) != map.end()){
            return true;
        }
        map[nums[i]] = i;
    }
    return false;
}

int main(){
    vector<int> nums = {1,1,1};
    if(containsDuplicate(nums)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}