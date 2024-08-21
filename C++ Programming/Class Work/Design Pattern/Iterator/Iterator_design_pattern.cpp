#include <cstdio>
#include <cstdlib>
#include <iostream>

class item{
    private:
        size_t start_item;
        size_t end_item;

    public:
        item(){
        }

        item(size_t range) : start_item(range), end_item(range + 10){
            if(start_item > end_item){
                std::cout <<"starting number is greater than end number" <<std::endl;
                exit(0);
            }
        }

    class iterator;

    iterator begin(void){
        iterator itr(start_item);
        return itr;
    }

    iterator end(void){
        iterator itr(end_item);
        return itr;
    }

    class iterator{
        private:
            size_t current_item;

        public:
            iterator(){
            }

            iterator(size_t current) : current_item(current){
            }

            bool operator!=(const iterator& rhs){
                    return current_item != rhs.current_item;
            }

            bool operator==(const iterator& rhs){
                return current_item == rhs.current_item;
            }

            size_t& operator*(void){
                return current_item;
            }

            // ++inc
            iterator& operator++(){
                current_item += 1;
                return *this;
            }

            // inc++
            iterator& operator++(int){
                iterator itr;
                itr.current_item = current_item;
                current_item+= 1;
                return itr;
            }

            // --inc
            iterator& operator--(){
                current_item -= 1;
                return *this;
            }

            // inc--
            iterator& operator--(int){
                iterator itr;
                itr.current_item  = current_item;
                current_item -= 1;
                return itr;
            }

            bool operator<=(const iterator& rhs){
                return current_item <= rhs.current_item;
            }

    };
};

int main(void){
    size_t count = 0;
    item* i1 = new item(10);

    item::iterator itr = i1->begin();
    for( itr ; itr <= i1->end(); ++itr){
        std::cout <<"item[" << ++count <<"]= " << (*itr) <<std::endl;
    }

    delete i1;
    std::cout <<"Programme terminated succesfully" << std::endl;
    return 0;
}