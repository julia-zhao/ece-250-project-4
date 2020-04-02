/*  ECE250 Project 4
    Due Apr 3, 2020    
    Julia Zhao
*/ 

#ifndef INCLUDE_DEQUE
#define INCLUDE_DEQUE
#include "deque.h"
#endif 

class Disjoint_Set
{
    public: 
        Deque* array;
        int size;

        Disjoint_Set();
        ~Disjoint_Set();

        void init(int s);
        void clear();
        void make_set(int x);
        void union_set(int x, int y);
        int find_set(int x);
        void print();
};