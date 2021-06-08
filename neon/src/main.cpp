#include <bits/stdc++.h>
using namespace std;

const int MAX_QUERIES = 2e3 + 10;
string queries[MAX_QUERIES];
int combos[MAX_QUERIES];
int letters_added['Z' - 'A' + 1];
string display = "";

void push_back(char c)
{
    display += c;
    letters_added[c - 'A']++;
}

void change_last(char c)
{
    size_t last_index = display.size() - 1;
    display[last_index] = c;
}

void remove_last()
{
    size_t last_index = display.size() - 1;
    display = display.substr(0, last_index);
}

void shift_first(char c)
{
    for (size_t i = 0; i < display.size(); i++)
    {
        if (display[i] == c)
        {
            display[i]++;
            if (display[i] > 'Z') display[i] = 'A';
            return;
        }
    }
}

int get_top_letter_index()
{
    int last_index = 0;
    for (int i = 0; i < 'Z' - 'A'; i++)
    {
        if (letters_added[i] > letters_added[last_index])
            last_index = i;
    }
    return last_index;
}

int get_top_query_index(int queries = MAX_QUERIES)
{
    int last_index = 0;
    for (int i = 0; i < queries; i++)
    {
        if (combos[i] > combos[last_index])
            last_index = i;
    }
    return last_index;
}

void debug()
{
    printf("letters_added[]:\n");
    for (int i = 0; i < 'Z' - 'A' + 1; i++)
    {
        if (!letters_added[i]) continue;
        printf("%i (%c) => %i\n", i, i + 'A', letters_added[i]);
    }
    printf("\n");

    printf("queries[], combos[]:\n");
    for (int i = 0; i < 100; i++)
    {
        if (queries[i].empty()) break;
        printf("%i => %s, %i\n", i, queries[i].c_str(), combos[i]);
    }
    printf("\n");
}

int main()
{
    char *filename = getenv("FILENAME");
    if (!filename) filename = (char *) "./test/test.in";

    ifstream file(filename);

    string query_type;
    char query_arg;
    int query_index = 0;

    while (file >> query_type >> query_arg)
    {
        if (query_index > 0)
        {
            queries[query_index] = query_type;
            if (queries[query_index] == queries[query_index - 1]) {
                combos[query_index] = combos[query_index - 1] + 1;
            }
            else combos[query_index] = 1;
        }
        else
        {
            queries[0] = query_type;
            combos[0] = 1;
        }

             if (query_type == "DOPISZ")  push_back(query_arg);
        else if (query_type == "ZMIEN")   change_last(query_arg);
        else if (query_type == "USUN")    remove_last();
        else if (query_type == "PRZESUN") shift_first(query_arg);

        query_index++;
    }

    file.close();

    // debug();

    int top_letter_index = get_top_letter_index();
    int top_query_index = get_top_query_index(query_index + 1);

    printf("1. %li\n", display.size());
    printf("2. %s, %i\n", queries[top_query_index].c_str(), combos[top_query_index]);
    printf("3. %c, %i\n", top_letter_index + 'A', letters_added[top_letter_index]);
    printf("4. %s\n", display.c_str());
}