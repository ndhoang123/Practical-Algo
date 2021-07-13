#include<bits/stdc++.h>

using namespace std;

bool isValidParen(string s){
    int indexMin = 0;
    int indexMax = s.size() - 1;
    bool isValid = false;
    if(s.size() % 2 != 0) return false;
    for(int i = 0; i < s.size() / 2; i++){
        if((s[indexMin] == '(' && s[indexMax] == ')') || (s[indexMin] == '[' && s[indexMax] == ']')
        || (s[indexMin] == '{' && s[indexMax] == '}')){
            indexMin++;
            indexMax--;
            isValid = true;
            cout << "A" << endl;
        }

        else if((s[indexMin] == '(' && s[indexMin+1] == ')') || (s[indexMin] == '[' && s[indexMin+1] == ']')
        || (s[indexMin] == '{' && s[indexMin+1] == '}')){
            indexMin = indexMin + 2;
            isValid = true;
            cout << "B" << endl;
            cout << indexMin << endl;
        }
        else {
            cout << "C" << endl;
            isValid = false;
            break;
        }
    }

    return isValid;
}

int main(){
    string s = "(([]){})";
    if(isValidParen(s)){
        cout << "True";
    }

    else {
        cout << "False";
    }
    return 0;
}