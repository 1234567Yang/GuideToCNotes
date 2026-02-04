#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
} node;

node* first_node = NULL;

void push(int v){
    if(first_node == NULL){
        first_node = (node*)malloc(sizeof(node));
        first_node -> data = v;
        first_node -> next = NULL;
        return;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = v;
    temp -> next = first_node;
    first_node = temp;
}

int pop(){
    if(first_node == NULL) return -1;
    int ret = first_node -> data;
    node *temp = first_node -> next;
    free(first_node);
    first_node = temp;
    return ret;
}

int main(int argc, char *argv[]){
    push(1);
    push(2);
    push(4);
    push(5);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

}
