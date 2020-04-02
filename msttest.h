/*  ECE250 Project 4
    Due Apr 3, 2020    
    Julia Zhao
*/ 

#include <string>

#ifndef INCLUDE_KRUSKAL
#define INCLUDE_KRUSKAL
#include "mst.h"
#endif

void trim_str(std::string &str);
double trim_db(std::string &str);
int trim_int(std::string &str);

std::string temp_str; //to parse through input file
int temp_int;
unsigned int temp_uint;
double temp_double;
MST* set = new MST();
bool valid, get_line;