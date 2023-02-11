// https://leetcode.com/problems/design-parking-system/?envType=study-plan&id=programming-skills-i
#include <bits/stdc++.h>

using namespace std;

class ParkingSystem
{
private:
    int bigSize, mediumSize, smallSize;

public:
    ParkingSystem(int big, int medium, int small)
    {
        bigSize = big;
        mediumSize = medium;
        smallSize = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 && bigSize > 0)
        {
            bigSize--;
            return true;
        }
        if (carType == 2 && mediumSize > 0)
        {
            mediumSize--;
            return true;
        }
        if (carType == 3 && smallSize > 0)
        {
            smallSize--;
            return true;
        }
        return false;
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