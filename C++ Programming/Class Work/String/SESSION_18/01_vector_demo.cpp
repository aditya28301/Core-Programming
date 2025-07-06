#include <iostream>
#include <string>
#include <vector>

using std::cout;  // Object of class ostrea, | ostream and cout are in std namespace
using std::endl;    // endl define in std namespace
using std::string;  // string in a calss define ins td namespace (header -> string)
using std::vector;  // vector is a 'Class template' defined in std namespace (header -> vector)

class Date{
    private:
        int day, month, year;
    public:
        Date(int init_day, int init_month, int init_year){
            day = init_day; 
            month = init_month;
            year = init_year;
        }

        void show(){
            cout << day << "/" << month << "/" << year << endl;
        }
};

void vector_demo(void);

int main(void){

    vector<int> ivec1;
    vector<int> ivec2;
    vector<int> ivec2{10,20,30,40}; // std:: initializer iterator
    vector<int> ivec2(ivec2);
    vector<int> ivec4(5);
    vector<int> ivec5(5, 100);

    return EXIT_SUCCESS;
}