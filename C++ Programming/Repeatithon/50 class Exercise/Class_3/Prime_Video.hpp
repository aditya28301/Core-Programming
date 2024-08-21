/* Guard    */
#ifndef _PRIME_VIDEO_
#define _PRIME_VIDEO_

/*  Header File */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

/*  Symoblic constant   */
#define CHOICE 3

/* typedef  */
typedef int statu_t;

/* List of Movie Global defination*/

extern char* Horror_movies[];
extern char* action_movies[];
extern char* drama_movies[];
extern char* movie_story[];

/*  Class Prime Video   */
class prime_video{
    friend class list;
     friend std::ostream& operator<<(std::ostream& os, const list& rhs);
    private:
        std::string movie_name;
        double price;
        unsigned int imdb_rating;
        std::string movie_story;
        prime_video* next;
        prime_video* prev;
        prime_video();
        prime_video(std::string name, 
                    double price_, 
                    unsigned int rating, 
                    std::string story);        
};

/* Class vector*/

class list{
    private:
        prime_video* p_list;
        static void generic_insert(prime_video* start, prime_video* mid, prime_video* end);

    public:
        list();
        void add(std::string movie_name, double price, unsigned int imdb_rating, std::string movie_story);
        ~list();
        void add_horror_movie();
        void add_action_movie();
        void add_drama_movie();
        friend std::ostream& operator<<(std::ostream& os, const list& rhs);
};

void run(void);
void show_categories(void);

#endif /*_PRIME_VIDEO_*/        