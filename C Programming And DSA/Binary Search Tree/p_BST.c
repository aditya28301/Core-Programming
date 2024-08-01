#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TRUE 1
#define INVALID_BST_DATA -1
#define PRED_BST_INVALID -2
#define SUCCESS 11
#define FALSE 0
#define SUCC_BST_INVALID -4
#define TEST_MAX 100

typedef size_t data_t;
typedef data_t index_t;
typedef data_t status_t;
typedef struct bst bst_t;
typedef struct node node_t;

struct node{
    data_t data;
    struct node* parent;
    struct node* left;
    struct node* right;
};

struct bst{
    struct node* root_node;
    size_t no_of_element;
};

//interface function
bst_t* create_bst(void);
void insert(bst_t* p_bst, data_t data);
node_t* search_bst(bst_t* p_bst, data_t s_data);
void destroy_bst(bst_t* p_bst);
status_t get_inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pre_data);
status_t get_inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data);
void inorder(bst_t* p_bst);
void preorder(bst_t* p_bst);
void postorder(bst_t* p_bst);
status_t getMax(bst_t* p_bst, data_t* g_min);
status_t getMin(bst_t* p_bst, data_t* g_max);
status_t remove_bst(bst_t* p_bst, data_t r_data);

//Auxilary function
static node_t* get_node(data_t data);
static void* xmalloc(size_t no_of_required_bytes);
static node_t* inorder_predecessor(node_t* p_node);
static node_t* inorder_successor(node_t* p_node);
static node_t* search_node(node_t* p_node, data_t data);
static void destroy_list(node_t* p_node);
static void inorder_nodelevel(node_t* root_node);
static void preorder_nodelevel(node_t* root_node);
static void postorder_nodelevel(node_t* root_node);
static status_t remove_node(bst_t* p_bst, node_t* e_node);

int main(void){
    bst_t* p_bst = NULL;
    data_t successor_data;
    data_t predecessor_data;
    status_t status;
    data_t Min = 0;
    data_t Max = 0;

    printf("* CREATE BST*\n"); 
    p_bst = create_bst();
    printf("\n");

    printf("* DATA INSERTION*\n");
    for(index_t i = 0; i < TEST_MAX; ++i)
        insert(p_bst, i);

    printf("\n");

    printf("* TREE OPERATION*\n\n");
    printf("* INORDER*\n");
    inorder(p_bst);
    printf("* PREORDER*\n");
    preorder(p_bst);
    printf("* POSTORDER*\n");
    postorder(p_bst);

    puts("* INORDER SUCCESSOR*");
    for(index_t i = 0; i < TEST_MAX; ++i){
        status = get_inorder_successor(p_bst, i, &successor_data);
        if(status == INVALID_BST_DATA || status == SUCC_BST_INVALID)
            printf("INVALID SEARCH DATA = [%llu]\n", i);
        else
            printf("INORDER_SUCESSOR OF [%llu] IS [%llu]\n", i, successor_data);
    }

    printf("\n* INORDER PREDECESSOR*\n");
    for(index_t i = 0; i < TEST_MAX; ++i){
        status = get_inorder_predecessor(p_bst, i, &predecessor_data);
        if(status == INVALID_BST_DATA || status == PRED_BST_INVALID)
            printf("INVALID SEARCH DATA = [%llu]\n", i);
        else    
            printf("INORDER PREDECESSOR OF [%llu] IS [%llu]\n", i, predecessor_data);
    }

    printf("\n* GET MIN AND MAX*\n");
    getMin(p_bst, &Min);
    printf("MINIMUM DATA IN BINARY SEARCH TREE = [%llu]\n", Min);
    getMax(p_bst, &Max);
    printf("MAXIMUM DATA IN BINARY SEARCH TREE = [%llu]\n", Max);
    
    printf("\n* REMOVE NODE\n");
    for(index_t i = 0; i < TEST_MAX; ++i){
        printf("REMOVE [%llu]\n", i);
        remove_bst(p_bst, i);
        puts("REMAINING NODE");
        inorder(p_bst);
    }
    
    printf("* DESTROY BST\n");
    destroy_bst(p_bst);
    puts("END");
    return (0);
}

