#include "Payment.hpp"

Payment::Payment(
            size_t i_kindle, 
            size_t i_paperback, 
            size_t i_hardcover
        ):  kindle(i_kindle), paperback(i_paperback), hardcover(i_hardcover){

        }

std::ostream& operator<<(std::ostream& os, const Payment& objpayment){
    std::cout <<"Kindle price = " << objpayment.kindle << std::endl;
    std::cout <<"Paperback Price = " << objpayment.paperback << std::endl;
    std::cout <<"Hardcover = " << objpayment.hardcover << std::endl;
    return os;
}