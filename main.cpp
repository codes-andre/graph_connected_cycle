//
// Created by André on 12/10/2017.
//

#include <iostream>
#include <vector>
#include "Graph.h"

int main() {

    Graph *g = new Graph();
    vector<string> nodes  = {"A","B","C","D"};

    g->insert_node(nodes);
    g->insert_node("E");
    Node *F = new Node("F");
    g->insert_node(F);

    vector<pair<string,string>> edges = {{"A","B"}, {"B","C"}};

    g->cria_adjacencia(edges);


    g->imprimeEdges();



    return 1;
}