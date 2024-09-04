#include "apple.hpp"

apple::apple() : price(0){

}
apple::apple(std::string name, unsigned int song_price) : price(song_price){
    song.push_back(name);
}

void apple::play(){
    unsigned int choose = 0;    
    choose = rand() % song.size();
    std::cout <<"song playing currently is " <<song[choose] << std::endl;
}

void apple::pause(){
    unsigned int choose = 0;    
    choose = rand() % song.size();
    std::cout <<"song pause currently is " <<song[choose] << std::endl;
}

void apple::next(){
    unsigned int choose = 0;    
    choose = rand() % song.size();
    std::cout <<"song playing next is " <<song[choose] << std::endl;
}

void apple::prev(){
    unsigned int choose = 0;    
    choose = rand() % song.size();
    std::cout <<"song playing prev is " <<song[choose] << std::endl;
}

void apple::add_song(){
    unsigned int choose = 0;    
    choose = rand() % song.size();
    std::cout <<"song newely added is " <<song[choose] << std::endl;
}

IApple* IApple::get_instance(std::string name, unsigned int song_price){
    return new apple(name, song_price);
}

void IApple::release_instance(IApple* release){
    delete release;
}

apple::~apple(){
    std::cout <<"Derived class destructor called" << std::endl;
}