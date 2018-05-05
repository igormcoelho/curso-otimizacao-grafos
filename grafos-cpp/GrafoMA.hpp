#pragma once

#include<vector>

#include "Utils.hpp"
#include "Grafo.h"


// Classe de Grafo para Matriz de Adjacencias
class GrafoMA
{
public:
  int nV; // n
  int nE; // m
  vector<vector<bool>> matrizAdj;
  GrafoMA(int _nV) : nV(_nV)
  {
    nE = 0;
    for(unsigned i=0; i<nV;++i)
      matrizAdj.push_back(vector<bool>(nV, false));
  }


  void LerGrafo(istream& in)
  {
    int n,m;
    in >> n >> m;
    nV = n;
    nE = m;
    //cout << "lendo (n=" << n << ", m=" << m << ")" << endl;
    matrizAdj.clear();
    for(unsigned i=0; i<nV;++i)
      matrizAdj.push_back(vector<bool>(nV, false));
    for(unsigned i=0; i<m;++i)
    {
      int u,v;
      in >> u >> v;
      //cout << "lendo (" << u << "," << v << ")" << endl;
      matrizAdj[u][v] = matrizAdj[v][u] = true;
    }
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
