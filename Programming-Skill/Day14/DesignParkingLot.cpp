// https://leetcode.com/problems/design-parking-system/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

class ParkingSystem
{
private:
    vector<int> count;

public:
    ParkingSystem(int b, int m, int s)
    {
        count = {b, m, s};
    }

    bool addCar(int carType)
    {
        return count[carType - 1]-- > 0;
    }
};

int main(){
    ParkingSystem* obj = new ParkingSystem(1, 1, 0);
    bool param_1 = obj->addCar(1);
    bool param_2 = obj->addCar(2);
    bool param_3 = obj->addCar(3);
    bool param_4 = obj->addCar(1);
    param_1 ? cout << "1: true " : cout << "1: false ";
    param_2 ? cout << "2: true " : cout << "2: false ";
    param_3 ? cout << "3: true " : cout << "3: false ";
    param_4 ? cout << "4: true " : cout << "4: false ";
    return 0;
}