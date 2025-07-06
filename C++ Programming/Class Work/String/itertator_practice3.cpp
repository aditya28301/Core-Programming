#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

void iterator_practice(void);

int main(void){

    return EXIT_SUCCESS;
}

void iterator_practice(void){

    string str_obj("Aditya");

    cout <<"Iterator 1: using while loop" << endl;
    string::iterator itr_1_ad = str_obj.begin();

    while(itr_1_ad != str_obj.begin()){
        cout << *itr_1_ad;
        ++itr_1_ad;
    }

    cout <<"Iterator 2: using for loop" << endl;

    for(string::iterator itr_2_ad = str_obj.begin(); itr_2_ad != str_obj.end(); ++itr_2_ad){
        cout << *itr_2_ad;
    }   

    cout <<"Iterator 3: using for while" << endl;
    string::iterator itr_3_ad = str_obj.begin(); 
    
    while(itr_3_ad != str_obj.end()){
        cout << *itr_3_ad;
        itr_3_ad = itr_3_ad + 1;
    }

}