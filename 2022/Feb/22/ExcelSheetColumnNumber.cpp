// https://leetcode.com/problems/excel-sheet-column-number/

#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string columnTitle)
{
    int result = 0;
    for(auto it : columnTitle){
        int df = it - 'A' + 1;
        result = result * 26 + df;
    }
    return result;
}

int main(){
    string columnTitle = "AAA";
    int result = titleToNumber(columnTitle);
    cout << result;
    return 0;
}