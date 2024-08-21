#include "Prime_Video.hpp"

char* horror_movies[] = {
    "Conjuring",
    "Anabella",
    "Pachadalela",
    "1920"
};

char* action_movies[] = {
    "Intrestallar",
    "Mission Impossible",
    "The Karate Kid",
    "Krish-3"
};

char* drama_movies[]={
    "The Godfather (1972)",
    "Schindler's List (1993)",
    "Casablanca (1942)",
    "12 Angry Men (1957)"
};

char* movie_story[]={
    "In a post-apocalyptic wasteland, Max teams up with Furiosa to escape a tyrant and his army, leading to a high-octane chase across the desert",
    "A retired hitman seeks vengeance for the killing of his beloved dog, taking on the underworld that once controlled him",
    "The Shawshank Redemption, Wrongfully imprisoned, Andy Dufresne befriends fellow inmate Red, and the two men find solace and eventual redemption through acts of common decency",
    "Based on the life of John Nash, a brilliant mathematician who struggles with schizophrenia, but ultimately triumphs in his personal and professional life",
    "Paranormal investigators Ed and Lorraine Warren help a family terrorized by a dark presence in their farmhouse, leading to terrifying encounters"
};

void show_categories(){
    std::cout <<"1.Horror/n2.Action/n3.Drama"<<std::endl;
}

void list::generic_insert(prime_video* start, prime_video* mid, prime_video* end){
    mid->next = end;
    mid->prev = start;
    start->next = mid;
    end->prev = mid;
}

void list::add(std::string movie_name, double price, unsigned int imdb_rating, std::string movie_story){
    generic_insert(p_list->prev, new prime_video(movie_name, price, imdb_rating, movie_story), p_list);
}

list::list() : p_list(new prime_video){
        if(p_list == 0)
            exit(0);

        p_list->next = p_list;
        p_list->prev = p_list;
    }

prime_video::prime_video():
    movie_name(""), 
    price(0.00), 
    imdb_rating(0),    
    movie_story(""),
    next(0),
    prev(0){}

list::~list(){
    free(p_list);
}

void list::add_horror_movie(){
    for(size_t i = 0; i < sizeof(horror_movies) / sizeof(char*); ++i){
        add(horror_movies[i], rand(), rand(), movie_story[i]);
    }
}

void list::add_action_movie(){
    for(size_t i = 0; i < sizeof(horror_movies) / sizeof(char*); ++i){
        add(action_movies[i], rand(), rand(), movie_story[i]);
    }
}

void list::add_drama_movie(){
    for(size_t i = 0; i < sizeof(horror_movies) / sizeof(char*); ++i){
        add(drama_movies[i], rand(), rand(), movie_story[i]);
    }
}

std::ostream& operator<<(std::ostream& os, const list& rhs){
    prime_video* run = 0;
    for(run = rhs.p_list->next; run != rhs.p_list; run = run->next){
        os  <<"Movie Name-  "  << run->movie_name <<std::endl    
            <<"Movie Price-  " << run->price << std::endl   
            <<"Movie Rating-  "<< run->imdb_rating << std::endl   
            <<"Movie Story-  " << run->movie_story << std::endl <<std::endl
            <<"-----------------------------------------------------------------------------------------------------------" <<std::endl;
    }
    return os;
}

prime_video::prime_video(std::string name, 
                    double price_, 
                    unsigned int rating, 
                    std::string story):
                    movie_name(name), price(price_), imdb_rating(rating), movie_story(story){}

