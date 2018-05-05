#include<iostream>
#include<fstream>

#include "Utils.hpp"
#include "GrafoMA.hpp"
#include "GrafoLA.hpp"

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



    return 0;
}
