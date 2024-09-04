#ifndef _ILIST_
#define _LIST_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

extern const int INVALID_DATA;
extern const int LIST_IS_EMPTY;
extern const int TRUE;
extern const int FAILURE;
extern const unsigned int TEST_MAX;
extern const int DATA_PRESENT;
extern const int LIST_NOT_EMPTY;

typedef int status_t;
typedef long long unsigned int data_t;

class IList{
    public:
        virtual void insert_start(data_t)                        = 0;
        virtual void insert_end(data_t)                          = 0;
        virtual void insert_after(data_t, data_t)                = 0;
        virtual void insert_before(data_t, data_t)               = 0;
        virtual void get_start(data_t*)                          = 0;
        virtual void get_end(data_t*)                            = 0;
        virtual void pop_start(data_t*)                          = 0;
        virtual void pop_end(data_t*)                            = 0;
        virtual status_t find(data_t)                            = 0;
        virtual status_t isEmpty()                               = 0;
        virtual data_t getLen()                                  = 0;
        virtual void show()                                      = 0;
        virtual ~IList(){ std::cout << "IList destructor is called " << std::endl;}
        static IList* get_instance();
        static void release_instance(IList*);
};

#endif /* _ILIST_*/