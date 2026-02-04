#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void loop(node* n);

int main(int argc, char *argv[]){
    node * last_n_ptr = NULL;
    
    node start;
    start.data = 3;

    node *nptr = (node *)malloc(sizeof(node));
    nptr->data = 4;
    
    start.next = nptr;

    last_n_ptr = nptr;

    nptr = (node *)malloc(sizeof(node));
    nptr->data = 5;
    last_n_ptr->next = nptr;
    
    last_n_ptr = last_n_ptr->next;

    loop(&start);
}

void loop(node* n){
    printf("%d\n", n->data);
    if(n->next == NULL) return;
    loop(n->next);
}
