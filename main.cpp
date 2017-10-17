//
// Created by André on 12/10/2017.
//

#include <iostream>
#include <vector>
#include "Graph.h"

int main() {

    Graph *g = new Graph();
    vector<string> nodes  = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13"};

    g->insert_node(nodes);
    vector<pair<string,string>> edges = {
            {"1","2"},{"2","3"},/*{"2","4"},*/{"3","6"},{"4","5"},{"5","3"},{"5","6"},
            {"6","7"},{"6","8"},{"6","9"},{"7","11"},{"8","11"},{"8","10"},
            {"9","8"},{"9","10"},{"11","10"},{"11","12"},{"11","13"},{"8","0"},{"0","8"}
    };

    g->create_edge(edges);

    if (g->isCyclic()){
        g->printStack();
        cout << "Tem ciclo";
    }

    //g->isConnectedBubble();

    return 1;
}