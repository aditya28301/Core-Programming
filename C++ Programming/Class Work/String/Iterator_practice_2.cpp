#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void iterator_practice(void){
    string str_obj("Aditya Ashok Darekar");

    /* iterator using while loop*/

    cout <<"Iterator 1: using while loop" << std::endl;

    string::iterator itr_1_ad = str_obj.begin();
    while(itr_1_ad != str_obj.end()){
        cout << *itr_1_ad;
        ++itr_1_ad;
    }

    cout << endl; 

    cout <<"Iterator 2: using for loop" << std::endl;
    for(string::iterator itr_2_ad = str_obj.begin(); itr_2_ad != str_obj.end(); ++itr_2_ad){   
        cout << *itr_2_ad;
    }

    cout << endl;

    cout <<"Iteator 3: using while loop" << endl;

    string::iterator itr_ad_3 = str_obj.begin(); 

    while(itr_ad_3 != str_obj.end()){
        cout << *itr_ad_3;
        itr_ad_3 = itr_ad_3 + 1;
    }
}

int main(void){
    iterator_practice();
    cout << endl;
    cout <<"Programme terminated succesfully" << endl;
    return EXIT_SUCCESS;
}