#include <iostream>
using namespace std;

long long nth_triangle_number(int x)
{
    long long output = 0;
    for (int i = 1; i <= x; i++)
    {
        output += i;
    }
    return output;
}

long long nth_triangle_number_recursion(int x)
{
    if (x == 1) return x;
    else return x + nth_triangle_number_recursion(x - 1);
}

int main()
{
    int x;
    cin >> x;

    // you can see that this returns the same value no matter what we use (iteration or recursion)
    cout << nth_triangle_number(x) << endl;
    cout << nth_triangle_number_recursion(x) << endl;
}