// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>

using namespace std;

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    while (i < version1.size() || j < version2.size())
    {
        int i1 = 0, j1 = 0;
        while(i < version1.size() && version1[i] != '.'){
            i1 = i1*10 + (version1[i] - '0');
            i++;
        }
        while (j < version2.size() && version2[j] != '.')
        {
            j1 = j1*10 + (version2[j] - '0');
            j++;
        }
        if(i1 > j1){
            return 1;
        }
        if(i1 < j1){
            return -1;
        }
        i++;
        j++;
    }
    return 0;
}

int main(){
    string version1 = "7.5.2.4";
    string version2 = "7.5.3";
    int result = compareVersion(version1, version2);
    cout << result;
    return 0;
}