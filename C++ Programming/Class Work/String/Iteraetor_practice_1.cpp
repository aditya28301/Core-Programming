#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void string_iterator_demo(void);

void string_iterator_demo(void){
    
    string s("ABCD");

    // 1. using iterator and while loop
    string::iterator my_iter = s.begin();
    while(my_iter != s.end())
    {
        cout << "Current char:" << *my_iter << endl;
        ++my_iter;
    }

    // 2. using iterator and while loop
    cout <<"Repeat 2:" << endl;
    string::iterator iter_1 = s.begin();
    while(iter_1 != s.end()){
        cout <<"Current char:" << *iter_1 << endl;
        iter_1++;
    }

    // 3: using iterator and while loop
    cout << "Repeat 3:" << endl;
    string::iterator iter_of_s = s.begin();
    while(iter_of_s != s.end()){
        cout <<"iter_of_s:" << *iter_of_s << endl;
    iter_of_s = iter_of_s + 1;
    }
}

int main(void){
    string_iterator_demo();
    cout <<"Programme terminated succesfully" << endl;
    return EXIT_SUCCESS;
}