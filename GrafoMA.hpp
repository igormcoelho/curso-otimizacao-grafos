#pragma once

#include<vector>

#include "Grafo.h"

// Classe de Grafo para Matriz de Adjacencias
class GrafoMA
{
public:
  int nV;
  vector<vector<bool>> matrizAdj;
  GrafoMA(int _nV) : nV(_nV)
  {
    for(unsigned i=0; i<nV;++i)
      matrizAdj.push_back(vector<bool>(nV, false));
  }


  friend ostream& operator<<(ostream& os, const GrafoMA& G)
  {
    os << "GrafoMA(nV)";
    return os;
  }

};
