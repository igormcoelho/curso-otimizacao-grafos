#pragma once

#include<vector>

#include "Utils.hpp"
#include "Grafo.h"


// Núcleo da Matriz de Adjacencias
class MatrizAdj
{
public:
  vector<vector<bool>> matrizAdj;

  // inicializa matriz
  virtual void inicializa(int N, int b = false)
  {
    matrizAdj.clear();
    for(unsigned i=0; i<N;++i)
      matrizAdj.push_back(vector<bool>(N, b));
  }

  // configura aresta
  virtual void setAresta(int u, int v, bool b)
  {
    matrizAdj[u][v] = b;
  }

  // retorna aresta
  virtual bool getAresta(int u, int v)
  {
    return matrizAdj[u][v];
  }

  // retorna vetor de adjacencias (const)
  virtual const vector<bool>& getAdj(int i) const
  {
    return matrizAdj[i];
  }

  // retorna vetor de adjacencias
  virtual vector<bool>& getAdj(int i)
  {
    return matrizAdj[i];
  }

};


// Classe de Grafo para Matriz de Adjacencias
class GrafoMA : public Grafo
{
public:
  int nV; // n
  int nE; // m
  MatrizAdj mtx;

  GrafoMA(int _nV) : nV(_nV)
  {
    nE = 0;
    mtx.inicializa(nV);
  }


  void LerGrafo(istream& in)
  {
    int n,m;
    in >> n >> m;
    nV = n;
    nE = 0;
    //cout << "lendo (n=" << n << ", m=" << m << ")" << endl;
    mtx.inicializa(nV);
    for(unsigned i=0; i<m;++i)
    {
      int u,v;
      in >> u >> v;
      //cout << "lendo (" << u << "," << v << ")" << endl;
      AdicionarAresta(u,v);
      AdicionarAresta(v,u);
    }
  }

  void AdicionarAresta(int u, int v)
  {
    if(!mtx.getAresta(u,v))
    {
      nE++;
      mtx.setAresta(u,v, true);
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
      os << i << ": " << G.mtx.getAdj(i) << endl;
    os << "]";
    return os;
  }

};
