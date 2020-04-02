/*  ECE250 Project 4
    Due Apr 3, 2020    
    Julia Zhao
*/ 
#ifndef INCLUDE_DSET
#define INCLUDE_DSET
#include "disjoint_set.h"
#endif 

#ifndef INCLUDE_DEQUE
#define INCLUDE_DEQUE
#include "deque.h"
#endif 

#include <iostream>
Disjoint_Set::Disjoint_Set(){
    size = 0;
}
Disjoint_Set::~Disjoint_Set(){
    for (int i=0; i<size; i++){ //delete all Deques
        array[i].~Deque();
    }
    delete[] array; //delete array
}
/**
    Initializes array to size (size)
    This will only get called once at the beginning of the program
    @param size - size of the array
*/
void Disjoint_Set::init(int s){
    size = s;
    array = new Deque[size];
}
/**
    Initializes array to size (size)
    @param size - size of the array
*/
void Disjoint_Set::clear(){
    for (int i=0; i<size; i++){
        array[i].clear();
    }
}
/**
    Creates a set containing x
    @param x - element in the set
*/
void Disjoint_Set::make_set(int x){
    array[x].enqueue_back(x);
}
/**
    Merges two sets
    @param x - first set
    @param y - second set

*/
void Disjoint_Set::union_set(int x, int y){
    //head pointer of set y is now tail pointer of set x
    array[x].merge(array[y]);
    //mark array[y] as empty
    array[y].nullify_head();
}
/**
    Find the subset that contains x
    @param x - element in the set
    @return the set that contains x
    
*/
int Disjoint_Set::find_set(int x){
    for (int i=0; i<size; i++){
        if (array[i].find(x)){ //if the element was found
            return i;
        }
    }
    return -1;
}

void Disjoint_Set::print(){
    for (int i=0; i<size; i++){
        std::cout << "i: " << i << "---";
        array[i].print();
    }
}