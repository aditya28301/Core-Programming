#include "Prime_Video.hpp"

int main(void){
    run();
    std::cout <<"PROGRAMMER TERMINATED SUCESSFULLY";
}

void run(void){
    list* horror_movie_list = 0;
    list* action_movie_list = 0;
    list* drama_movie_list = 0;

    horror_movie_list = new list;
    action_movie_list = new list;
    drama_movie_list = new list;

    size_t object_count = 0;
    int choice = -1;

    do{
        std::cout << "Select a category of a movie" <<std::endl;
        show_categories();
        choice = CHOICE;
    }
    while(choice < 0);
    std::cout <<"Adding movie into the library" <<std::endl << std::endl;
    switch(choice){    
        case 1:
            horror_movie_list->add_horror_movie();
        break;

        case 2:
            action_movie_list->add_action_movie();
        break;

        case 3:
            drama_movie_list->add_drama_movie();
        break;
    }

    std::cout <<"Get list of Movie and details" << std::endl <<std::endl;
    std::cout << *horror_movie_list;
    std::cout << *action_movie_list;
    std::cout << *drama_movie_list;
    
    delete horror_movie_list;
    horror_movie_list = 0;

    delete action_movie_list;
    action_movie_list = 0;

    delete drama_movie_list;
    drama_movie_list = 0;
}   
