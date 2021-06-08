#include <iostream>
using namespace std;

int array[10] = { 90, 52, 51, 63, 64, 75, 76, 87, 86, 19 };

// print contents of our array
void print_array(int how_many_items)
{
    // easy for loop over all elements
    for (int i = 0; i < 10; i++)
    {
        // print value
        cout << array[i] << " ";
    }
    // print newline
    cout << endl;
}

// returns true if changes were made
// returns false if changes were NOT made
bool bubble_sort_round(int start_index, int how_many_items)
{
    int how_many_changes_made = 0;

    for (int i = start_index; i < how_many_items - 1; i++)
    {
        // we sort items by ascending order (1 2 3 ... 10)
        // if the order is incorrect (current value is higher than the next one)
        if (array[i] > array[i + 1])
        {
            // then swap the elements
            int tmp = array[i]; // buffer, temporary variable
            array[i] = array[i + 1];
            array[i + 1] = tmp;

            // and indicate the change
            how_many_changes_made++;
        }
    }

    return how_many_changes_made > 0;
}

// sort the array with bubble sort algorithm
void bubble_sort(int start_index, int how_many_items)
{
    // do one round until there were no changes made
    while (bubble_sort_round(start_index, how_many_items) == true)
    {
        // (optional): you can print something to indicate how many rounds occurred
        cout << "round:  ";
        print_array(how_many_items);

        // (fun fact): it is allowed to leave any loop's body blank
    }
}

int main()
{
    // print array BEFORE sorting
    cout << "before: ";
    print_array(10);

    // sort the array
    bubble_sort(0, 10);

    // print array AFTER sorting
    cout << "after:  ";
    print_array(10);

    return 0;
}