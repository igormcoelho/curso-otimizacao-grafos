#pragma once

#include<vector>

#include "Utils.hpp"
#include "Grafo.h"


// Classe auxiliar para construir lista interna do GrafoLA
class NoAresta
{
public:
  int Viz; // vizinho
  NoAresta* Prox;

  NoAresta()
  {
      Viz = -1;
      Prox = nullptr;
  }
};


// Classe de Grafo para Lista de Adjacencias
class GrafoLA : public Grafo
{
public:
  int n;
  int m;
  vector<NoAresta*> L;

  GrafoLA(int _nV) : n(_nV)
  {
    m = 0;
    L = vector<NoAresta*>(n, nullptr);
  }


  void LerGrafo(istream& in)
  {
    in >> n >> m;
    //cout << "lendo (n=" << n << ", m=" << m << ")" << endl;
    L = vector<NoAresta*>(n, nullptr); // memory leak, TODO: fix
    for(unsigned i=0; i<m;++i)
    {
      int u,v;
      in >> u >> v;
      //cout << "lendo (" << u << "," << v << ")" << endl;
      AdicionarAresta(u,v);
      AdicionarAresta(v,u);
    }
  }

  void Insere(NoAresta* &L, int viz)
  {
    NoAresta* novo = new NoAresta;
    novo->Viz = viz;
    novo->Prox = L;
    L = novo;
  }

  void AdicionarAresta(int u, int v)
  {
    Insere(L[u],v);
  }

  friend ostream& operator<<(ostream& os, const GrafoLA& G)
  {
    os << "GrafoLA(" << G.n << "): [" << endl;
    for(unsigned i=0; i<G.n; ++i)
    {
      os << i << ": [\t";
      for(NoAresta* no=G.L[i]; no != nullptr; no = no->Prox)
         os << no->Viz << "\t";
      os << "]" << endl;
    }
    os << "]";
    return os;
  }

};
