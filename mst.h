/*  ECE250 Project 4
    Due Apr 3, 2020    
    Julia Zhao
*/ 

#ifndef INCLUDE_DSET
#define INCLUDE_DSET
#include "disjoint_set.h"
#endif 

class MST{
    struct Edge{
        double weight;
        int src, dest;
    };

    public:
        int size;
        unsigned int edges;
        double** array;

        MST();
        ~MST();

        void num_nodes(int m);
        void insert_edge(int u, int v, double w);
        bool delete_edge(int u, int v);
        unsigned int degree(int u);
        unsigned int edge_count();
        void clear();
        double mst();
    };
class illegal_argument{};