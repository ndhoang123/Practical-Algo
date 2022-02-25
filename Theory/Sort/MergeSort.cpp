#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i < n1; i++){
        v1[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++){
        v2[i] = a[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if(v1[i] < v2[j]){
            a[k] = v1[i];
            i++;
        }
        else if(v1[i] > v2[j]){
            a[k] = v2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = v1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = v2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &a, int l, int r){
    if(l >= r){
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}

int main(){
    vector<int> a{12, 11, 13, 5, 6, 7};
    mergeSort(a, 0, a.size() - 1);
    for(auto it : a){
        cout << it << " ";
    }
    return 0;
}