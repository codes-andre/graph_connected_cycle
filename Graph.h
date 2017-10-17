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

    bool verified(string element){
        list<string>::iterator it;
        for (it = stackVisitors.begin(); it != stackVisitors.end(); it++) {
            if (*it == element) {
                return true;
            }
        }
        return false;
    }
    list<string> nodeToString(){
        list<Node*>::iterator it;
        list<string> ret;
        for(it = vertices.begin();it!= vertices.end();it++){
            ret.push_back((*it)->label);
        }
        return ret;
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

    void printVertices(){
        list<Node*>::iterator it;

        for(it = vertices.begin(); it != vertices.end(); it++)
            cout << (*it)->label << endl;
    }
    void printStack(){
        list<string>::iterator it;

        for(it = stackVisitors.begin(); it != stackVisitors.end(); it++)
            cout << *it << endl;
    }
    void printEdges(){
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
    list<string> edgesOut(string p)    {
        list<string> ret;
        list<Edge*>::iterator itE;
        for(itE = edges.begin(); itE != edges.end(); itE++)
            if((*itE)->arco.first->label == p )
                if(!verified((*itE)->arco.second->label))
                   ret.push_back((*itE)->arco.second->label);

        return  ret;
    }

    int bubbleConditional(int cond){
        list<string> nodes = nodeToString();
        list<string>::iterator it1;
        list<string>::iterator it2;
        int x;
        bool ret = false;

        for(it1 = nodes.begin(); it1 != nodes.end(); it1++){
            for(it2 = nodes.begin(); it2 != nodes.end(); it2++){


                if (*it1 != *it2) {
                    cout << *it1 << " busca " <<  *it2 << endl;
                    /*
                    stackVisitors.clear();
                    x = depthFirstSearch(*it1, *it2);
                    if (x == cond) {
                        cout << cond << " foi satisfeito " ;
                        ret = true;
                    }
                    //se em algum momento encontrou 0 2 ou 0 então já sabe-se
                    //se o grafo é não-conexo ou ciclico(ja verificado)
                     */
                }
            }
        }

        return ret;
    }
    bool isCyclic(){
        return bubbleConditional(2); //2 significa que node jfoiverificado
    }

    bool isConnectedBubble(){
        return !bubbleConditional(0); //0 retorna true , significa que nao encontrou um caminho
    }

    //DEPTH FIRST SEARCH - DFS
    int depthFirstSearch(string origin, string destiny){

        if (origin == destiny){
            return 1;
        }else
        {
            if (!verified(origin)){
                stackVisitors.push_back(origin);
                list<string> adjOf = edgesOut(origin);
                list<string>::iterator itAdj;
                int x;
                for(itAdj = adjOf.begin(); itAdj != adjOf.end();itAdj++){
                    x = depthFirstSearch(*itAdj, destiny);
                    if (x == 1) return 1; //encontrou
                }
            }else {

                cout << "ja verificado: " << origin << " - " << destiny << endl;
                return 2; //ciclico
            }
        }
        return 0; // nao encontrou
    }
};


#endif //GRAPH_CONNECTED_CYCLE_GRAPH_H
