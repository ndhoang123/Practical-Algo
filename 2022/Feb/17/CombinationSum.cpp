// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>

using namespace std;

void Sum(vector<int> candidates, int target, vector<vector<int>> &result, vector<int> &temp, int index){
    if(target == 0){
        result.push_back(temp);
        return;
    }

    while(index < candidates.size() && target - candidates[index] >= 0){
        temp.push_back(candidates[index]);
        Sum(candidates, target - candidates[index], result, temp, index);
        index++;
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> temp;
    Sum(candidates, target, result, temp, 0);
    return result;
}

int main()
{
    vector<int> candidates{2, 3, 6, 7};
    vector<vector<int>> result = combinationSum(candidates, 7);
    for (int i = 0; i < result.size(); i++)
    {
        for (auto it : result[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}