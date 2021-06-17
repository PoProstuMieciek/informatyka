#include <iostream>
using namespace std;

long long power(int a, int b)
{
    long long output = 1;
    for (int i = 1; i <= b; i++)
    {
        output *= a;
    }
    return output;
}

long long power_recursion(int a, int b)
{
    // a^0 is always 1
    if (b == 0) return 1;
    
    // a^n = a * a^(n-1)
    else return a * power_recursion(a, b - 1);
}

int main()
{
    int a, b;
    cin >> a >> b;

    // you can see that this returns the same value no matter what we use (iteration or recursion)
    cout << power(a, b) << endl;
    cout << power_recursion(a, b) << endl;
}