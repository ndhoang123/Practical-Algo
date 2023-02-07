// https://leetcode.com/problems/merge-strings-alternately/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    string sc = "";
    int i = 0;
    while(i < word1.size() || i < word2.size())
    {
        if(i < word1.size()){
            sc += word1[i];
        }
        if(i < word2.size()){
            sc += word2[i];
        }
        i++;
    }
    return sc;
}

int main()
{
    string word1 = "abc";
    string word2 = "pqr";
    string rs = mergeAlternately(word1, word2);
    cout << rs;
    return 0;
}