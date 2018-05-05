#pragma once

#include<iostream>
#include<string>

#include "Grafo.h"

using namespace std;


template<class X>
class RotuloVertice
{
public:
    virtual X getRotulo(int i) = 0;
    virtual void setRotulo(int i, X r) = 0;
};

// Interface para métodos da classe Grafo Rotulado
template<typename... T> // usando multiplos tipos de rotulos (Variadic Templates)
class GrafoRotulado : public Grafo
{
public:

  virtual void RotularVertices(string rotulo, int rotid) = 0;
  virtual void RotularArestas(string rotulo, int rotid) = 0;

// typename std::tuple_element<0, std::tuple<Args...> >::type
//  virtual tuple<T...> getRotuloVertice(int rotid, int i) = 0;

  //virtual void LerGrafo(istream& in) = 0;
  //virtual void AdicionarAresta(int u, int v) = 0;
  //virtual void LerGrafo(istream& in) = 0;
};
