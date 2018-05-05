#include<iostream>
#include<fstream>
#include<tuple>

#include "Utils.hpp"
#include "GrafoMA.hpp"
#include "GrafoLA.hpp"

#include "GrafoRotulado.h"
#include "GrafoRotuladoMA.hpp"

using namespace std;


int main()
{
    // testes com grafos
    GrafoMA G(5);
    cout << G << endl;

    ifstream fG;
    fG.open ("grafo1.txt");
    G.LerGrafo(fG);
    fG.close();

    cout << G << endl;

    // =============================

    GrafoLA G2(5);
    cout << G2 << endl;
    fG.open ("grafo1.txt");
    G2.LerGrafo(fG);
    fG.close();
    cout << G2 << endl;

    // =============================

    GrafoRotuladoMA<bool, double> GR(4);

    bool b = rotularVerticesMA<0>(GR);
    cout << b << endl;

    rotularVertice<0>(GR, 4, true);
    rotularVertice<1>(GR, 2, 7.2);
    // rotulacao ainda em desenvolvimento



    return 0;
}
