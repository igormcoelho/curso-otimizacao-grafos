#pragma once

#include<vector>
#include<functional>

#include "Utils.hpp"
#include "Grafo.h"


// Classe de Grafo Rotulado (em vertices) para Matriz de Adjacencias
template<typename... Args>
class GrafoRotuladoMA : public GrafoMA
{
public:
  int nV; // n
  int nE; // m
  //MatrizAdj mtx;
  vector< vector<void*> > rotulosVertices; // evitando hiper-complicações usando void* :)

  GrafoRotuladoMA(int v) : GrafoMA(v)
  {
    //mtx.inicializa(v);
    const int ntypes = sizeof...(Args);
    vector<void*> vrot(v, nullptr);
    rotulosVertices = vector< vector<void*> >(ntypes, vrot);
  }

  template<int X>
  typename std::tuple_element<X, std::tuple<Args...> >::type getRotuloVertice(int i)
  {
    return rotulosVertices[X][i];
  }

  template<int X>
  void setRotuloVertice(int i, typename std::tuple_element<X, std::tuple<Args...> >::type &value)
  {
    rotulosVertices[X][i] = (void*) new typename std::tuple_element<X, std::tuple<Args...> >::type(value);
  }

};

/*
template<int X, typename... Args>
typename std::tuple_element<X, std::tuple<Args...> >::type getRotuloVerticeG(GrafoRotuladoMA<Args...>& grafo, int i)
{
  return grafo.rotulosVertices[X][i];
}

template<int X, typename... Args>
void setRotuloVerticeG(GrafoRotuladoMA<Args...>& grafo, int i, typename std::tuple_element<X, std::tuple<Args...> >::type &value)
{
  grafo.rotulosVertices[X][i] = value;
}
*/

template<int X, typename... Args>
typename std::tuple_element<X, std::tuple<Args...> >::type rotularVertice(GrafoRotuladoMA<Args...>& grafo, int i)
{
  return grafo.rotulosVertices[X][i];
}

template<int X, typename... Args>
void rotularVertice(GrafoRotuladoMA<Args...>& grafo, int i, typename std::tuple_element<X, std::tuple<Args...> >::type value)
{
  grafo.rotulosVertices[X][i] = (void*) new typename std::tuple_element<X, std::tuple<Args...> >::type(value);
}


// X é o índice do rótulo, Args... sao os tipos dos rótulos.
template<int X, typename... Args>
typename std::tuple_element<X, std::tuple<Args...> >::type rotularVerticesMA(GrafoRotuladoMA<Args...>& grafo)
{
  typename std::tuple_element<X, std::tuple<Args...> >::type x = 10;
  return x;
}

/*
template<int X, typename... Args>
void rotularVerticesMA2(GrafoRotuladoMA<Args...>& grafo)
{
  //auto func1 = getRotuloVerticeG;
  std::function<typename std::tuple_element<X, std::tuple<Args...> >::type(GrafoRotuladoMA<Args...>&, int)> func1 = getRotuloVerticeG;

  //auto func2 = setRotuloVerticeG;
  std::function<void(GrafoRotuladoMA<Args...>&, int, typename std::tuple_element<X, std::tuple<Args...> >::type)> func2 = setRotuloVerticeG;

  //return std::make_tuple(func1, func2);
}
*/
