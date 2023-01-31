#include <iostream>
#include <vector>

using namespace std;

double average(vector<int> &salary)
{
    int low = INT_MAX;
    int high = INT_MIN;
    int scr = 0;
    int number = 0;
    for(int i = 0; i < salary.size(); i ++){
        if(salary[i] > high) high = salary[i];
        if(salary[i] < low) low = salary[i];
    }
    for(int i = 0; i < salary.size(); i++){
        if(salary[i] != high && salary[i] != low){
            scr += salary[i];
            number++;
        }
    }
    return (double)scr/number;
}

int main(){
    vector<int> salary = {48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000};
    double res = average(salary);
    cout << res;
    return 0;
}