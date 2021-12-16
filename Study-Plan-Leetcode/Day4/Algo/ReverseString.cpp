// https://leetcode.com/problems/reverse-string/
#include<iostream>
#include<vector>
#include<string>

using namespace std;
void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    while(i < s.size() / 2){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main(){
    vector<char> numbers{'h','e','l','l','o'};
    reverseString(numbers);
    for(auto it: numbers){
        cout << it << " ";
    }
    return 0;
}