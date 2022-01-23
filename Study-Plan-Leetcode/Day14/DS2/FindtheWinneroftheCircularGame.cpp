// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include <bits/stdc++.h>

using namespace std;

int findTheWinner(int n, int k) {
    queue<int> q;
    int count = 1;
    int top;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while (!q.empty())
    {
        top = q.front();
        q.pop();
        if(q.empty()){
            break;
        }
        if(count == k){
            count = 1;
        }
        else{
            count++;
            q.push(top);
        }
    }
    return top;
}

int main(){
    int n, k;
    cin >> n >> k;
    int result = findTheWinner(n, k);
    cout << result;
    return 0;
}