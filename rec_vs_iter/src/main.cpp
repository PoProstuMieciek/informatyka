#include <stdio.h>
#include <stack>
using namespace std;

// #define COLORS_ENABLE 0
#define COLORS_ENABLE 1

#if COLORS_ENABLE == 1
#define COLOR_RESET       "\x1b[0m"
#define COLOR_LIGHT_BLACK "\x1b[30;1m"
#define COLOR_LIGHT_GREEN "\x1b[32;1m"
#else
#define COLOR_RESET       ""
#define COLOR_LIGHT_BLACK ""
#define COLOR_LIGHT_GREEN ""
#define DEBUG             COLOR_LIGHT_BLACK "[DEBUG] " COLOR_RESET
#define INFO              COLOR_LIGHT_GREEN "[INFO] " COLOR_RESET
#endif

#define DEBUG COLOR_LIGHT_BLACK "[DEBUG] " COLOR_RESET
#define INFO  COLOR_LIGHT_GREEN "[INFO] " COLOR_RESET

const int MAX_N = 1e6;

int D_recursive(int n, bool debug = false)
{
    if (debug) printf(DEBUG "Called D(%d). ", n);

    if (n > MAX_N) return -1;

    if (n == 0 || n == 1)
    {
        if (debug) printf("I know! D(%d) = 1\n", n);
        return 1;
    }
    if (n > 1)
    {
        int nn = (n % 2 == 0) ? (n / 4) : (3 * n + 1);

        if (debug) printf("I don't know D(%d), but D(%d) = D(%d) + 1\n", n, n, nn);

        int v  = D_recursive(nn);
        int v2 = v + 1;

        if (debug) printf(DEBUG "Now I know! D(%d) = D(%d) + 1 = %d + 1 = %d\n", n, nn, v, v2);

        return v2;
    }

    return -1;
}

int D_iterative(int n, bool debug = false)
{
    int results[MAX_N] = { 1, 1 };
    for (size_t i = 2; i < sizeof(results) / sizeof(*results); i++)
    {
        results[i] = -1;
    }

    std::stack<int> s;

    s.push(n);

    while (!s.empty())
    {
        int v = s.top();

        if (debug) printf(DEBUG "Processing D(%d)\n", v);

        int nv = (v % 2 == 0) ? (v / 4) : (3 * v + 1);
        if (debug) printf(DEBUG "Trying to retrieve D(%d) = D(%d) + 1\n", v, nv);

        if (results[nv] != -1)
        {
            results[v] = results[nv] + 1;
            s.pop();

            if (debug)
            {
                printf(DEBUG "Found D(%d) = %d\n", nv, results[nv]);
                printf(DEBUG "Calculating D(%d) = D(%d) + 1 = %d\n", v, nv, results[v]);
                printf(DEBUG "Removing D(%d) from stack\n", v);
            }

            continue;
        }

        if (debug)
        {
            printf(DEBUG "D(%d) not found\n", nv);
            printf(DEBUG "Adding D(%d) to stack\n", nv);
        }
        s.push(nv);
    }

    if (debug) printf(DEBUG "Stack is empty returning D(%d) = %d\n", n, results[n]);
    return results[n];
}

void solve()
{
    int N = 31;
    printf(INFO "D_iterative(%d) = %d\n", N, D_iterative(N));
    printf(INFO "D_recursive(%d) = %d\n", N, D_recursive(N));
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    solve();
}
#endif