#pragma once

#include<iostream>

using namespace std;

// Interface para métodos da classe Grafo
class Grafo
{
public:

  virtual void AdicionarAresta(int u, int v) = 0;

};
