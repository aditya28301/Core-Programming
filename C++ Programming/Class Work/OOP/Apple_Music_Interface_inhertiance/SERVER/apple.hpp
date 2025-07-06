#include "IApple.hpp"

class apple : public IApple{
    private:
        std::vector<std::string> song;
        unsigned int price;

    public:
        apple();
        apple(std::string name, unsigned int song_price);
        void play();    
        void pause();    
        void next();        
        void prev();     
        void add_song();
        ~apple();
};