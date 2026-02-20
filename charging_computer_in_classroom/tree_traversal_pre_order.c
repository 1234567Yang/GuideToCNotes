#include <stdio.h>
#include <stdlib.h>

typedef struct btree_node{
    int value;
    struct btree_node *left;
    struct btree_node *right;
} btree_node;

btree_node* new_btree_node(int value){
    btree_node *n = malloc(sizeof(btree_node));
    if(n == NULL) return 0;
    n -> value = value;
    return n;
}
// success - 0
// failed - 1
int insert_into_btree(btree_node *btree, int insert_value){
    if(insert_value == btree -> value) return 1;
    if(insert_value > btree -> value){
        if(btree -> right  == NULL){
            btree_node *n = new_btree_node(insert_value);
            if(n != 0){
                btree -> right = n;
            }
        }else{
            return insert_into_btree(btree -> right, insert_value);
        }
    }else{
        if(btree -> left  == NULL){
            btree_node *n = new_btree_node(insert_value);
            if(n != 0){
                btree -> left  = n;
            }
        }else{
            return insert_into_btree(btree -> left, insert_value);
        }
    }



    return 0;
}


void pre_order_search(btree_node *btree){
    if(btree == NULL) return;
    printf("%c | ", btree -> value);
    pre_order_search(btree -> left);
    pre_order_search(btree -> right);
}

void post_order_search(btree_node *btree){
    if(btree == NULL) return;
    post_order_search(btree -> left);
    post_order_search(btree -> right);
    printf("%c | ", btree -> value);
}

void in_order_search(btree_node *btree){
    if(btree == NULL) return;
    in_order_search(btree -> left);
    printf("%c | ", btree -> value);
    in_order_search(btree -> right);
}

int main(void){
    btree_node btree = {.left = NULL, .right = NULL, .value = 'F'};
    insert_into_btree(&btree, 'B');
    insert_into_btree(&btree, 'G');
    insert_into_btree(&btree, 'A');
    insert_into_btree(&btree, 'D');
    insert_into_btree(&btree, 'C');
    insert_into_btree(&btree, 'E');
    insert_into_btree(&btree, 'I');
    insert_into_btree(&btree, 'H');
    pre_order_search(&btree);
    printf("\n\n");
    post_order_search(&btree);
    printf("\n\n");
    in_order_search(&btree);
    printf("\n\n");
    
    
    printf("insert failed should be: %d\n", insert_into_btree(&btree, 'E'));
    // printf("btree: %p \n btree_left: %p \n btree_right: %p \n", &btree, btree.left, btree.right);
    
}
