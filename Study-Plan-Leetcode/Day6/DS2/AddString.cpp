// https://leetcode.com/problems/add-strings/

#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2)
{
    string ans = "";
    int i = num1.size()-1, j = num2.size()-1;
    int holder = 0;
    while((i >= 0) || (j >= 0) || (holder > 0)){
        if(i >= 0){
            holder += num1[i] - '0';
            i -= 1;
        }
        if(j >= 0){
            holder += num2[j] - '0';
            j -= 1;
        }
        ans += (char)(holder % 10 + '0');
        holder = holder / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // "11" + "123"
    // string num1, num2;
    // cin >> num1 >> num2;
    // string result = addStrings(num1, num2);
    // cout << result;
    // char a = '1';
    int a = 1;
    char b = a + '0';
    cout << b;
    return 0;
}