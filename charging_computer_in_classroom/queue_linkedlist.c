#include <stdio.h>
#include <stdlib.h>

typedef struct double_linked_list{
    struct double_linked_list *left;
    int value;
    struct double_linked_list *right;
} double_linked_list;

double_linked_list *front = NULL;
double_linked_list *end = NULL;

// Failed return 0
// Success return 1
int enqueue(int v){
    double_linked_list *new_malloc = malloc(sizeof(double_linked_list));
    if(new_malloc == NULL) return 0;
    if(front == NULL){
        front = new_malloc;
        end = new_malloc;
    }else{
        end -> left = new_malloc;
        new_malloc -> right = end;
        end = new_malloc;
    }
    new_malloc -> value = v;
    return 1;
}

// Fail return -1
// Success return the number
int dequeue(){
    if(front == NULL) return -1;
    int ret = front -> value;
    if(front == end){
        free(front);
        front = NULL;
        end = NULL;
        return ret;
    }
    double_linked_list *recircle = front;
    front = front -> left;
    free(recircle);
    return ret;
}

int main(int argc, char *argv[]){
    for(int i = 0; i < 10; i++){
        if(enqueue(i) == 0) printf("Failed to enqueue %d\n", i);
    }


    for(int i = 0; i < 5; i++)
        printf("Dequeued the number %d\n", dequeue());


    for(int i = 0; i < 10; i++){
        if(enqueue(i) == 0) printf("Failed to enqueue %d\n", i);
    }


    for(int i = 0; i < 20; i++)
        printf("Dequeued the number %d\n", dequeue());


    return 0;
}
