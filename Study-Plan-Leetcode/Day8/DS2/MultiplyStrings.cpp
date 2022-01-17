// https://leetcode.com/problems/multiply-strings/

#include <bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2)
{
    if(num1 == "0" || num2 == "0") return "0";
    vector<int> v(num1.size()+num2.size(), 0);
    for(int i = num1.size() - 1; i >= 0; i--){
        for(int j = num2.size()-1; j >= 0; j--){
            v[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            v[i+j] += v[i+j+1] / 10;
            v[i+j+1] = v[i+j+1]%10;
        }
    }

    int i = 0;
    string str = "";
    while(v[i] == 0){
        i++;
    }
    while(i < v.size()){
        str += to_string(v[i++]);
    }
    return str;
}

int main(){
    string num1, num2;
    cin >> num1 >> num2;
    string result = multiply(num1, num2);
    cout << result;
    return 0;
}