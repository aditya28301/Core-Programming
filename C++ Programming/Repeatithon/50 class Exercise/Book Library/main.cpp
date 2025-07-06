#include "Book.hpp"

int main(void){
    Book book1(
        "C++ Programming",
        "The C++ Programming Language, Fourth Edition, delivers meticulous, richly explained, and integrated coverage of the entire language―its facilities, abstraction mechanisms, standard libraries, and key design techniques. Throughout, Stroustrup presents concise, “pure C++11” examples, which have been carefully crafted to clarify both usage and program design. To promote deeper understanding, the author provides extensive cross-references, both within the book and to the ISO standard",
        {"Bjarne Stroustrup", "Ken Thompson"},
        5000,
        6000,
        10000,
        "AT&T Bell Labrotaries",
        "Express Delivery",
        "0321958322",
        "Addison-Wesley Professional",
        4,
        1,
        1,
        2016,
        9
    );
    std::cout <<book1 << std::endl;
    std::cout <<"Program terminated sucesfully";
    return EXIT_SUCCESS;
}