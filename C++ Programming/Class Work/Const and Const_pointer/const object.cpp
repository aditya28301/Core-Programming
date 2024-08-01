#include <cstdio>

class Date {
    private:
        int day;
        int month;
        int year;

    public:
        Date(int day_, int month_, int year_) : year(year_){
            this->day = 10;
            this->month = 3;
        }
        void new_modify() const { //object data being made const
            // this->year = 100; ERROR
            // this->day = 20;  ERROR
        }
        void show() {
            printf("[%d][%d][%d]\n", day, month, year);
        }
};

int main(void){

    Date d1(10,20,30);
    d1.new_modify();
    d1.show();
}