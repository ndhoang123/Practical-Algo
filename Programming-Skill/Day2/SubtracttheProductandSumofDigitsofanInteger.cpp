// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/?envType=study-plan&id=programming-skills-i
#include <iostream>
#include <vector>

using namespace std;

int subtractProductAndSum(int n)
{
    int product = 1, sum = 0;
    while(n > 0){
        product *= n%10;
        sum += n%10;
        n = n / 10;
    }
    return product - sum;
}

int main()
{
    int n, res;
    cin >> n;
    res = subtractProductAndSum(n);
    cout << res;
    return 0;
}