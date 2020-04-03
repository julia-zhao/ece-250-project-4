/*  ECE250 Project 1
    Due Jan 31, 2020
    Julia Zhao
*/ 

#ifndef INCLUDE_NODE
#define INCLUDE_NODE
#include "node.h"
#endif

class Deque
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    Deque();
    ~Deque();

    Node* get_head();
    Node* get_tail();
    int get_length();
    void add_length();
    void set_tail(Node*);
    void merge(Deque& t);

    bool find(int &i);
    void enqueue_front(int &i);
    void enqueue_back(int &i);
    void front_delete();
    void dequeue_front();
    void dequeue_back();
    void clear();
    void front(int &i);
    void back(int &i);
    void empty();
    void size();
    bool print();
};

class deque_empty{};
