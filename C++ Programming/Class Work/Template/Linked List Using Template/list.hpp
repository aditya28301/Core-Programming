#ifndef _LIST_HPP_
#define _LIST_HPP_

/*Header files  */
#include <cstdio>
#include <cstdlib>
#include <iostream>

/* Symbolic constant    */
const int TEST_DATA =   1;    
const int TRUE =        2;
const int FALSE =       3;

/* Typedefination   */
typedef int status_t;
typedef unsigned long long int len_t;

template <typename T>  class list;

template <typename T> class node{
    friend class list<T>;
    friend std::ostream& operator<<(std::ostream& os, const list<T>& list_obj);
    private:
        T data;
        node* next;
        node* prev;
        node(const T& data_) : data(data_), next(0), prev(0){
        }
        node() : next(0), prev(0){
        }
};

template <typename T> class list{
    friend std::ostream& operator<<(std::ostream& os, const list<T>& node_obj);
    private:
        node<T>* head_node;
        static void generic_insert(node<T>* start, node<T>* mid, node<T>* end){
            mid->next = end;
            mid->prev = start;
            start->next = mid;
            end->prev = mid;
        }
        static void generic_delete(node<T>* del_node){
            node<T>* start = 0;
            node<T>* end = 0;
            start = del_node->prev;
            end = del_node->next;

            start->next = end;
            end->prev = start;
            delete del_node;
        }
        node<T>* search_node(const T& data){
            node<T>* run = 0;
            run = head_node->next;
            while(run != head_node){
                if(run->data == data)
                    return run;
                run = run->next;
            }
            return 0;
        }

    public:
        list() : head_node(new node<T>){
            head_node->next = head_node;
            head_node->prev = head_node;
        }

        ~list(){
            node<T>* run = 0;
            node<T>* run_next = 0;
            run = head_node->next;
            while(run != head_node){
                run_next = run->next;
                delete run;
                run = run_next;
            }
            delete head_node;
            head_node = 0;
        }

        void insert_start(const T& new_data){
            generic_insert(head_node, new node<T>(new_data), head_node->next);
        }

        void insert_end(const T& new_data){
            generic_insert(head_node->prev, new node<T>(new_data), head_node);
        }

        void insert_after(const T& e_data, const T& new_data){
            node<T>* e_node = 0;
            e_node = search_node(e_data);
            if(e_node == 0){
                std::cout <<"Invalid data" << std::endl;
                return;
            }
            generic_insert(e_node, new node<T>(new_data), e_node->next);
        }

        void insert_before(const T& e_data, const T& new_data){
            node<T>* e_node = 0;
            e_node = search_node(e_data);
            if(e_node == 0){
                std::cout <<"Invalid data" << std::endl;
                return;
            }
            generic_insert(e_node->prev, new node<T>(new_data), e_node);
        }

        void get_start(){
            if(isEmpty_()){
                std::cout <<"List is empty" << std::endl;
                return;
            }
            std::cout <<"get_start() = " << head_node->next->data << std::endl;
        }

        void get_end(){
            if(isEmpty_()){
                std::cout <<"List is empty" << std::endl;
                return;
            }
            std::cout <<"get_end() = " << head_node->prev->data << std::endl;
        }

        void pop_start(){
            if(isEmpty_()){
                std::cout <<"List is empty" << std::endl;
                return;
            }
            std::cout <<"pop_start() = " << head_node->prev->data << std::endl;  
            generic_delete(head_node->next);
        }

        void pop_end(){
            if(isEmpty_()){
                std::cout <<"List is empty" << std::endl;
                return;
            }
            std::cout <<"pop_end() = " << head_node->prev->data << std::endl;  
            generic_delete(head_node->prev);
        }

        void remove_node(const T& d_data){
            if(isEmpty_()){
                std::cout <<"List is empty" << std::endl;
                return;
            }

            node<T>* e_node = 0;
            e_node = search_node(d_data);
            if(e_node == 0){
                std::cout <<"Invalid data " << std::endl;           
                return;
            }       
            generic_delete(e_node);
        }

        status_t isEmpty_(){
             if(head_node->next == head_node){
                return TRUE;
            }
            return FALSE;
        }

        void get_len(){
            node<T>* run = 0;
            len_t len = 0;
            run = head_node->next;
            while(run != head_node){
                len += 1;
                run = run->next;
            }   
            std::cout <<"List len = " << len << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& os, const list<T>& list_obj){
            os <<"[START]<->";
            node<T>* run = 0;
            run = list_obj.head_node->next;
            while(run != list_obj.head_node){
                os <<"[" << run->data <<"]<->";
                run = run->next;
            }
            os <<"[END]" << std::endl;
            return os;
        }   

        class iterator;
        iterator begin(){
            return iterator(head_node->next);
        }
        iterator end(){
            return iterator(head_node);
        }

        class iterator{
            private:
                node<T>* p_node;
            public:
                iterator(node<T>* node) : p_node(node){

                }
                iterator() : p_node(0){

                }
                iterator operator++(){
                    p_node = p_node->next;
                    return *this;
                }

                iterator operator++(int){
                    iterator temp_node(p_node);
                    p_node = p_node->next;
                    return temp_node;
                }
                T operator*(){
                    return p_node->data;
                }
                bool operator!=(const iterator& rhs){
                   return p_node != rhs.p_node; 
                }
                bool operator==(const iterator& other){
                    return p_node == other.p_node; 
                }
        };
};

#endif  /*_LIST_*/