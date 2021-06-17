#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        cout << "All conditions are true. Triangle can be built.";
    }
    else
    {
        cout << "One or more condition(s) failed. Triangle cannot be built.";
    }

    cout << endl;
    return 0;
}