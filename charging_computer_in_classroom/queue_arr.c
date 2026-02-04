#include <stdio.h>
#include <stdlib.h>

int front = 0;
int real = 0;
int *mem = NULL;

const int SIZE = 5; // actual size: SIZE - 1, we need 1 block to distict between empty and full


// Success: 1
// Fail: 0
int enqueue(int number){
    if((real + 1) % SIZE == front) return 0;
    mem[real] = number;
    real = (real + 1) % SIZE;
    
    return 1;
}

int dequeue(){
    if(front == real) return -1;
    int v = mem[front];
    front = (front + 1) % SIZE;
    return v;
}
int main(int argc, char *argv[]){
    mem = malloc(sizeof(int) * SIZE);
    if(mem == NULL){
        printf("Memory can not be allocated\n");
        exit(EXIT_FAILURE);
    }
    
    for(int i = 0; i < 7; i++){
    if(enqueue(i) == 0)
        printf("Failed to enqueue %d\n", i);
    }

    for(int i = 0; i < 2; i++){
        printf("Dequeued %d\n", dequeue());
    }
    
    for(int i = 0; i < 7; i++){
    if(enqueue(i) == 0)
        printf("Failed to enqueue %d\n", i);
    }



    for(int i = 0; i < 7; i++){
        printf("Dequeued %d\n", dequeue());
    }




    free(mem);
}