status_t remove_node(bst_t* p_bst, node_t* e_node){

    node_t* current_node = NULL;\

    current_node = e_node;
    /* case 1 left subtree of node is NULL but Right subtree NULL or May be not NULL */
    if(current_node->left == NULL){
        if(current_node->parent == NULL)
          p_bst->root_node = current_node->right;
        else if(current_node->parent->left == current_node)
            current_node->parent->left = current_node->right;
        else
            current_node->parent->right = current_node->right;  

            if(current_node->right != NULL)
                current_node->right->parent = current_node->parent;        
    }   
    /* case 2 left is not NULL but right is definately NULL*/
    else if(current_node->right == NULL){
        if(current_node->parent == NULL)
            p_bst->root_node = current_node->left;
        else if(current_node->parent->left == current_node)
            current_node->parent->left = current_node->left;
        else 
            current_node->parent->right = current_node->left;

        current_node->left->parent = current_node->parent;
    }
    else{
        node_t* sucessor_node = NULL;
        node_t* run = NULL;

        run = current_node->right;
        /* find successor of node*/ 
        while(run->left != NULL)
            run = run->left;
        sucessor_node = run;

        /* if sucessor is not child of current parent node*/
        if(current_node->right != sucessor_node){
            sucessor_node->parent->left = sucessor_node->right;
            if(sucessor_node->right != NULL)
                sucessor_node->right->parent = sucessor_node->parent;

            sucessor_node->right = current_node->right;
            sucessor_node->right->parent = sucessor_node;    
        }

        sucessor_node->left = current_node->left;
        sucessor_node->left->parent = sucessor_node;
        
        if(current_node->parent == NULL)
            p_bst->root_node = sucessor_node;
        else if(current_node->parent->left  == current_node)
            current_node->parent->left = sucessor_node;
        else
            current_node->parent->right = sucessor_node;

        sucessor_node->parent = current_node->parent;
    }   
    free(current_node);
    current_node = NULL;
    return(SUCCESS);
}
status_t remove_bst(bst_t* p_bst, data_t r_data){
    node_t* root_node = NULL;
    node_t* e_node = NULL;
    status_t status;

    root_node = p_bst->root_node;
    e_node = search_bst(p_bst, r_data);
    if(e_node == NULL)
        return (INVALID_BST_DATA);

    status = remove_node(p_bst, e_node);
    if(status == FALSE)
        return(FALSE);

    return (TRUE);
}
status_t getMin(bst_t* p_bst, data_t* g_min){
    node_t* run = NULL;
    run = p_bst->root_node;
    
    if(run == NULL){
        return(FALSE);
    }

    while(run->left != NULL)
        run = run->left;

    *g_min = run->data;
    return (SUCCESS);
}   

status_t getMax(bst_t* p_bst, data_t* gMax){
    node_t* run = NULL;
    run = p_bst->root_node;

    if(p_bst->root_node == NULL)
        return (FALSE);

    while(run->right != NULL)
        run = run->right;

    *gMax = run->data;
    return (SUCCESS);
}
static void postorder_nodelevel(node_t* p_node){
    node_t* run = NULL;
    run = p_node;
    if(run != NULL){
        postorder_nodelevel(run->left);
        postorder_nodelevel(run->right);
        printf("[%llu]", run->data);
    }
}
void postorder(bst_t* p_bst){
    printf("[START]<->");
    postorder_nodelevel(p_bst->root_node);
    printf("<->[END]\n\n");
}
static void preorder_nodelevel(node_t* p_node)
{
    node_t* run = NULL;
    run = p_node;

    if(run != NULL)
    {
        printf("[%llu]", run->data);
        preorder_nodelevel(run->left);
        preorder_nodelevel(run->right);
    }
}
void preorder(bst_t* p_bst){
    printf("[START]<->");
    preorder_nodelevel(p_bst->root_node);
    printf("<->[END]\n\n");
}
static void inorder_nodelevel(node_t* p_node){
    node_t* run = NULL;
    run = p_node;
    if(run != NULL){
        inorder_nodelevel(run->left);
        printf("[%llu]", run->data);
        inorder_nodelevel(run->right);
    }
}
void inorder(bst_t* p_bst){
    node_t* run = NULL;
    printf("[START]<->");
    inorder_nodelevel(p_bst->root_node);
    printf("<->[END]\n\n");
}
static void destroy_list(node_t* p_node){
    node_t* run = NULL;
    run = p_node;
    if(run != NULL){
        destroy_list(run->left);
        destroy_list(run->right);
        run->left = NULL;
        run->right = NULL;
        run->parent = NULL;
        free(run);
    }
}
void destroy_bst(bst_t* p_bst){
    destroy_list(p_bst->root_node);
    p_bst->root_node = NULL;
}   
node_t* inorder_predecessor(node_t* e_node){
    node_t* run = NULL;
    node_t* parent_node = NULL;
    node_t* child = NULL;

    if(e_node->left != NULL)
    {
        run = e_node->left;
        while(run->right != NULL){
            run = run->right;
        }
        return (run);
    }
    else 
    {
        child = e_node;
        parent_node = child->parent;
        while(parent_node != NULL && parent_node->left == child){
            child = parent_node;
            parent_node = parent_node->parent;
        }       
        return (parent_node);
    }  
}

