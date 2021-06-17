#include <iostream>
using namespace std;

long long factorial(int x)
{
    long long output = 1;
    for (int i = 1; i <= x; i++)
    {
        output *= i;
    }
    return output;
}

long long factorial_recursion(int x)
{
    if (x == 1) return x;
    else return x * factorial_recursion(x - 1);
}

int main()
{
    int x;
    cin >> x;

    // you can see that this returns the same value no matter what we use (iteration or recursion)
    cout << factorial(x) << endl;
    cout << factorial_recursion(x) << endl;
}