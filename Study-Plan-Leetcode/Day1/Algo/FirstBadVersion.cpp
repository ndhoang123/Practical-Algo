#include<iostream>

using namespace std;

int firstBadVersion(int n) {
    int first = 1;
    int last = n;
    while(first < last){
        int temp = first + (last - first) / 2; // Use this condition to handle the overflow;
        if((temp) == true){ // Use temp instead of IsFirstBadVersion
            last = temp;
        }
        if((temp) == false){
            first = temp + 1;
        }
    }
    return first;
}