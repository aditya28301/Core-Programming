#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SUCCESS 0
#define FAILED -1
#define TRUE 1
#define BST_NO_SUCESSOR 2
#define INVALID_BST_DATA 3
#define BST_NO_PREDECESSOR 4

typedef struct bst bst_t;
typedef long long data_t;
typedef struct bst_node node; 
typedef int status_t;
typedef size_t index_t;

struct bst{
    struct bst_node* root_node;
    size_t no_of_element;
};

struct bst_node{
    data_t data;
    struct bst_node* parent;
    struct bst_node* left;
    struct bst_node* right;
};

//Interface bst function
bst_t* create_bst();
node* get_node(data_t new_data);
status_t insert(bst_t* p_bst, data_t new_data);
void* xmalloc(size_t new_size_of_bytes);
void inorder(bst_t* p_bst);
void preorder(bst_t* p_bst);
void postorder(bst_t* p_bst);
void destroy_bst(bst_t* p_bst);
status_t get_inorder_successor(bst_t* p_bst, data_t s_data, data_t* p_succ_data);
status_t get_inorder_predecessor(bst_t* p_bst, data_t s_data, data_t* p_pre_data);
//Auxiliary Routines
static void inorder_nodelevel(node* root_node); 
static void preorder_nodelevel(node* root_node); 
static void postorder_nodelevel(node* root_node);
void destroy_list(node** p_node);
static void destroy_nodelevel(node* root_node);
static node* inorder_successor(node* e_node);

int main(void){
    data_t arr[] = {100, 50, 150, 25, 175, 65, 130, 5};
    bst_t* p_bst = NULL;
    data_t p_succ_data;
    data_t p_pre_data;
    status_t status;

    p_bst = create_bst();
    for(index_t index = 0; index < sizeof(arr) / sizeof(arr[0]); ++index){
        insert(p_bst, arr[index]);
        }

    puts("inorder");
    inorder(p_bst);
    puts("preorder");
    preorder(p_bst);
    puts("postorder");
    postorder(p_bst);
    destroy_bst(p_bst);

    for(index_t index = 0; index < sizeof(arr) / sizeof(arr[0]); ++index){
        status = get_inorder_successor(p_bst, index , &p_succ_data);
        if(status != BST_NO_SUCESSOR)
            printf("NO SUCESSOR PRESENT OF %llu\n", p_succ_data);
        else
            printf("SUCESSOR = %llu\n", p_succ_data);
        }
    
    for(index_t index = 0; index < sizeof(arr) / sizeof(arr[0]); ++index){
        status = get_inorder_predecessor(p_bst, index, &p_pre_data);
        if(status != BST_NO_PREDECESSOR)
            printf("NO PREDECESSOR PRESENT OF %llu\n", p_pre_data);
        else
            printf("PREDECESSOR = %llu\n", p_pre_data);
        }   

    puts("done");
    return (0);
}
node* inorder_successor(node* e_node){

    node* run = NULL;
    node* parent_node = NULL;

    if(e_node->right != NULL){
        run = e_node->right;
        while(run->left != NULL){
            run = run->left;
        }
        return run;
    }
    else{
        run = e_node;
        parent_node = run->parent;
        while(parent_node != NULL && parent_node->right == run){
            run = parent_node;
            parent_node = parent_node->parent;
        }
        return parent_node;
    }
}
static node* inorder_predecessor(node* e_node){
    node* run = NULL;
    node* parent_node = NULL;

    if(e_node->left != NULL){
        run = e_node->left;
        while(run->right != NULL){
            run = run->right;
        }
        return (run);
    }
    else{
        run = e_node;
        parent_node = run->parent;
        while(parent_node != NULL && parent_node->left == run){
            run = parent_node;
            parent_node = parent_node->parent;
        }
        return (parent_node);
    } 
}
status_t get_inorder_predecessor(bst_t* p_bst, data_t s_data, data_t* p_succ_data){
    node* root_node = NULL;
    node* e_node = NULL;
    node* e_pre_node = NULL;

    e_node = (root_node, s_data);
    if(e_node == NULL)
        return (INVALID_BST_DATA);

    e_pre_node = inorder_predecessor(e_node);
    if(e_node == NULL)
        return (BST_NO_PREDECESSOR);   
}
status_t get_inorder_successor(bst_t* p_bst, data_t s_data, data_t* p_succ_data){

    node* root_node = NULL;
    node* e_node = NULL;
    node* e_succ_node = NULL;

    root_node = p_bst->root_node;
    e_node = search_node(root_node, s_data);
    if(e_node == NULL)
        return (INVALID_BST_DATA);

    e_succ_node = inorder_successor(e_node);
    if(e_succ_node == NULL)
        return (BST_NO_SUCESSOR);

    *p_succ_data = e_node->data;
    return(SUCCESS);
}

