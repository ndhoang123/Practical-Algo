#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m -1, j = n - 1, k = m + n - 1;
    vector<int> nums3(k + 1);
    fill(nums3.begin(), nums3.end(), 0);
    while(i >= 0 && j >= 0){
        if(nums1[i] < nums2[j]){
            nums3[k--] = nums2[j--];
        }
        else{
            nums3[k--] = nums1[i--];
        }
    }
    while(i >= 0){
        nums3[k--] = nums1[i--];
    }
    while(j >= 0){
        nums3[k--] = nums2[j--];
    }
    for(auto it : nums3){
        cout << it << " ";
    }
}

int main()
{
    vector<int> nums1{1,3,6,8,10};
    vector<int> nums2{2,6,7,12,14,15};
    merge(nums1, 5, nums2, 6);
    return 0;
}