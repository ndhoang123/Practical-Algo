#include <iostream>
#include <vector>

using namespace std;

int countOdds(int low, int high)
{
    low = low % 2 ? low : low + 1;
    high = high % 2 ? high : high - 1;
    
    return (high - low) / 2 + 1;
}

int main(){
    int low, high, value;
    cin >> low >> high;
    value = countOdds(low, high);
    cout << value;
    return 0;
}