#include <stdio.h>
#include <limits.h>

void swap_arr_index(int* arr, int i1, int i2){
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}
void selection_sort(int *arr, int size){
    for(int i = 0; i < size; i++){
        int smallest_index = -1;
        for(int j = i; j < size; j++){
            if(smallest_index == -1 || arr[j] < arr[smallest_index]){
                smallest_index = j;
            }
        }
        swap_arr_index(arr, i, smallest_index);

    }
}


int main(void){
    int arr[] = {1,2,3,4,5,6, 0, 44, 55, 12, 33};
    selection_sort(arr, sizeof(arr) / sizeof(int));
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) printf("%d | ", arr[i]);
    printf("\n\n");
}