void destroy_list(node** p_node){
    destroy_nodelevel(*p_node);
    free(*p_node);
    *p_node = NULL;
}
void destroy_bst(bst_t* p_bst){
    destroy_list(&p_bst->root_node);

}

void inorder(bst_t* p_bst){
    printf("[START]<->");
    inorder_nodelevel(p_bst->root_node);
    puts("[END]");
}
void preorder(bst_t* p_bst){
    printf("[START]<->");
    preorder_nodelevel(p_bst->root_node);
    puts("[END]");

}
void postorder(bst_t* p_bst){
    printf("[START]<->");
    postorder_nodelevel (p_bst->root_node);
    puts("[END]");
}

static void inorder_nodelevel(node* root_node){
    if(root_node != NULL){
        inorder_nodelevel(root_node->left);
        printf("[%llu]<->", root_node->data);
        inorder_nodelevel(root_node->right);
    }
}
static void preorder_nodelevel(node* root_node){
    if(root_node != NULL){
        printf("[%llu]<->", root_node->data);
        preorder_nodelevel(root_node->left);
        preorder_nodelevel(root_node->right);
    }

}
static void postorder_nodelevel(node* root_node){
     if(root_node != NULL){
        postorder_nodelevel(root_node->left);
        postorder_nodelevel(root_node->right);
        printf("[%llu]<->", root_node->data);
    }
}

static void destroy_nodelevel(node* root_node){
     if(root_node != NULL){
        destroy_nodelevel(root_node->left);
        destroy_nodelevel(root_node->right);
        free(root_node);
        root_node = NULL;
    }
}

bst_t* create_bst(){
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)malloc(sizeof(bst_t));
    assert(p_bst != NULL);
    p_bst->root_node = NULL;
    p_bst->no_of_element = 0;
    return p_bst;
}

status_t insert(bst_t* p_bst, data_t new_data){

    node* new_node = NULL;
    node* run = NULL;

    if(p_bst->root_node == NULL){
        p_bst->root_node = get_node(new_data);
        p_bst->no_of_element += 1;
        return SUCCESS;
    }
    new_node = get_node(new_data);
    run = p_bst->root_node;

    while(TRUE){
        if(new_data <= run->data){
            if(run->left == NULL){
                run->left = new_node;
                new_node->parent = run;
                break;
            }
            else{
                run = run->left;
            }
        }
        else{
            if(run->right == NULL){
                run->right = new_node;
                new_node->parent = run;
                break;
            }
            else{
                    run = run->right;
            }
        }
    }
    p_bst->no_of_element += 1;
    return SUCCESS;
}

node* get_node(data_t new_data){
    node* p_node = NULL;
    p_node = (node*)xmalloc(sizeof(node));
    p_node->data = new_data;
    p_node->left = NULL;
    p_node->right = NULL;
    p_node->parent = NULL;
    return p_node;
}

void* xmalloc(size_t new_size_of_bytes){
    void* ptr = NULL;
    ptr = malloc(new_size_of_bytes);
    assert(ptr != NULL);
    return ptr;
}