//
//  main.cpp
//  grafo
//
//  Created by Luis Alberto Sanchez Moreno on 06/08/16.
//  Copyright © 2016 Luis Alberto Sanchez Moreno. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Vertice;

class Arista{
public:
    Arista(Vertice *org, Vertice *dest, int dist){
        origen = org;
        destino = dest;
        distancia = dist;
    }
    Vertice* getOrigen() {return origen;}
    Vertice* getDestino() {return destino;}
    int getDistancia() {return distancia;}
private:
    Vertice* origen;
    Vertice* destino;
    int distancia;
};


class Vertice{
public:
    Vertice(string id){
        nombre = id;
    }

    void addArista(Vertice *v, int dist){
        Arista newArista(this, v, dist);
        aristas.push_back(newArista);
    }

    void printAristas(){
        cout << nombre << ":" << endl;
        for (int i = 0; i < aristas.size(); i++)
        {
        Arista e = aristas[i];
        cout << e.getDestino()->getNombre() <<
            " distancia " << e.getDistancia() << endl;
        }
        cout << endl;
    }

    string getNombre() {return nombre;}
    vector<Arista> getAristas() {return aristas;}

private:
    string nombre;
    vector<Arista> aristas;
};


class Grafo{
public:
    Grafo() {}

    void insertar(Vertice *v){
        vertices.push_back(v);
    }

    void printGrafo(){
        for (int i = 0; i < vertices.size(); i++)
            vertices[i]->printAristas();
    }

private:
    vector<Vertice*> vertices;
};

int main(){
Grafo g;

Vertice v1 = Vertice("Arequipa");
Vertice v2 = Vertice("Lima");
Vertice v3 = Vertice("Cusco");
Vertice v4 = Vertice("Libertad");

Vertice *vp1 = &v1;
Vertice *vp2 = &v2;
Vertice *vp3 = &v3;
Vertice *vp4 = &v4;

v1.addArista(vp2, 100);
v2.addArista(vp3, 80);
v3.addArista(vp4, 30);
v4.addArista(vp1, 10);

g.insertar(vp1);
g.insertar(vp2);
g.insertar(vp3);
g.insertar(vp4);

g.printGrafo();

//system("PAUSE");

//return 1;
}