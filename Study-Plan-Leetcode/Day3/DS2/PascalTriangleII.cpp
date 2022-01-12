// https://leetcode.com/problems/pascals-triangle-ii/

#include <bits/stdc++.h>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> result(rowIndex+1, 1);
    long C= 1;
    for(int i = 1; i < rowIndex; i++){
        C = C *(rowIndex - i + 1) / i;
        result[i] = C;
    }
    return result;
}

int main(){
    int rowIndex;
    cin >> rowIndex;
    vector<int> result = getRow(rowIndex);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}