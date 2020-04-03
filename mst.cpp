/*  ECE250 Project 4
    Due Apr 3, 2020    
    Julia Zhao
*/ 

#ifndef INCLUDE_KRUSKAL
#define INCLUDE_KRUSKAL
#include "mst.h"
#endif

#ifndef INCLUDE_DSET
#define INCLUDE_DSET
#include "disjoint_set.h"
#endif 

#include <algorithm>
#include <iostream> 
MST::MST(){
    size = -1;
    edges = 0;
}

MST::~MST(){
    //delete array
    for (int i=0; i<size; i++){
        delete[] array[i];
    }
    delete[] array;
}

/**
    Defines number of nodes in mst
    @param m = number of nodes
*/
void MST::num_nodes(int m){
    if (m<=0){
        throw illegal_argument();
    }
    else{
        size = m;
        //dynamically create adjacency 2d matrix
        array = new double*[size];
        for (int i=0; i<size; i++){
            array[i] = new double[size];
        }
        //set all values to 0
        clear();
    }   
}
/**
    Inserts edge between u and v    
    @param u = first vertex
    @param v = second vertex
    @param w = weight of edge
*/
void MST::insert_edge(int u, int v, double w){
    //w<=0 or u or v is outside of the range or if it is a self edge (as specified by piazza)
    if (w<=0 || (u<0 || u>size-1) || (v<0 || v>size-1) || (u==v)){
        throw illegal_argument();
    }
    //create edge if it doesnt already exist
    if (array[u][v]==0){
        edges++;    
    }
    //update weight of edge
    array[u][v] = w;
    array[v][u] = w;
}
/**
    Deletes edge between u and v
    @param u = first vertex
    @param v = second vertex
*/
bool MST::delete_edge(int u, int v){
    //u or v is outside of the range
    if ((u<0 || u>size-1) || (v<0 || v>size-1)){
        throw illegal_argument();
    }
    //the edge doesn't exist
    else if (array[u][v]==0){
        return false;
    }
    //the edge exists so delete the edge
    edges--;
    array[u][v] = 0;
    array[v][u] = 0;
    return true;
}
/**
    Returns degree of vertex u
    @param u = first vertex
    @return degree of u
*/
unsigned int MST::degree(int u){
    //if u is out of range 
    if (u<0 || u>size-1){
        throw illegal_argument();
    }

    unsigned int counter = 0;
    for (int i=0; i<size; i++){
        if (array[u][i]!=0 && i!=u){
            counter++;
        }
    }
    return counter;
}
/**
    Number of edges in graph
    @return number of edges
*/
unsigned int MST::edge_count(){
    return edges;
}
/**
    Removes all edges from graph
*/
void MST::clear(){
    edges = 0;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            array[i][j] = 0;
        }
    }
}

/**
    Calculates MST and returns total weight
    @return total weight of MST
*/
double MST::mst(){
    if (size == 1){
        return -1;
    }
    Disjoint_Set* DSet = new Disjoint_Set();
    DSet -> init(size);
    Edge edge_array[edges];
    int counter = 0;

    //since the edges are unweighted, the edge from a to b is equal to the edge from b to a
    //so, only traverse the right diagonal half of the matrix
    for (int i=0; i<size; i++){
        for (int j=i; j<size; j++){ 
            if (array[i][j] != 0){
                Edge temp;
                temp.weight = array[i][j];
                temp.src = i;
                temp.dest = j;
                edge_array[counter] = temp;
                counter++;
            }
        }
    }

    //sort by weight
    std::sort(edge_array,edge_array+edges,[](const Edge& left, const Edge& right){return left.weight < right.weight;});
   
    double mst_size= 0;

    //initialize disjoint sets
    for (int i=0; i<size; i++){
        DSet -> make_set(i);
    }

    int u,v,u_set,v_set;
    for (int i=0; i<edges; i++){
        u = edge_array[i].src;
        v = edge_array[i].dest;
        if (DSet -> find_set(u) != DSet -> find_set(v)){
            DSet -> union_set(u,v);
            mst_size+=edge_array[i].weight; //one edge has been added to MST
        }
    }

    //check that MST is all connected
    Node* parent = DSet -> find_set(0);
    for (int i=1; i<size; i++){
        if (DSet -> find_set(i) != parent){
            return -1;
        }
    }

    DSet -> ~Disjoint_Set();
    return mst_size;
}