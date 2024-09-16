#include "list.hpp"

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date() : day(1), month(1), year(1967){

        }

        Date(int day_, int month_, int year_) : day(day_), month(month_), year(year_){

        }
        bool operator==(const Date& other){
            return day == other.day && month == other.month && year == other.year; 
        }
        friend std::ostream& operator<<(std::ostream& os, const Date& date_object);
};

std::ostream& operator<<(std::ostream& os, const Date& date_obj){
            os << date_obj.day << "/" << date_obj.month <<"/" << date_obj.year;
            return os;
}

int main(void){
    list<int> intList;
    list<float> floatList;
    list<Date> dateList;

    intList.insert_start(10);
    intList.insert_start(20);
    intList.insert_start(30);

    floatList.insert_end(1.1);
    floatList.insert_end(2.2);
    floatList.insert_end(3.3);

    Date d1(28,3,2001);
    Date d2(1,10,2001);
    Date d3(5,7,2001);

    dateList.insert_end(d1);
    dateList.insert_end(d2);
    dateList.insert_end(d3);

    std::cout <<"intList= " << intList << std::endl;
    std::cout <<"floatList= " <<floatList << std::endl;
    std::cout <<"dateList= " <<dateList << std::endl;
    
    std::cout <<"Printing the list element using iterator design pattern" << std::endl;
    std::cout <<"intList " << std::endl;
    for(
        list<int>::iterator itr = intList.begin();
        itr != intList.end();
        ++itr){
        std::cout << *itr <<"->";
    }

    std::cout <<std::endl <<"floatList " << std::endl;
    for(
        list<float>::iterator itr = floatList.begin();
        itr != floatList.end();
        ++itr){
        std::cout << *itr <<"->";
    }

    std::cout <<std::endl <<"datetList " << std::endl;
    for(
        list<Date>::iterator itr = dateList.begin();
        itr != dateList.end();
        ++itr){
        std::cout << *itr <<"->";
    }

    std::cout <<"Program terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}