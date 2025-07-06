#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void iterator_practice(void);

int main(void){
    iterator_practice();
    cout << endl;
    cout <<"Programme terminated sucesfully" << endl;
    return EXIT_SUCCESS;
}

void iterator_practice(void){

    string str_obj("Aditya Ashok Darekar");

    cout <<"Iteartor 1 : using while loop" << endl;
    string::iterator itr_ad_1 = str_obj.begin();

    while(itr_ad_1 != str_obj.end()){
        cout << *itr_ad_1;
        ++itr_ad_1;
    }   

    cout << endl;

    cout <<"Iteartor 2: using for loop" << endl;
    for(string::iterator itr_ad_2 = str_obj.begin(); itr_ad_2 != str_obj.end() ; ++itr_ad_2){
        cout << *itr_ad_2;
    }

    cout << endl;


    cout <<"Iteartor 3: using while loop" << endl;
    string::iterator itr_ad_3 = str_obj.begin();

    while(itr_ad_3 != str_obj.end()){
        cout << *itr_ad_3;
        itr_ad_3 = itr_ad_3 + 1;
    }
}