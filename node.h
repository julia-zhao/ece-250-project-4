/*  ECE250 Project 1
    Due Jan 31, 2020
    Julia Zhao
*/ 

class Node
{
private:
    int data;
    Node* next_node;
    Node* prev_node;
    
public:
    Node();
    Node(int &i);
    Node(int &i, Node* next, Node* prev);
    ~Node(); //doesn't do anything

    int get_data();
    Node* get_next();
    Node* get_prev();

    void set_data(int &i);
    void set_next(Node* next);
    void set_prev(Node* prev);
};


