#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1 DONE
void swap_args(int *lhs, int *rhs) {
    if (rhs == nullptr || lhs == nullptr) {
        return;
    }
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

// Задание 2 DONE
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows <= 0 || num_cols <= 0) {
        return nullptr;
    }
    int **arr = new int *[num_rows];
    for (int row_idx = 0; row_idx < num_rows; row_idx++) {
        arr[row_idx] = new int [num_cols]{init_value};

    }
    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_cols; j++) {
            arr[i][j] = init_value;
        }
    }
    return arr;
}

// Задание 3 DONE
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (num_rows <= 0 || num_cols <= 0) return false;
    if (arr_2d_source == nullptr || arr_2d_target == nullptr) return false;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }

    return true;
}

// Задание 4 DONE
void reverse_1d_array(vector<int> &arr) {
    int arr_size = arr.size();
    int temp;
    for (int i = 0; i < arr_size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[arr_size-i-1];
        arr[arr_size-i-1] = temp;
    }
}

// Задание 5 DONE
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin == nullptr || arr_end == nullptr) return;
    int temp;
    int arr_size = (arr_end - arr_begin + 1);
    for (int i = 0; i < arr_size / 2; i++) {
        temp = *(arr_begin + i);
        *(arr_begin + i) = *(arr_end - i);
        *(arr_end - i) = temp;
    }
}

// Задание 6 DONE
int *find_max_element(int *arr, int size) {
    if (arr == nullptr || size <= 0) return nullptr;
    int *max_element = &(arr[0]);
    for (int i = 1; i < size; i++) {
        if (*max_element < arr[i]) max_element = &(arr[i]);
    }
    return max_element;
}

// Задание 7 DONE
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> odd_arr;
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 > 0) odd_arr.push_back(arr[i]);
    }
    return odd_arr;
}

// Задание 8 TODO
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    if (arr_a.empty() || arr_b.empty()) return {};
    int size_a = arr_a.size(), size_b = arr_b.size(), temp;
    for (int i = 0; i < size_a - 1; i++) {
        for (int j = 0; j < size_a - i - 1; j++){
            if (arr_a[j] > arr_a[j+1]) {
                temp = arr_a[j];
                arr_a[j] = arr_a[j+1]; arr_a[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < size_b - 1; i++) {
        for (int j = 0; j < size_b - i - 1; j++){
            if (arr_b[j] > arr_b[j+1]) {
                temp = arr_b[j];
                arr_b[j] = arr_b[j+1]; arr_b[j+1] = temp;
            }
        }
    }
    vector<int> common_arr;
    int i = 0, j = 0;
    while (true) {
        if (arr_a[i] == arr_b[j]) {
            common_arr.push_back(arr_a[i]);
            i++; j++;
            while (arr_a[i] == arr_a[i-1] && i < size_a) {
                i++;
            }
            if (i >= size_a) return common_arr;
            while (arr_b[j] == arr_b[j-1] && j < size_b) {
                j++;
            }
            if (j >= size_b) return common_arr;
        } else if (arr_a[i] < arr_b[j]) {
            i++;
            while (arr_a[i] == arr_a[i-1] && i < size_a) {
                i++;
            }
            if (i >= size_a) return common_arr;
        } else {
            j++;
            while (arr_b[j] == arr_b[j-1] && j < size_b) {
                j++;
            }
            if (j >= size_b) return common_arr;
        }
    }
}
