#include <iostream>  // cout

#include "tasks.hpp"

using namespace std;

int main() {
    int a = 1, b = 7;
    cout << a << " " << b << endl;
    swap_args(&a, &b);
    cout << a << " " << b << endl;

    allocate_2d_array(4, 3, 7);

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(5);

    reverse_1d_array(arr);
    for (int e: arr) {
        cout << e << " ";
    } cout << endl;
    cout << (&arr[5] - &arr[0]);
    cout << endl;

    reverse_1d_array(&arr[0], &arr[4]);
    for (int e: arr) {
        cout << e << " ";
    } cout << endl;
    cout << (&arr[5] - &arr[0]);
    cout << endl;

    vector<int> arr_b;
    arr_b.push_back(1);
    arr_b.push_back(1);
    arr_b.push_back(9);
    arr_b.push_back(4);
    arr_b.push_back(1);
    arr_b.push_back(6);
    arr_b.push_back(4);
    arr_b.push_back(7);

    vector<int> com = find_common_elements(arr, arr_b);
    for (int e: com) {
        cout << e << " ";
    } cout << endl;
    return 0;
}