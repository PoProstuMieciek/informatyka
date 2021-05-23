#include <stdio.h>
#include <numeric>

int main()
{
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);

    bool conditions[3] = {
        a + b > c,
        a + c > b,
        b + c > a
    };
    
    int check = std::accumulate(conditions, conditions + sizeof(conditions), 0);
    
    if (check == sizeof(conditions)) {
        printf("All conditions are true. Triangle can be built.");
    }
    else {
        printf("One or more condition(s) failed. Triangle cannot be built.");
    }

    printf("\n");
    return 0;
}