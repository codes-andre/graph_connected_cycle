//
// Created by André on 12/10/2017.
//

#include <iostream>
#include <vector>
#include "Graph.h"

int main() {

    Graph *g = new Graph();
    vector<string> nodes  = {"0","1","2","3","4","5","6","7","8","9","10"};

    g->insert_node(nodes);
    vector<pair<string,string>> edges = {
            {"0","1"}, {"0","2"}, {"0","3"}, {"1","4"}, {"1","5"}, {"1","7"},
            {"2","8"}, {"3","9"}, {"3","10"}, {"7","5"}
    };

    g->create_edge(edges);
    g->depthFirstSearch("0", "10");
    g->imprimeEdges();

    return 1;
}