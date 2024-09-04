#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

class IApple{
    public:
        virtual void play()          = 0;
        virtual void pause()         = 0;
        virtual void next()          = 0;   
        virtual void prev()          = 0;
        virtual void add_song()      = 0;
        virtual ~IApple(){}
        static IApple* get_instance(std::string, unsigned int song_price);
        static void release_instance(IApple* release);
};