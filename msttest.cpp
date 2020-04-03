/*  ECE250 Project 4
    Due Apr 3, 2020    
    Julia Zhao
*/ 

#include <iostream> 
#include <string>

#ifndef INCLUDE_DRIVER
#define INCLUDE_DRIVER
#include "msttest.h"
#endif 

/**  
    Trims the beginning and end white spaces for strings
    @param str - the string to trim
    @return void
*/
void trim_str(std::string &str){
    int str_start = str.find_first_not_of(" \t");
    int str_end = str.find_last_not_of(" \t");
    int str_range = str_end - str_start + 1;

    str = str.substr(str_start, str_range);
}
/**  
    Trims the beginning and end white spaces for doubles
    @param str - the string to trim
    @return the double 
*/
double trim_db(std::string &str){
    int str_start = str.find_first_not_of(" \t");
    int str_end = str.find_last_not_of(" \t");
    int str_range = str_end - str_start + 1;
    str = str.substr(str_start, str_range);
    return std::stod(str);
}
/**  
    Trims the beginning and end white spaces for ints
    @param str - the string to trim
    @return the int
*/
int trim_int(std::string &str){
    int str_start = str.find_first_not_of(" \t");
    int str_end = str.find_last_not_of(" \t");
    int str_range = str_end - str_start + 1;

    str = str.substr(str_start, str_range);
    return std::stoi(str);
}

int main (void){        
     while (!std::cin.eof()){
        valid = true;
        get_line = true;
        std::cin >> temp_str;

        if (temp_str.compare("n") == 0){ //specify number of nodes
            std::cin >> temp_int;
            try{
                set -> num_nodes(temp_int);
                std::cout << "success";
            }catch(illegal_argument){ //number of nodes < 0
                std::cout << "failure" << std::endl;
                return 0; //the program will terminate as per project specs
            }
        }
        else if (temp_str.compare("i") == 0){ //inserts edge between nodes
            std::getline(std::cin, temp_str);
            get_line = false;
            try{
                temp_int = temp_str.find(";");

                std::string t = temp_str.substr(0, temp_int);
                int u = trim_int(t);  

                temp_str = temp_str.substr(temp_int + 1, temp_str.length()); //the rest of the line
                temp_int = temp_str.find(";");

                t = temp_str.substr(0, temp_int);
                int v = trim_int(t);  

                t = temp_str.substr(temp_int + 1, temp_str.length());
                double w = trim_db(t);

                set -> insert_edge(u,v,w);
                std::cout << "success";
            }catch(illegal_argument){ 
                std::cout << "failure";
            }
        }
        else if (temp_str.compare("d") == 0){
            std::getline(std::cin, temp_str);
            get_line = false;
            try{
                temp_int = temp_str.find(";");

                std::string t = temp_str.substr(0, temp_int);
                int u = trim_int(t);  

                t = temp_str.substr(temp_int + 1, temp_str.length());
                int v = trim_int(t);  
                bool temp_bool = set -> delete_edge(u,v);
                if (temp_bool){
                    std::cout << "success"; 
                }
                else{
                    std::cout << "failure";
                }
            }catch(illegal_argument){ 
                std::cout << "failure";
            }
        }
        else if (temp_str.compare("degree") == 0){
            std::cin >> temp_int;
            try{
                temp_uint = set -> degree(temp_int);
                std::cout << "degree of " << temp_int << " is " << temp_uint;
            }catch(illegal_argument){ 
                std::cout << "failure";
            }
        }
        else if (temp_str.compare("edge_count") == 0){
            temp_int = set -> edge_count();
            std::cout << "edge count is " << temp_int;
        }
        else if (temp_str.compare("clear") == 0){
            set -> clear();
            std::cout << "success";
        }
        else if (temp_str.compare("mst") == 0){
            try{
                temp_double = set -> mst();
                if (temp_double > -1){
                    std::cout << "mst " << temp_double;
                }
                else{
                    std::cout << "not connected";
                }
            }catch(illegal_argument){ 
                std::cout << "not connected";
            }
        }
        else{
            //invalid command, will ignore and continue
            valid = false;
        }
        
        if (get_line == true){
            std::getline(std::cin, temp_str); //throw out the rest of the line if there are trailing spaces or additional characters
        }
        
        if (valid == true){
            std::cout << std::endl;
        }

        temp_str = "";

        // std::cout << "----------" << std::endl;

    } //end of file
    set -> ~MST();
    
    return 0;
}
