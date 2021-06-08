#include <iostream>
using namespace std;

// array of items, box of apples, random order of elements
int array[10] = { 90, 52, 51, 63, 64, 75, 76, 87, 86, 19 };

// find smallest item in array[]
void min(int start_here, int total_items)
{
    int smallest_value = array[start_here]; // smallest item yet
    int smallest_index = start_here; // smallest item index

    // loop over all items in array
    // start from index = 0
    // loop only if index < 10 (0 1 2 ... 9)
    // after each loop increment index (go to next item)
    for (int current_index = start_here; current_index < total_items; current_index++)
    {
        // if current item is SMALLER than saved one
        if (array[current_index] < smallest_value)
        {
            // then we have a new "smallest" item

            // lets save its value
            smallest_value = array[current_index];
            // and index
            smallest_index = current_index;
        }
    }

    // set the value of the smallest found to the starting item
    array[smallest_index] = array[start_here];
    // set the value of starting item to the smallest found
    array[start_here] = smallest_value;
}

void primitive_sort(int start_here, int how_many_items)
{
    for (int i = start_here; i < how_many_items; i++)
    {
        min(i, how_many_items);
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
    // print array BEFORE sorting
    print_array(10);

    // sort the array
    cout << "sorting ..." << endl;
    primitive_sort(0, 10);

    // print array AFTER sorting
    print_array(10);

    return 0;
}