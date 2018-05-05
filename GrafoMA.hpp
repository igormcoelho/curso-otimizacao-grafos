#pragma once

#include<vector>

#include "Utils.hpp"
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
    os << "GrafoMA(" << G.nV << "): [" << endl;
    os << "\t";
    for(unsigned i=0; i<G.nV; ++i)
      os << i << ":" << "\t";
    os << endl;
    for(unsigned i=0; i<G.nV; ++i)
      os << i << ": " << G.matrizAdj[i] << endl;
    os << "]";
    return os;
  }

};
