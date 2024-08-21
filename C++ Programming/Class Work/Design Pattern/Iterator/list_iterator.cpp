#include <cstdio>
#include <cstdlib>
#include <iostream>

const int TEST_DATA = 10;

class node{
    friend class list;
    private:
        size_t data;
        node* next;
        node* prev;

    public:
        node(size_t data_ = 0) : next(0), prev(0), data(data_){
        }
};

class list{
    private:
        node* head_node;
        void generic_insert(node* start, node* mid, node* end){
            mid->prev = start;
            mid->next = end;
            start->next = mid;
            end->prev = mid;
        }

        node* search_node(size_t e_data){
            node* run = 0;
            for(run = head_node->next; run != head_node; run = run->next){
                if(run->data == e_data)
                    return run;
            }
            return 0;
        }

        void generic_delete(node* del){
            node* start = 0;
            node* end = 0;

            start = del->prev;
            end = del->next;

            start->next = end;
            end->prev = start;

            delete del;
        }

    public:
        list() : head_node(new node){
            if(head_node == 0){
                std::cout <<"ERROR IN ALLOCATING THE MEOMARY" <<std::endl;
                exit(EXIT_FAILURE);
            }
            head_node->next = head_node;
            head_node->prev = head_node;
        }

        class iterator;

        iterator begin(){
            iterator itr(head_node->next);
            return itr;
        }

        iterator end(){
            iterator itr(head_node);
            return itr;
        }

        class iterator{
            private:
                node* current_node;
            public:
                iterator();
                iterator(node* current) : current_node(current){
                }

                bool operator!=(const iterator& rhs){
                    return current_node != rhs.current_node;
                }

                bool operator==(const iterator& rhs){
                    return current_node == rhs.current_node;
                }
                // ++inc
               iterator& operator++(){
                    current_node = current_node->next;
                    return *this;
                }

                // inc++
                iterator& operator++(int){
                    iterator itr;
                    itr.current_node = current_node;
                    current_node = current_node->next;
                    return itr;
                }

                bool operator==(const size_t data){
                    return current_node->data == data;
                }

                size_t& operator*(){
                    return current_node->data;
                }
        };

        void insert_start(size_t data){
            generic_insert(head_node, new node(data), head_node->next);
        }

        void insert_end(size_t data){
            generic_insert(head_node->prev, new node(data), head_node);
        }   

        void insert_after(size_t e_data, size_t data){
            node* s_node = 0;
            s_node = search_node(e_data);
            if(s_node == 0){
                std::cout <<"INVALID_DATA" <<std::endl;
                exit(EXIT_FAILURE);
            }
            generic_insert(s_node, new node(data), s_node->next);
        }
        void insert_before(size_t e_data, size_t data){
            node* s_node = 0;
            s_node = search_node(e_data);
            if(s_node == 0){
                std::cout <<"INVALID_DATA" <<std::endl;
                exit(EXIT_FAILURE);
            }
            generic_insert(s_node->prev, new node(data), s_node);
        }

        size_t get_start() const {
            return head_node->next->data;
        }

        size_t get_end() const{
            return head_node->prev->data;
        }

        size_t pop_start(){
            size_t data;
            data = head_node->next->data;
            generic_delete(head_node->next);
            return data;
        }

        size_t pop_end(){
            size_t data;
            data = head_node->prev->data;
            generic_delete(head_node->prev);
            return data;
        }

        void remove_node(size_t d_data){
            node* s_node = 0;;
            s_node = search_node(d_data);
            generic_delete(s_node);
        }

        size_t get_len(){
            node* run = 0;
            size_t len = 0;
            for(run = head_node->next; run != head_node; run = run->next){
                len += 1;
            }
            return len;
        }

        bool isEmpty(){
            return head_node == 0;
        }

};

int main(void){
    size_t data;
    bool status;

    list* stock = new list;
    
    std::cout <<"insert start" <<std::endl;
    for(size_t i = 0; i < TEST_DATA; ++i)
        stock->insert_start(i+1);

    std::cout <<"insert end" <<std::endl;
    for(size_t i = 0; i < TEST_DATA; ++i)
        stock->insert_end(i + 1);

    std::cout <<"INSERT AFTER" << std::endl;
    stock->insert_after(5, 100);

    std::cout <<"INSERT BEFORE" <<std::endl;
    stock->insert_before(100, 200);

    std::cout <<"Printing list using iterator" <<std::endl;
    for(list::iterator itr = stock->begin(); itr != stock->end(); ++itr){
        std::cout <<(*itr)  <<std::endl;
    }
    std::cout <<"GET START DATA"<<std::endl;
    data = stock->get_start();
    std::cout <<"GET START DATA "<<data << std::endl;

    data = stock->get_end();
    std::cout <<"GET LAST DATA " << data << std::endl;

    data = stock->pop_start();
    std::cout <<"POP START DATA " << stock->pop_start() << std::endl;

    data = stock->pop_end();
    std::cout <<"POP END DATA " << data <<std::endl;

    stock->remove_node(100);
    std::cout <<"REMOVE DATA" << std::endl;

    data = stock->get_len();
    std::cout <<"GET LENGHT "<<data <<std::endl;

    status = stock->isEmpty();
    std::cout <<"CHECK IF LIST IS EMPTY " << status <<std::endl;
    
   
    delete stock;
    stock = 0;

    std::cout <<"PROGRAMME TERMINATED SUCCSFULLY" <<std::endl;
    return 0;
}