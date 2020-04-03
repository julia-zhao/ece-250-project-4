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
    delete[] array;
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
    int parent1 = array[x].get_head() -> get_parent() -> get_data();
    int parent2 = array[y].get_head() -> get_parent() -> get_data();
    //head pointer of set y is now tail pointer of set x
    array[parent1].merge(array[parent2]);
}
/**
    Find the subset that contains x
    @param x - element in the set
    @return the set that contains x
    
*/
Node* Disjoint_Set::find_set(int x){
    //if the parent is the same then they are part of the same set
    return array[x].get_head() -> get_parent();
}

// debug purposes only
void Disjoint_Set::print(){
    for (int i=0; i<size; i++){
        std::cout << "i: " << i << "---";
        array[i].print();
    }
}