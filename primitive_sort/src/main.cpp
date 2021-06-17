#include <iostream>
using namespace std;

// array of items, box of apples, random order of elements
int array[10] = { 90, 52, 51, 63, 64, 75, 76, 87, 86, 19 };

// find smallest item in array (starting from `start`)
int find_min_index(int start, int total_items)
{
    int smallest_value = array[start]; // smallest item yet
    int smallest_index = start; // smallest item index

    // loop over all items in array
    // start from index = start
    // loop only if index < 10 (0 1 2 ... 9)
    // after each loop increment index (go to next item)
    for (int current_index = start; current_index < total_items; current_index++)
    {
        // if current item is SMALLER than saved one
        if (array[current_index] < smallest_value)
        {
            // then we have a new "smallest" item

            // lets save its value and index
            smallest_value = array[current_index];
            smallest_index = current_index;
        }
    }

    return smallest_index;
}

// find highest item in array (starting from `start`)
int find_max_index(int start, int total_items)
{
    int highest_value = array[start]; // highest item yet
    int highest_index = start; // highest item index

    // loop over all items in array
    // start from index = start
    // loop only if index < 10 (0 1 2 ... 9)
    // after each loop increment index (go to next item)
    for (int current_index = start; current_index < total_items; current_index++)
    {
        // if current item is LARGER than saved one
        if (array[current_index] > highest_value)
        {
            // then we have a new "highest" item

            // lets save its value and index
            highest_value = array[current_index];
            highest_index = current_index;
        }
    }

    return highest_index;
}

// we use find_min_index inside this function, so it sorts ASCENDING (1, 2, 3, 4, 5)
void primitive_sort(int start, int how_many_items)
{
    for (int i = start; i < how_many_items; i++)
    {
        int min_index = find_min_index(i, how_many_items);

        // swap the items
        int tmp = array[i];
        array[i] = array[min_index];
        array[min_index] = tmp;
    }
}

// we use find_max_index inside this function, so it sorts DESCENDING (5, 4, 3, 2, 1)
void primitive_sort_recursion(int start, int how_many_items)
{
    // if we are in range of array
    if (start < how_many_items - 1)
    {
        int max_index = find_max_index(start, how_many_items);

        // swap the items
        int tmp = array[start];
        array[start] = array[max_index];
        array[max_index] = tmp;

        primitive_sort_recursion(start + 1, how_many_items);
    }
}

// print contents of our array
void print_array(int how_many_items)
{
    // easy for loop over all elements
    for (int i = 0; i < how_many_items; i++)
    {
        // print value
        cout << array[i] << " ";
    }
    // print newline
    cout << endl;
}

int main()
{
    cout << "# SORT ASCENDING" << endl;
    // print array BEFORE sorting
    print_array(10);

    // sort the array
    cout << "sorting ..." << endl;
    primitive_sort(0, 10);

    // print array AFTER sorting
    print_array(10);

    cout << endl << endl;
    
    cout << "# SORT DESCENDING" << endl;
    // print array BEFORE sorting
    print_array(10);

    // sort the array
    cout << "sorting ..." << endl;
    primitive_sort_recursion(0, 10);

    // print array AFTER sorting
    print_array(10);

    return 0;
}