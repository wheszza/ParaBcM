#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>

using namespace std;


struct vertex
{
    int data;
};

class Graph
{

//------------------------------------------------------------
//Variables
//------------------------------------------------------------
public:
    int vertexNum;
    int edgeNum;
    vector<int> vertices;
    vector<vector<int>> edges;

//------------------------------------------------------------
//Constructor
//------------------------------------------------------------
Graph(){
    vertexNum = 0;
    edgeNum = 0;
}

void init(int vNum, int eNum){
    vertexNum = vNum;
    edgeNum = eNum;
    for(int i = 0; i < vertexNum; i++){
        vertices.push_back(0);
        edges.push_back(vector<int>(0));
    }
}

void clear(){
    vertices.clear();
    edges.clear();
    vertexNum = 0;
    edgeNum = 0;
}

/**
 * Adds an edge to the graph.
 *
 * @param from
 *          the starting node of an edge
 * @param to
 *          the final node of an edge
 */

bool addEdge(int from, int to){
    if(from == to){
        return false;
    }
    while(from + 1 > vertexNum){
        vertexNum += 1;
        vertices.push_back(0);
        edges.push_back(vector<int>(0));
    }
    for(int i = 0; i < edges[from].size(); i++){
        if(edges[from][i] == to){
            return false;
        }
    }
    edges[from].push_back(to);
    edgeNum += 1;
    return true;
}


bool deleteEdge(int from, int to){
    if(from > vertexNum){
        return false;
    }
    vector<int>::iterator Iter;
    for(Iter = edges[from].begin(); Iter != edges[from].end(); Iter++){
        if(*Iter == to){
            edges[from].erase(Iter);
            edgeNum -= 1;
            Iter = edges[from].begin();
            return true;
        }
    }
    if(Iter == edges[from].end()){
        return false;
    }
}

int GetvertexNum(){
    return vertexNum;
}

int GetedgeNum(){
    return edgeNum;
}

};

#endif