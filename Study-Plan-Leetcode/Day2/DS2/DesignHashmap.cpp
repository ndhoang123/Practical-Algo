//https://leetcode.com/problems/design-hashmap/

#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
private:
    int data[1000001];
public:
    MyHashMap() {
        fill(data, data + 1000000, -1);
    }
    
    void put(int key, int value) {
        data[key] = value;
    }
    
    int get(int key) {
        return data[key];
    }
    
    void remove(int key) {
        data[key] = -1;
    }
};

int main(){
    MyHashMap* obj = new MyHashMap();
    int key = 1, value = 1;
    obj->put(key,value);
    int param_2 = obj->get(key);
    cout << param_2 << endl;
    obj->remove(key);
    cout << key << ": " << obj->get(key) << endl;
    return 0;
}