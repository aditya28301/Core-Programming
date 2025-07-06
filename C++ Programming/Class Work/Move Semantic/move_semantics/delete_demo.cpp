#include <iostream> 
#include <cstdlib> 

class node
{
    friend class list; 
    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int init_data = 0) : data(init_data), prev(0), next(0) {} 
        node(const node&) = delete;                 // node cannot be initialized by other node
        node& operator=(const node&) = delete;      // A node cannot be assigned to another node 
        ~node() = default;                          // Don't do anything with prev, next       
}; 

class list
{
    private: 
        node* p_head_node; 
    public: 
        list()
        {
            p_head_node = new node; 
            p_head_node->prev = p_head_node; 
            p_head_node->next = p_head_node; 
        }

        ~list()
        {
            node* p_run, *p_run_next; 
            for(p_run = p_head_node->next; p_run != p_head_node; p_run = p_run_next)
            {
                p_run_next = p_run->next; 
                delete p_run; 
            }

            delete p_head_node; 
            p_head_node = 0; 
        }

        list(const list& other) = delete;               // cannot initialize a new list by existing one
        list& operator=(const list& other) = delete;    // cannot assign an existing list object by the other 
}; 

int main(void)
{
    list L1; 
    list L2(L1);    // not allowed 
    list L3; 

    L3 = L1;        // not allowed 

}

// Technique prior to delete keyword : C++ 98
// Keep copy constructor and overload assignment operator private   