node_t* inorder_successor(node_t* p_node){
    node_t* parent_node = NULL;
    node_t* child = NULL;
    node_t* run = NULL;

    if(p_node->right != NULL){
        run = p_node->right;
        while(run->left != NULL){
            run = run->left;
        }
        return (run);
    }
    else{
        child = p_node;
        parent_node = child->parent;
        while(parent_node != NULL && parent_node->right == child){
            child = parent_node;
            parent_node = parent_node->parent;
        }
        return (parent_node); 
    }
}
status_t get_inorder_successor(bst_t* p_bst, data_t e_data, data_t* p_succ_data){
    node_t* e_node = NULL;
    node_t* p_succ_node = NULL;

    e_node = search_bst(p_bst, e_data);
    if(e_node == NULL)
        return (INVALID_BST_DATA);
    
    p_succ_node = inorder_successor(e_node);
    if(p_succ_node == NULL)
        return (SUCC_BST_INVALID);
    
    *p_succ_data = p_succ_node->data;
    return (SUCCESS);
}
status_t get_inorder_predecessor(bst_t* p_bst, data_t e_data, data_t* p_pred_data){
    node_t* e_node = NULL;
    node_t* p_pred_node = NULL;

    e_node = search_bst(p_bst, e_data);
    if(e_node == NULL)
        return (INVALID_BST_DATA);

    p_pred_node = inorder_predecessor(e_node);
    if(p_pred_node == NULL)
        return (PRED_BST_INVALID);

    *p_pred_data = p_pred_node->data;
    return(SUCCESS);
}
static node_t* search_node(node_t* p_node, data_t e_data){
    node_t* run = NULL;
    run = p_node;

    while(run != NULL){
        if(run->data == e_data)
            return run; 
        else if(e_data < run->data)
            run = run->left;
        else
            run = run->right;
    }
    return NULL;
}
node_t* search_bst(bst_t* p_bst, data_t e_data){
    return (search_node(p_bst->root_node, e_data));
}

bst_t* create_bst(){
    bst_t* p_bst = NULL;
    p_bst = (bst_t*)malloc(sizeof(bst_t));
    assert(p_bst != NULL);
    p_bst->root_node;
    p_bst->no_of_element;
    return p_bst;
}

void insert(bst_t* p_bst, data_t data){
    node_t* run = NULL;
    node_t* new_node = NULL;

    if(p_bst->root_node == NULL){
        p_bst->root_node = get_node(data);
        p_bst->no_of_element=+ 1;
        return;
    }

    new_node = get_node(data);
    run = p_bst->root_node;

    while(TRUE){
        if(data < run->data){
            if(run->left == NULL){
                run->left = new_node;
                run->left->parent = run;
                break;
            }
            else{
                run = run->left;
            }
        }
        else{
            if(run->right == NULL){
                run->right = new_node;
                run->right->parent = run;
                break;
            }
            else{
                run = run->right;
            }
        }
    }
    p_bst->no_of_element+= 1;
}

node_t* get_node(data_t data){
    node_t* p_node = NULL;
    p_node = (node_t*)xmalloc(sizeof(node_t));
    assert(p_node != NULL);
    p_node->data = data;
    p_node->parent = NULL;
    p_node->left = NULL;
    p_node->right = NULL;
    return p_node;
}

void* xmalloc(size_t no_of_required_bytes){
    void* ptr = NULL;
    ptr = malloc(no_of_required_bytes); 
    assert(ptr != NULL);
    return ptr;
}
