//
// Created by André on 12/10/2017.
//

#ifndef GRAPH_CONNECTED_CYCLE_EDGE_H
#define GRAPH_CONNECTED_CYCLE_EDGE_H

#include "Node.h"
#include <list>

using namespace std;

class Edge {

public:
    int peso;
    pair<Node*,Node*> arco;

    Edge(Node *a,Node *b, int p){
        arco.first = a;
        arco.second = b;
        peso = p;
    }
};


#endif //GRAPH_CONNECTED_CYCLE_EDGE_H
