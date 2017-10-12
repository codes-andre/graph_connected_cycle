//
// Created by André on 12/10/2017.
//

#ifndef GRAPH_CONNECTED_CYCLE_GRAPH_H
#define GRAPH_CONNECTED_CYCLE_GRAPH_H

#include <iostream>
#include <list>
#include <vector>
#include "Edge.h"

using namespace std;

class Graph {
public:
    list<Edge*> edges;
    list<Node*>  vertices;


    void insert_node(Node* n){
        vertices.push_back(n);
    }

    bool insert_node(string rotulo){
        bool ret = true;
        list<Node*>::iterator it;

        for(it = vertices.begin(); it != vertices.end(); it++)
            if((*it)->rotulo == rotulo)
                ret = false;

        if (ret){
            Node* insert = new Node(rotulo);
            vertices.push_back(insert);
        }

        return ret;
    }

    bool insert_node(vector<string> rotulo){
        bool ret = true;

        for(int i = 0; i < rotulo.size(); i++)
            ret = ret && insert_node(rotulo[i]);

        return ret;
    }

    void imprime(){
        list<Node*>::iterator it;

        for(it = vertices.begin(); it != vertices.end(); it++)
            cout << (*it)->rotulo << endl;
    }

    void imprimeEdges(){
        list<Edge*>::iterator it;
        for(it = edges.begin(); it!=edges.end();it++)
            cout << (*it)->arco.first->rotulo << " - " << (*it)->arco.second->rotulo << endl;
    };
    bool cria_adjacencia(string from, string to){
        bool noEdge = true;

        list<Edge*>::iterator it;
        for(it = edges.begin() ; it != edges.end(); it++){
            if ((*it)->arco.first->rotulo == from && (*it)->arco.second->rotulo == to){
                noEdge = false; //ARCO IS ALREADY ON THE GRAPH
                break;
            }
        }

        if (noEdge){
            Node *a = return_node(from).second;
            Node *b = return_node(to).second;
            Edge *New = new Edge(a,b,1);
            edges.push_back(New);
        }

        return noEdge;
    }
    bool cria_adjacencia(vector< pair<string,string>> edges){
        bool ret = true;

        for(int i = 0; i < edges.size(); i++)
            ret = ret && cria_adjacencia(edges[i].first,edges[i].second);

        return ret;
    }
    pair<bool,Node*> return_node(string rotulo){
        pair<bool,Node*> ret;
        ret.first = false;
        ret.second = nullptr;

        list<Node*>::iterator it;
        for (it = vertices.begin(); it != vertices.end(); it++){
            if ((*it)->rotulo == rotulo){
                ret.first = true;
                ret.second = *it;
                break;
            }
        }

        return ret;
    }




};


#endif //GRAPH_CONNECTED_CYCLE_GRAPH_H
