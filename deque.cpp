/*  ECE250 Project 1
    Due Jan 31, 2020
    Julia Zhao
*/ 


#ifndef INCLUDE_DEQUE
#define INCLUDE_DEQUE
#include "deque.h"
#endif 

#include <iostream> 

Deque::Deque(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

Deque::~Deque(){
   delete head;
}

Node* Deque::get_head(){
    return head;
}
Node* Deque::get_tail(){
    return tail;
}
int Deque::get_length(){
    return length;
}
void Deque::add_length(){
    length++;
}
void Deque::set_tail(Node* t){
    tail = t;
}

void Deque::merge(Deque& t){
    //merge t to the back of this
    if (length >= t.get_length()){
        //set tail of current Deque to head of t
        tail -> set_next(t.get_head());
        //connect head of t to tail of current Deque
        t.get_head() -> set_prev(tail);
        tail = t.get_tail();
        //set the parent of all nodes in t to be the head
        Node* temp = t.get_head();
        do {
            temp -> set_parent(head);
            temp = temp -> get_next();
            length++; //add 1 length to this deque
        } while (temp != nullptr);
    }
    //merge this to the back of t
    else{
        //set tail of t to head of current Deque
        t.get_tail() -> set_next(head);
        //connect head of current Deque to tail of t
        head -> set_prev(t.get_tail());
        t.set_tail(tail);
        //set the parent of all nodes in this to be the head
        Node* temp = head;
        do {
            temp -> set_parent(t.get_head());
            temp = temp -> get_next();
            t.add_length(); //add 1 length to t
        } while (temp != nullptr);
    }
}

/**  
    Determines if i is in the linked list
    @param i - the integer to be found
    @return if i was found or not
*/
bool Deque::find(int &i){
    if (head!=nullptr){ //list is not empty
        Node* temp = head;
        do {
            if (temp -> get_data() == i){
                return true;
            }
            else {
                temp = temp -> get_next();
            }
        } while (temp != nullptr);
        return false;
    }
    else{
        return false;
    }
}
/**  
    Adds element to back of queue
    @param i - the integer to be added into the queue
    @return void
*/
void Deque::enqueue_back(int &i){
    if (tail!=nullptr){ //list is not empty
        Node* last = new Node(i,nullptr,tail);
        tail -> set_next(last);
        tail = tail -> get_next();
        last -> set_parent(head);
    }
    else{ //first node
        Node* last = new Node(i);
        head = last;
        tail = last;
        last -> set_parent(head);
    }
    length++;
}
/**  
    General functionality for removing item from front of queue. 
    Frees up memory taken by the removed Node since it was dynamically allocated. 
    @return void
*/
void Deque::front_delete(){
    if (head!=nullptr){ //list is not empty  
        if (head -> get_next() != nullptr){ //2 or more elements
            Node* temp = head;
            head = head -> get_next();
            delete temp;
        }
        else{ //only one element
            delete head; //this deletes tail as well since head and tail point to the same node
            head = nullptr;
            tail = nullptr;
        }
    }
    length--;
}
/**  
    Clears the queue if it is not already empty
    @return void
*/
void Deque::clear(){
    if (head!=nullptr){ //list is not empty  
        while(head!=nullptr){
            Deque::front_delete();
        }
    }
    tail=nullptr;
    head = nullptr;
    length=0;
}

/**  
    Prints the queue twice: once front-to-back, then once back-to-front
    @return void
*/
//debug purposes only
bool Deque::print(){
    if (head != nullptr){ //there is at least one element 
        Node* temp = head;
        do{
            std::cout << temp -> get_data();
            temp = temp -> get_next();
			if (temp != nullptr){ //not the last element of the line, print a space
				std::cout << " ";
			}
        }while (temp != nullptr);
        std::cout << std::endl;
		return true;
    }
    std::cout << std::endl;
	return false;
}
