#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCESS                          1
#define FALSE                           2
#define GRAPH_VERTEX_EXISTS             3
#define GRAPH_INVALID_VERTEX            4
#define GRAPH_INCONSISTENT              5
#define GRAPH_EDGE_EXISTS               6
#define GRAPH_INVALID_REMOVE            7
#define TEST_MAX                        10

typedef struct Graph graph_t;
typedef struct Vertex vertex_t;
typedef struct vertex_relation v_relation_t;
typedef size_t data_t;
typedef size_t vertex_point_t;
typedef int status_t;
typedef size_t index_t;

struct Graph{
    struct Vertex* vertex_list;
    size_t no_of_vertex;
    size_t no_of_edge;
};

struct Vertex{
    size_t vertex_point;   
    struct vertex_relation* r_list;
    struct Vertex* prev;
    struct Vertex* next;
};

struct vertex_relation{
    size_t vertex_point;
    struct Vertex* p_vertex_point;
    struct vertex_relation* prev;
    struct vertex_relation* next;
};

// Auxiliary Function
graph_t* create_graph();
status_t add_vertex(graph_t* p_graph, vertex_point_t v);
void show_graph(graph_t* p_graph);
status_t add_edge(graph_t* p_graph, vertex_point_t v_start, vertex_point_t v_end);
vertex_t* v_search_node(vertex_t* p_vertex, vertex_point_t s_v_point);
v_relation_t* v_relation_search_node(vertex_t* p_vertex, vertex_point_t v);
status_t remove_vertex(graph_t* p_graph, vertex_point_t v);

static vertex_t* v_get_node(vertex_point_t v);
static status_t v_generic_insert(vertex_t* v_start, vertex_t* v_mid, vertex_t* v_end);
static void show_vertex(vertex_t* p_vertex);
static void* xmalloc(size_t size_of_bytes);
static void e_generic_insert(v_relation_t* p_r_start, v_relation_t* p_r_mid, v_relation_t* p_r_end);
static v_relation_t* r_get_node(vertex_point_t , vertex_t* p_vertex);
static void remove_edge(v_relation_t* p_r_node, vertex_point_t v);
static void e_generic_delete(v_relation_t* d_node);

int main(void){
    graph_t* p_graph = NULL;
    status_t status;

    p_graph = create_graph();
    // puts("create_graph()");
    for(index_t i = 0; i < TEST_MAX; ++i){
        status = add_vertex(p_graph, i);
        // puts("add_vertex");
        if(status == GRAPH_VERTEX_EXISTS){
            printf("VERTEX ALREADY PRESENT [%llu]\n", i);
        }
    }

    for(index_t i = 0; i < TEST_MAX; ++i){
        status = add_edge(p_graph, i, i+1);
        // puts("add edges");
        if(status == SUCESS)
            printf("EDGE INSERT [%llu]-[%llu]\n", i+1, i+2);
    }

    for(index_t i = 0; i < TEST_MAX; ++i){
        status = remove_vertex(p_graph, i);
        if(status == SUCESS)
            printf("REMOVE VERTEX AND THEIR EDGE [%llu]\n", i);
    }
    
    show_graph(p_graph);    
    puts("program terminate successfully");
    return (EXIT_SUCCESS);
}

void e_generic_delete(v_relation_t* d_node){
    d_node->next->prev = d_node->prev;
    d_node->prev->next = d_node->next;
    free(d_node);
}

static void remove_edge(v_relation_t* p_r_node, vertex_point_t v){
    v_relation_t* run =  NULL;
    v_relation_t* run_next = NULL;
    v_relation_t* e_node = NULL;
    for(run = p_r_node->next; run != p_r_node; run = run_next){
        run_next = run->next;
        e_node = v_relation_search_node(run->p_vertex_point,v);
        e_generic_delete(e_node);
        free(run);
    }
    free(p_r_node);
}
status_t remove_vertex(graph_t* p_graph, vertex_point_t v){
    vertex_t* e_vertex = NULL;

    e_vertex = v_search_node(p_graph->vertex_list, v);
    if(e_vertex == NULL)
        return (GRAPH_INVALID_REMOVE);

    remove_edge(e_vertex->r_list, v);
    e_vertex->next->prev = e_vertex->prev;
    e_vertex->prev->next = e_vertex->next;
    free(e_vertex);
    return (SUCESS);
}
vertex_t* v_search_node(vertex_t* p_vertex, vertex_point_t s_v_point){
    vertex_t* head_node = NULL;
    vertex_t* run = NULL;

    head_node = p_vertex;
    run = head_node->next;
    while(run != head_node){
        if(run->vertex_point == s_v_point)
            return (run);

        run = run->next;
    }   
    return (NULL);
}

