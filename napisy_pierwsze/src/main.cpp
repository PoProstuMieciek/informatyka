#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

const int MAX_N = 25 * 'Z' + 10;

// checked   => complex
// unchecked => prime
bool sieve[MAX_N];

bool gen_sieve(size_t limit = MAX_N)
{
    if (limit > sizeof(sieve)) return false;

    // there is no need to go beyond sqrt(limit)
    for (int i = 2; i*i < limit; i++)
    {
        // if still unchecked
        if(!sieve[i])
        {
            // check all multiples
            for (int j = i*i; j < limit; j += i)
            {
                sieve[j] = true;
            }
        }
    }

    return true;
}

bool is_prime(int number)
{
    // unchecked => prime
    return !sieve[number];
}

int sum_of_letters(string input)
{
    int sum = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        sum += input[i];
    }
    return sum;
}

int main(int argc, char *argv[])
{
    string filename = "./test/example01.in";

    if (argc >= 2) {
        filename = argv[1];
    }
    else {
        printf("[WARN] Assuming filename: ./test/example01.in\n");
    }

    gen_sieve();

    int result = 0;

    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        int sum = sum_of_letters(line);
        bool prime = is_prime(sum);

        // printf("\n");
        // printf("input: %s\n", line.c_str());
        // printf("sum_of_letters: %i\n", sum);
        // printf("is_prime: %s\n", prime ? "true" : "false");
        // printf("\n");

        if (prime) result++;
    }

    printf("[INFO] Result: %i\n", result);
}