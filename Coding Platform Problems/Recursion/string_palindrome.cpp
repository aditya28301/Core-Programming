/*
m   a       d    d  a           m
l    l+1     l+2     l-2        l-1

l, l-1 == true
l+1, l-2 == true

*/

#include <cstdio>
#include <cstdlib>
#include <iostream>

const int TRUE   = 1;
const int FALSE  = 0;
typedef unsigned long long int data_t;
typedef int status_t;
status_t isPalindrome(std::string str, data_t size, data_t i);

int main(void){
    std::string str = "Madam";
    status_t status = 0;
    data_t size = 0;
    size = str.length();
    status = isPalindrome(str, size, 0);
    std::cout << str <<" ";
    if(status == TRUE)
        std::cout << "String is palindrome" << std::endl;
    else    
        std::cout << "String is not palindrome" << std::endl;
    std::cout <<"Programe terminated sucesfully"<< std::endl;
    return EXIT_SUCCESS;
}

status_t isPalindrome(std::string str, data_t size, data_t i){
    static data_t status = TRUE;
    if(i >= size/2 || status == FALSE)
        return status;
    if(str[i] != str[size-i-1])
        status = FALSE;
    status = isPalindrome(str, size, i+1);
    return status;
}