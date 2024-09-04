#include "Dcl.hpp"

int main(void){
    list* l = 0;
    l = new list;
    l->insert_start(10);
    l->insert_end(20);
    l->insert_after(10, 100);
    l->insert_before(20, 200);
    l->get_start();
    l->get_end();
    l->pop_end();
    l->pop_start();
    l->remove_node(10);
    l->get_len();
    l->isEmpty();
    delete l;
    l = 0;
    return 0;
}