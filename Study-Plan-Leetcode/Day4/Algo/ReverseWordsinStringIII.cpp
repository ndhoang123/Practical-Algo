// https://leetcode.com/problems/reverse-words-in-a-string-iii/
#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
    stringstream ss(s);
    string word;
    string result = "";
    int sum = 0;
    int first = 0, last;
    while(ss >> word){
        first = 0, last = word.size() - 1;
        while(first <= last){
            char temp = word[first];
            word[first] = word[last];
            word[last] = temp;
            first++;
            last--;
        }
        sum = sum + word.size() + 1;
        if(sum >= s.size()){
            result = result + word;
        }
        else{
            result = result + word + " ";
        }
    }
    return result;
}

int main()
{
    string str = "Let's take LeetCode contest";
    string result = reverseWords(str);
    for(auto it : result){
        cout << it << " ";
    }
    cout << result.size() << " " << str.size();
    return 0;
}