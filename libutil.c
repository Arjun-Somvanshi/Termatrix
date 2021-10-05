#include<stdio.h>

void print_arr(int *arr, int n){
    for(int i = 0; i<n; i++)
        printf("%d\t", arr[i]);
    printf("%c", '\n');
}

void print_2Darray(int arr[1000][1000], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
           printf("%c", arr[i][j]); 
        printf("\n");
    }
    
}

void transpose(int arr[1000][1000], int m, int n){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            arr[i][j] = arr[j][i];
}

void copy_matrix(int arr1[1000][1000], int arr2[1000][1000], int m, int n){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            arr1[i][j] = arr2[i][j];
}

void fill_space_2D(int arr[1000][1000], int m, int n){
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            arr[i][j] = ' ';
            //arr[i][j] = '@';
}

void fill_space(int arr[1000], int n){
        for(int j=0; j<n; j++)
            arr[j] = ' ';
}

void fill_zero(int arr[1000], int n){
        for(int j=0; j<n; j++)
            arr[j] = 0;
}

void sort(int *arr, int n){
    //implementation of bubble sort
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}

int _in(int ele, int *arr, int n)
{
    //returns the index of element if it's present in the array
    //otherwise returns -1
    int beg = 0;
    int end = n-1;
    while(beg<=end)
    {
        int mid = (beg+end)/2;
        if(ele<arr[mid])
        {
            end = mid - 1;
            //printf("From binary search:%d\t%d\t%d\t%d\n ", beg, mid, end, arr[mid]);
        }
        else if(ele>arr[mid])
        {
            beg = mid + 1;
            //printf("From binary search:%d\t%d\t%d\t%d\n ", beg, mid, end, arr[mid]);
        }
        else
        {
            //printf("From binary search:%d\t%d\t%d\t%d\n ", beg, mid, end, arr[mid]);
            return mid;
        }
    }
    return -1;
}