status_t add_edge(graph_t* p_graph, vertex_point_t v_start, vertex_point_t v_end){    
    vertex_t* pv_start = NULL;
    vertex_t* pv_end = NULL;
    v_relation_t* start_in_end = NULL;
    v_relation_t* end_in_start = NULL;

    pv_start =  v_search_node(p_graph->vertex_list, v_start);
    pv_end =    v_search_node(p_graph->vertex_list, v_end);
    // puts("vertex_search_node");
    if(!pv_start && !pv_end)
        return (GRAPH_INVALID_VERTEX);

    if(pv_start != NULL ^ pv_end != NULL)
        return (GRAPH_INCONSISTENT);

    // Check if itis have already relation
    start_in_end = v_relation_search_node(pv_start, v_end);
    // puts("relation_search_node");
    end_in_start = v_relation_search_node(pv_end, v_start);
    if(start_in_end && end_in_start)
        return (GRAPH_EDGE_EXISTS);

    if(start_in_end != NULL ^ end_in_start != NULL)
        return (GRAPH_INCONSISTENT);

    e_generic_insert(pv_start->r_list->prev, r_get_node(v_end, pv_end), pv_start->r_list);
    e_generic_insert(pv_end->r_list->prev, r_get_node(v_start, pv_start), pv_end->r_list);
    
    return (SUCESS);
}

v_relation_t* v_relation_search_node(vertex_t* p_vertex, vertex_point_t v){
    v_relation_t* run = NULL;
    run = p_vertex->r_list->next;
    while(run != p_vertex->r_list){
        if(run->vertex_point == v)
            return (run);
        run = run->next;
    }
    return (NULL);
}

static void e_generic_insert(v_relation_t* p_r_start, v_relation_t* p_r_mid, v_relation_t* p_r_end){
    p_r_mid->prev = p_r_start;
    p_r_mid->next = p_r_end;
    p_r_start->next = p_r_mid;
    p_r_end->prev = p_r_mid;
}

static void show_vertex(vertex_t* p_vertex){
    vertex_t* vertex_run = NULL;
    v_relation_t* edge_run = NULL;

    for(vertex_run = p_vertex->next; vertex_run != p_vertex ; vertex_run = vertex_run->next ){
        printf("[%llu]\t\t->\t\t\t[START]<->", vertex_run->vertex_point);
        for(edge_run = vertex_run->r_list->next; edge_run != vertex_run->r_list; edge_run = edge_run->next){
            printf("[%llu]", edge_run->vertex_point);
        }
        printf("<->[END]\n");
    }   
}

static void show_graph(graph_t* p_graph){
    show_vertex(p_graph->vertex_list);
}

static status_t v_generic_insert(vertex_t* v_start, vertex_t* v_mid, vertex_t* v_end){

    v_mid->prev = v_start;
    v_mid->next = v_end;
    v_start->next = v_mid;
    v_end->prev = v_mid;
    return (SUCESS);
}

status_t add_vertex(graph_t* p_graph, vertex_point_t v){
    vertex_t* e_vertex = NULL;
    e_vertex = v_search_node(p_graph->vertex_list, v);

    if(e_vertex != NULL)    
        return (GRAPH_VERTEX_EXISTS);

    v_generic_insert(p_graph->vertex_list->prev, v_get_node(v), p_graph->vertex_list);
    p_graph->no_of_vertex += 1;
    return (SUCESS);
}

vertex_t* v_get_node(vertex_point_t v){
    vertex_t* p_vertex_node = NULL;
    p_vertex_node = (vertex_t*)xmalloc(sizeof(vertex_t));  
    assert(p_vertex_node != NULL);
    p_vertex_node->vertex_point = v;
    p_vertex_node->r_list = r_get_node(0, NULL);
    p_vertex_node->prev = p_vertex_node;
    p_vertex_node->next = p_vertex_node;

    return (p_vertex_node);
}

v_relation_t* r_get_node(vertex_point_t v, vertex_t* p_vertex){
    v_relation_t* p_v_relation = NULL;

    p_v_relation = (v_relation_t*)xmalloc(sizeof(v_relation_t));
    assert(p_v_relation != NULL);

    p_v_relation->vertex_point = v;
    p_v_relation->p_vertex_point = p_vertex;
    p_v_relation->next = p_v_relation;
    p_v_relation->prev = p_v_relation;
    return (p_v_relation);
}

void* xmalloc(size_t size_of_bytes){
    void* ptr = NULL;
    ptr = malloc(size_of_bytes);
    assert(ptr != NULL);
    return (ptr);
}

graph_t* create_graph(){
    graph_t* p_graph_node = NULL;
    p_graph_node = (graph_t*)xmalloc(sizeof(graph_t));
    assert(p_graph_node != NULL);
    p_graph_node->vertex_list = v_get_node(0);
    p_graph_node->no_of_edge = 0;
    p_graph_node->no_of_edge = 0;
    return p_graph_node;
}

