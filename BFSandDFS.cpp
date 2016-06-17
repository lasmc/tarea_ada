//
//  main.cpp
//  bpsanddps
//
//  Created by Luis Alberto Sanchez Moreno on 06/16/16.
//  Copyright © 2016 Luis Alberto Sanchez Moreno. All rights reserved.
//

#include "iostream"
#include "vector"
#include "list"

enum color{
    WHITE,
    GREY,
    BLACK
};

struct edge{
    int destination_vertex;
    edge(int ver){
        destination_vertex = ver;
    }
};

struct vertex{
    int id;
    color visited;
    std::list<edge>  list;
    vertex(int _id){
        id = _id;
    }
};


class graph
{
private:
    std::vector<vertex> vertexes;
    void dfs_visits(vertex& source);
    int next;
public:
    graph(void){
        next = 0;
    }
    ~graph(void){}
    void dfs();
    void bfs();
};



void graph::dfs(void)
{
    for(std::vector<vertex>::iterator iter =vertexes.begin();iter < vertexes.end();iter++ ){
        iter->visited = WHITE;  
    }   

    for(std::vector<vertex>::iterator iter =vertexes.begin();iter < vertexes.end();iter++ ){
        if(iter->visited == WHITE){
            dfs_visits(*iter);
        }
    }
}


void graph::dfs_visits(vertex& source){
    source.visited = GREY;
    for(std::list<edge>::iterator iter = source.list.begin();iter != source.list.end();iter++){
        if(vertexes[iter->destination_vertex].visited == WHITE){
            dfs_visits(vertexes[iter->destination_vertex]);
        }
    }
    source.visited = BLACK;
    std::cout<< source.id <<std::endl;
}

void graph::bfs(){

    for(std::vector<vertex>::iterator iter=vertexes.begin();iter != vertexes.end();iter++){
        iter->visited = WHITE;
    }

    std::queue<vertex*> bsf_q;

    bsf_q.push(&vertexes[0]);

    while(!bsf_q.empty()){
        vertex * v = bsf_q.front();
        bsf_q.pop();

        for(std::list<edge>::iterator iter = v->list.begin() ;iter != v->list.end();iter++ ){
            if(vertexes[iter->destination_vertex].visited == WHITE){
                vertexes[iter->destination_vertex].visited = GREY;
                bsf_q.push(& vertexes[iter->destination_vertex]);
            }
        }

        v->visited = BLACK;
        std::cout << v->id <<std::endl;
    }
}

int main(){

    cout<<"*****Breadth First Search*****"<<endl;
    Graph();
    bfs();
    cout<<"*****Deap First Search*****"<<endl;
    dfs();
}
