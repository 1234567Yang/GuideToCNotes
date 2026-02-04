#include <stdio.h>
#include <stdlib.h>

// arr should be asc
// return the smallest index which is larger to than target number. 
// the index could be out of bound
int binary_search(int *arr, int len, int target){
    if(len < 1) return 0;
    if(len == 1) return arr[0] > target ? 0 : 1;
    int center = len / 2;
    // if (arr[center] == target) return center;
    if(arr[center] > target){
        //left
        return binary_search(arr, len / 2, target);
    }else{
        return center + binary_search(arr + center, len - center, target);
        //right
    }
}

int binary_search_safe(int *arr, int len, int target){
    int res = binary_search(arr, len, target);
    if(res >= len) res = len - 1;
    return res;
}


int main(void){
    int arr[10] = {-4,2,3,6,7,9,22,33,44,55};
    int n = binary_search_safe(arr, 10, 999);
    printf("%d\n", n);

}
