#include <iostream>
#include <iomanip>
using namespace std;

int arrayData[7] = {1,8,2,5,4,9,7};
int cari;

void selection_sort(int arr[], int n){
    int temp, min;
    for (int i = 0; i < n-1; i++){
        min = 1;
        for (int j = i+1; j < n; i++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void binary_search(int arr[], int n, int target){
    int awal = 0, akhir = n-1, tengah, b_flag = 0;

    while (b_flag == 0 && <= akhir)/2;
    if (arr[tengah] == target)
}