/*  ECE250 Project 1
    Due Jan 31, 2020
    Julia Zhao
*/ 

#include "node.h"

Node::Node(){} //default constructor, doesn't do anything 
Node::Node(int &i){ //constructor for the head
    data = i;
    next_node = nullptr;
    prev_node = nullptr;
}
Node::Node(int &i, Node* next, Node* prev){ //constructor for enqueue_front
    data = i;
    next_node = next;
    prev_node = prev;
}
Node::~Node(){} //doesn't do anything

int Node::get_data(){
    return data;
}
Node* Node::get_next(){
    return next_node;
}
Node* Node::get_prev(){
    return prev_node;
}
void Node::set_data(int &i){
    data = i;
}
void Node::set_next(Node* next){
    next_node = next;
}
void Node::set_prev(Node* prev){
    prev_node = prev;
}
