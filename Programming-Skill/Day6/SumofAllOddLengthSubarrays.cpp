// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

int sumOddLengthSubarrays(vector<int> &arr)
{
    int count = 1, sum = 0, subSum = 0;
    for(int i = 0; i < arr.size(); i++){
        subSum = 0;
        count = 0;
        for(int j = i;j < arr.size(); j++){
            subSum += arr[j];
            count++;
            if(count % 2 != 0){
                sum += subSum;
            }
        }
    }
    return sum;
}

int main()
{
    vector<int> arr = {10,11,12};
    int res = sumOddLengthSubarrays(arr);
    cout << res;
}