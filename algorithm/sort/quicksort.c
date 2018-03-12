#include <stdio.h>
#include <stdlib.h>

void PrintArray(int array[], int length);
void QuickSort(int array[], int begin, int end);
void QuickSortMiddleBase(int array[], int begin, int end);

int main(int argc, char** argv) {
    int array[] = {3, 9, 4, 2, 5, 8, 7, 6, 1};
    int length = sizeof(array) / sizeof(int);
    printf("output array\n");
    PrintArray(array, length);
    printf("begin quick sort\n");
    QuickSortMiddleBase(array, 0, length - 1);
    printf("quick sorted\n");
    PrintArray(array, length);

    system("pause");
    return 0;
}

void QuickSortMiddleBase(int array[], int begin, int end) {
    if(begin >= end) {
        return ;
    }
    int base_pos = (begin + end) / 2;
    int base_value = array[base_pos];

    int left_pos = begin, right_pos = end;
    int temp_val;

    while(left_pos != right_pos) {
        while(array[left_pos] < base_value && left_pos <= right_pos) {
            left_pos++;
        }
        while(array[right_pos] > base_value && right_pos >= left_pos) {
            right_pos--;
        }
        if(left_pos <= right_pos) {
            temp_val = array[left_pos];
            array[left_pos] = array[right_pos];
            array[right_pos] = temp_val;
        }
    }
    array[left_pos] = base_value;
    PrintArray(array, 9);
    QuickSortMiddleBase(array, begin, left_pos - 1);
    QuickSortMiddleBase(array, left_pos + 1, end);
}

void QuickSort(int array[], int begin, int end) {
    if(begin >= end) {
        return ;
    }
    int base_pos = begin;
    int base_value = array[base_pos];

    int left_pos = begin, right_pos = end;
    int temp_val;
    while(left_pos != right_pos) {
        while(array[left_pos] < base_value && left_pos < right_pos) {
            left_pos++;
        }
        while(array[right_pos] > base_value && left_pos < right_pos) {
            right_pos--;
        }
        if(left_pos < right_pos) {
            temp_val = array[left_pos];
            array[left_pos] = array[right_pos];
            array[right_pos] = temp_val;
        }
    }
    //array[left_pos] = base_value;
    //array[base_pos] = temp_val;
    printf("sort result:");
    PrintArray(array, 9);
    QuickSort(array, begin, left_pos);
    QuickSort(array, left_pos + 1, end);

}

void PrintArray(int *array, int length) {
    int i;
    for(i = 0 ; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}