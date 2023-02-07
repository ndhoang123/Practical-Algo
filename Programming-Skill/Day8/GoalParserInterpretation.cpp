// https://leetcode.com/problems/goal-parser-interpretation/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

string interpret(string command)
{
    string rs = "";
    int i = 0;
    while(i < command.size())
    {
        if(command[i] == 'G'){
            rs += "G";
            i++;
        }
        if(command[i] == '('){
            if(command[i+1] == 'a'){
                rs += "al";
                i += 4;
            }
            else if(command[i+1] == ')'){
                rs += "o";
                i += 2;
            }
        }
    }
    return rs;
}

int main()
{
    string command = "(al)G(al)()()G";
    string res = interpret(command);
    cout << res;
    return 0;
}