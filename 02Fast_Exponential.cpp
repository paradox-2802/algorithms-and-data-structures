#include <iostream>
using namespace std;

int fastExponentiation(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    int half = fastExponentiation(base, exponent / 2);
    if (exponent % 2 == 0)
    {
        return half * half;
    }
    else
    {
        return half * half * base;
    }
}

int main()
{
    int base, exponent;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exponent;
    int result = fastExponentiation(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl;
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(log n)