#include "list.hpp"

    node::node(data_t _data) : data(_data), next(0){ }

    list::list() : head_node(new node){
        std::cout <<"LIST IS CREATED" << std::endl;
    }

    list::list(list&& rhs){
        head_node = rhs.head_node;
        rhs.head_node = 0;
    }

    void list:: insert_start(data_t new_data){
        generic_insert(head_node, new node(new_data), head_node->next);
        std::cout <<"Insert start() : SUCCESS" << std::endl;
    }

    void list:: insert_end(data_t new_data){
        node* prev_node = 0;
        node* current_node = 0;
        get_last_prev_node(&prev_node, &current_node);
        if(prev_node == 0 && current_node == 0){
            std::cout <<"LIST IS EMPTY NEW DATA INSERT AT A END" << std::endl;
            generic_insert(head_node, new node(new_data), head_node->next);
            return;
        }
        generic_insert(current_node, new node(new_data), current_node->next);
        std::cout <<"Insert End(): SUCCESS" << std::endl;
    }

    void list:: insert_after(data_t e_data, data_t new_data){
        node* prev_node = 0;
        node* current_node = 0;
        find_current_prev_node(&prev_node, &current_node, e_data);
        if(prev_node == 0 &&  current_node == 0){
            std::cout <<"INVALID DATA" << std::endl;
            return;
        }
        generic_insert(current_node, new node(new_data), current_node->next);
        std::cout <<"Insert_after() : SUCCESS" << std::endl;
    }

    void list:: insert_before(data_t e_data, data_t new_data){
        node* prev_node = 0;
        node* current_node = 0;
        find_current_prev_node(&prev_node, &current_node, e_data);
        if(prev_node == 0 && current_node == 0){
            std::cout <<"INVALID DATA" << std::endl;
            return;
        }
        generic_insert(prev_node, new node(new_data), current_node);
        std::cout <<"INSERT BEFORE() : SUCCESS" << std::endl;
    }

    void list:: get_start(){
        data_t get_start_data = -1;
        if(isEmpty() == false){
            get_start_data = head_node->next->data;
            std::cout <<"get_start() = " << get_start_data << std::endl; 
        }
        std::cout <<"LIST IS EMPTY" << std::endl;
    }
    void list:: get_end(){
        data_t get_end_data = -1;
        if(isEmpty() == false){
            node* prev_node = 0;
            node* current_node = 0;
            get_last_prev_node(&prev_node, &current_node);
            get_end_data = current_node->data;
            std::cout <<"get_end() = " << get_end_data << std::endl;
            return;
        }
        std::cout <<"LIST IS EMPTY" << std::endl;
    }

    void list:: pop_start(){
        data_t pop_start_data = -1;
        if(isEmpty() == false){
            pop_start_data = head_node->next->data;
            generic_delete(head_node, head_node->next);
            std::cout <<"pop_start() = " << pop_start_data << std::endl;
        }
        std::cout <<"LIST IS EMPTY" << std::endl;
    }

    void list::pop_end(){
        data_t pop_end_data = 0;
        if(isEmpty() == false){
            node* prev_node = 0;
            node* current_node = 0;
            get_last_prev_node(&prev_node, &current_node);
            if(prev_node == 0 || current_node == 0){

            }   
            pop_end_data = current_node->data;
            generic_delete(prev_node, current_node);
            std::cout <<"pop_end() = " << pop_end_data << std::endl;
            return;
        }
        std::cout <<"LIST IS EMPTY" << std::endl;
    }

    void list:: remove_data(data_t d_data){
        if(isEmpty() == false){
            node* prev_node = 0;
            node* current_node = 0;
            find_current_prev_node(&prev_node, &current_node, d_data);
            if(prev_node == 0 || current_node == 0){
                std::cout <<"INVALID DATA" << std::endl;
                return;
            }
            generic_delete(prev_node, current_node);
            std::cout <<"remove_data() : SUCCESS" << std::endl;
        }
    }

    bool list:: isEmpty(){
        if(head_node->next == 0)            
            return true;
        else
            return false;
    }

    void list:: get_len(){
        data_t len = 0;
        if(isEmpty() == false){
            node* run = head_node->next;
            while(run != 0){
                len += 1;   
                run = run->next;
            }
            std::cout <<"LEN OF LIST = " << len << std::endl;
            return;
        }
        std::cout <<"LIST IS EMPTY" << std::endl;
    }

    void list::generic_insert(node* start, node* mid, node* end){
        mid->next = end;
        start->next = mid;
    }

    void list::get_last_prev_node(node** prev_node, node** current_node){
        node* run = 0;
        node* run_next = 0;
        if(head_node->next != 0){
            run = head_node;
            run_next = head_node->next;

            while(run_next->next != 0){
                run = run_next;
                run_next = run_next->next;
            }
        }
        *prev_node = run;
        *current_node = run_next;
    }

    void list::find_current_prev_node(node** prev_node, node** current_node, data_t e_data){
        node* run = 0;
        node* run_next = 0;
        if(head_node->next != 0){
            run = head_node;
            run_next = head_node->next;
            while(run_next != 0){
                if(run_next->data == e_data){
                    *prev_node = run;
                    *current_node = run_next;
                    return;
                }
                run = run_next;
                run_next = run_next->next;
            }
        }

        *prev_node = run;
        *current_node = run_next;
    }

    void list::generic_delete(node* start, node* d_node){
        start->next = d_node->next;
        delete d_node;
    }

    list::~list(){
        std::cout <<"Destroying list" << std::endl;
        if(head_node != 0){
            if(isEmpty() == false){
                node* run = 0;
                node* run_next = head_node->next;
                while(run_next != 0){
                    run = run_next;
                    run_next = run_next->next;
                    delete run;
                }
            }
            delete head_node;
            head_node = 0;
            if(head_node == 0)
                std::cout <<"list is empty" << std::endl;
            return;
        }
        std::cout <<"LIST IS ALREADY EMPTY : Unable to destroy" << std::endl;
    }

std::ostream& operator<<(std::ostream& os, list& rhs){
        std::cout <<"[START]->";
        // if(rhs.head_node->next == 0)
        //     std::cout <<"YES" << std::endl;

        if(rhs.head_node != 0){
            node* run = rhs.head_node->next;
            while(run != 0){
                std::cout <<"[" << run->data <<"]";
                run = run->next;
            }
        }
        std::cout <<"<-[END]" << std::endl;
        return os;
    }