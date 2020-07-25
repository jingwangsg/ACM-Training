#include<iostream>
using namespace std;

void swap(int &a, int &b){int tmp; tmp = a; a = b; b = tmp;}

void quicksort(int l, int r, int* arr) {
    int mid_pos = (l+r)>>1, pivot = arr[mid_pos];
    int i = l, j = r;
    while (1) {
        while (i < r && arr[i] < pivot) i++;
        while (j > l && arr[j] > pivot) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i ++;
        j --;
    }
}

int main() {
    int arr[10] = {9, 2, 4, 3, 6, 1, 2, 5, 3};
    quicksort(0, 8, arr);
    for (int i=0; i<9; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}