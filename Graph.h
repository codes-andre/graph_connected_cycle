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
private:
    list<string> stackVisitors;

    bool find(string element){
        list<string>::iterator it;
        for (it = stackVisitors.begin(); it != stackVisitors.end(); it++)
            if (*it == element)
                return true;
        return false;
    }
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
            if((*it)->label == rotulo)
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
            cout << (*it)->label << endl;
    }
    list<string> edgesOf(string p)
    {
        list<string> ret;
        list<Edge*>::iterator itE;
        for(itE = edges.begin(); itE != edges.end(); itE++)
            if((*itE)->arco.first->label == p )
                ret.push_back((*itE)->arco.second->label);

        return  ret;
    }
    void imprimeEdges(){
        list<Edge*>::iterator it;
        for(it = edges.begin(); it!=edges.end();it++)
            cout << (*it)->arco.first->label << " - " << (*it)->arco.second->label << endl;
    };
    bool create_edge(string from, string to){
        bool noEdge = true;

        list<Edge*>::iterator it;
        for(it = edges.begin() ; it != edges.end(); it++){
            if ((*it)->arco.first->label == from && (*it)->arco.second->label == to){
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
    bool create_edge(vector<pair<string, string>> edges){
        bool ret = true;

        for(int i = 0; i < edges.size(); i++)
            ret = ret && create_edge(edges[i].first, edges[i].second);

        return ret;
    }
    pair<bool,Node*> return_node(string rotulo){
        pair<bool,Node*> ret;
        ret.first = false;
        ret.second = nullptr;

        list<Node*>::iterator it;
        for (it = vertices.begin(); it != vertices.end(); it++){
            if ((*it)->label == rotulo){
                ret.first = true;
                ret.second = *it;
                break;
            }
        }

        return ret;
    }

    //DEPTH FIRST SEARCH - DFS
    int depthFirstSearch(string origin, string destiny){
        if (origin == destiny){
            cout << origin;
            return 1;
        }else{
            if (!find(origin)){
                stackVisitors.push_back(origin);
                list<string> adjOf = edgesOf(origin);
                list<string>::iterator itAdj;
                int x;
                for(itAdj = adjOf.begin(); itAdj != adjOf.end();itAdj++){
                    x = depthFirstSearch(*itAdj, destiny);
                    if (x == 1)
                        return 1;
                }
            }else{
                cout << "There are cycle" << endl;
            }
        }
        return 0;
    }
};


#endif //GRAPH_CONNECTED_CYCLE_GRAPH_H
