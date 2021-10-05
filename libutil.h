#ifndef libutil
#define libutil
void print_arr(int *arr, int n);
void print_2Darray(int arr[1000][1000], int m, int n);
void transpose(int arr[1000][1000], int m, int n);
void copy_matrix(int arr1[1000][1000], int arr2[1000][1000], int m, int n);
void fill_space_2D(int arr[1000][1000], int m, int n);
void fill_space(int arr[1000], int n);
void fill_zero(int arr[1000], int n);
void sort(int *arr, int n);
int _in(int ele, int *arr, int n);
#endif //libutil