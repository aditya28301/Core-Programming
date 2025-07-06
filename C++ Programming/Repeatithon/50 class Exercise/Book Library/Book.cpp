#include "Book.hpp"

Book::Book(
            std::string book_name, 
            std::string book_desc, 
            std::initializer_list <std::string> authors,
            size_t kindle,
            size_t paperback,
            size_t hardcover,
            std::string seller_address,
            std::string delivery_mode,
            std::string ISBN_number,
            std::string publisher_name,
            size_t Edition,
            size_t month_of_publication,
            size_t year_of_publication,
            size_t day_of_publication,
            size_t rating
        ):
            s_Book_name(book_name),
            s_Book_desc(book_desc),
            author_name(authors),
            o_Payment(kindle, paperback, hardcover),
            o_Address(seller_address, delivery_mode),
            o_Product_details(ISBN_number, publisher_name, Edition),
            Rating(rating),
            o_Date(month_of_publication, year_of_publication, day_of_publication)
        {

        }

std::ostream& operator<<(std::ostream& os, const Book& objbook){
    std::cout <<"Name of the book is = " << objbook.s_Book_name << std::endl;    
    std::cout <<"Book Description = " << objbook.s_Book_desc << std::endl;
    std::cout <<"Author Name = ";
    for(size_t i = 0; i < objbook.author_name.size(); ++i){
        std::cout << objbook.author_name[i];
        if(i != objbook.author_name.size() - 1)
            std::cout <<",";
    }        

    std::cout << std::endl;
    std::cout <<"Payment details " << std::endl;
    std::cout << objbook.o_Payment;   

    std::cout <<"Address Details" << std::endl;
    std::cout <<objbook.o_Address;

    std::cout <<"Product details " << std::endl;
    std::cout << objbook.o_Product_details;

    std::cout <<"Date " << std::endl;
    std::cout << objbook.o_Date;

    return os;
}
