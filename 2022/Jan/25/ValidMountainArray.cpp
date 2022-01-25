// https://leetcode.com/problems/valid-mountain-array/

#include <bits/stdc++.h>

using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int maxPos = INT_MIN;
    if(arr.size() < 3) return false;
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        if(arr[i] == arr[i+1]) return false;
        if(arr[i] > arr[i+1] && maxPos == INT_MIN){
            maxPos = i;
        }
        if(arr[i] < arr[i+1] && i > maxPos && maxPos != INT_MIN){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr{0,2,3,4,5,2,1,0};
    validMountainArray ? cout << "Valid" : cout << "Invalid";
    return 0;
}