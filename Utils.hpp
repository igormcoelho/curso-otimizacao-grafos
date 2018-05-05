#pragma once

#include<iostream>
#include<vector>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
  //os << "vector("<<v.size()<<"):";
  os << "[\t";
  for(auto i: v)
    os << i << "\t";
  os << "]";
  return os;
}
