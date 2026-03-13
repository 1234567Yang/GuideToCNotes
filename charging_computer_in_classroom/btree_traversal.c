#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct btree_node{
    int value;
    struct btree_node *left;
    struct btree_node *right;
} btree_node;

struct closest_btree_node{
    struct btree_node *btree;
    int diff;
};

btree_node* new_btree_node(int value){
    btree_node *n = malloc(sizeof(btree_node));
    if(n == NULL) return 0;
    n -> value = value;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

// success - 返回插入的节点
// failed - 返回NULL（重复值或malloc失败）
btree_node* insert_into_btree(btree_node *btree, int insert_value){
    if(insert_value == btree -> value) return NULL;
    if(insert_value > btree -> value){
        if(btree -> right  == NULL){
            btree_node *n = new_btree_node(insert_value);
            if(n != 0){
                btree -> right = n;
            }
            return n;
        }else{
            return insert_into_btree(btree -> right, insert_value);
        }
    }else{
        if(btree -> left  == NULL){
            btree_node *n = new_btree_node(insert_value);
            if(n != 0){
                btree -> left  = n;
            }
            return n;
        }else{
            return insert_into_btree(btree -> left, insert_value);
        }
    }
}

// 寻找最近似的child：如 10 会找 11 而不是 12。8 会找 6 而不是 999.
// 不包括数的value本身，只搜寻子元素的
struct closest_btree_node* get_closest_child(btree_node *btree, int number){
    int smallest_value = INT_MAX;
    btree_node* smallest_node = NULL;

    if(btree -> left != NULL){
        smallest_value = abs(btree -> left -> value - number);
        smallest_node = btree -> left;


        struct closest_btree_node *n = get_closest_child(btree -> left, number);
        if(n -> diff < smallest_value){
            smallest_value = n -> diff;
            smallest_node = n -> btree; 
        }

        free(n);
    }
    
    
    
    if(btree -> right != NULL){

        int temp_ck = abs(btree -> right -> value - number);
        if(temp_ck < smallest_value){
            smallest_value = temp_ck;
            smallest_node = btree -> right;
        }
    

        struct closest_btree_node *n = get_closest_child(btree -> right, number);
        if(n -> diff < smallest_value){
            smallest_value = n -> diff;
            smallest_node = n -> btree; 
        }

        free(n);
    }



    struct closest_btree_node *ret = malloc(sizeof(struct closest_btree_node));
    if(ret == NULL){
        printf("Failed to malloc memory");
        exit(EXIT_FAILURE);
    }
    ret -> btree = smallest_node;
    ret -> diff = smallest_value;
    return ret;
}


// 如果是叶子 -> 直接移除 + 父节点取消链接
// 如果是线条 -> 直接移除 + 父节点链接它的子节点
// 如果是茎 -> 找右子树最小值替换，再递归删除那个节点
// return the memory you should link the parent with
btree_node* remove_number(btree_node *btree, int value){
    if(btree == NULL) return NULL;

    if(value < btree -> value){
        btree -> left = remove_number(btree -> left, value);
        return btree;
    }
    if(value > btree -> value){
        btree -> right = remove_number(btree -> right, value);
        return btree;
    }

    // value == btree -> value，找到了要删除的节点

    if(btree -> left == NULL && btree -> right == NULL){
        free(btree);
        return NULL;
    }

    if(btree -> left == NULL || btree -> right == NULL){
        btree_node *kept = (btree -> left != NULL)?(btree -> left):(btree -> right);
        free(btree);
        return kept; 
    }
    
    // all not null
    // 茎：找右子树最小值替换，再递归删除那个节点
    btree_node *successor = btree -> right;
    while (successor -> left != NULL) {
        successor = successor -> left;
    }
    btree -> value = successor -> value;
    btree -> right = remove_number(btree -> right, successor -> value);
    return btree;
}


// WARNING: will not free base node
void free_btree(btree_node *btree, int base){
    if(btree == NULL) return;
    free_btree(btree -> left, 0);
    free_btree(btree -> right, 0);
    if(base == 0) free(btree);
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
    
    
    printf("insert failed should be: %d\n", insert_into_btree(&btree, 'E') == NULL);
    // printf("btree: %p \n btree_left: %p \n btree_right: %p \n", &btree, btree.left, btree.right);
    
    // 测试移除 C
    printf("--- Removing C ---\n");
    // 注意：根节点是栈上的，不能被free，所以remove_number不会动到根
    // remove_number 会递归找到 C 并删除
    btree_node *new_root = remove_number(&btree, 'C');
    // new_root 应该还是 &btree（根没变）

    printf("After removing C:\n");
    in_order_search(new_root);
    printf("\n\n");
    pre_order_search(new_root);
    printf("\n\n");

    free_btree(&btree, 1);
}
