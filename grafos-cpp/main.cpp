#include<iostream>
#include<fstream>

#include "Utils.hpp"
#include "GrafoMA.hpp"

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

    return 0;
}
