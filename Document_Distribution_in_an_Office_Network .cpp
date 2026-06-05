/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class RedDistribucion {
private:
    int totalOficinas;

    // Guarda las conexiones de cada oficina
    vector<vector<int>> conexiones;

public:
    RedDistribucion(int oficinas) {
        totalOficinas = oficinas;
        conexiones.resize(oficinas);
    }

    // Agrega una ruta entre dos oficinas
    void agregarRuta(int origen, int destino) {
        conexiones[origen].push_back(destino);
        conexiones[destino].push_back(origen);
    }

    // Muestra las conexiones registradas
    void mostrarConexiones() {
        cout << "\nLista de conexiones:\n";

        for (int i = 0; i < totalOficinas; i++) {
            cout << "Oficina " << i << ": ";

            for (int vecino : conexiones[i]) {
                cout << vecino << " ";
            }

            cout << endl;
        }
    }

    // Recorre la red usando BFS
    void simularEntrega(int oficinaInicial = 0) {

        vector<bool> visitada(totalOficinas, false);
        queue<int> cola;

        cout << "\nOrden de entrega de documentos:\n";

        visitada[oficinaInicial] = true;
        cola.push(oficinaInicial);

        while (!cola.empty()) {

            int actual = cola.front();
            cola.pop();

            cout << "Documento entregado en oficina "
                 << actual << endl;

            for (int vecino : conexiones[actual]) {

                if (!visitada[vecino]) {
                    visitada[vecino] = true;
                    cola.push(vecino);
                }
            }
        }
    }
};

int main() {

    int cantidadOficinas;
    int cantidadRutas;

    cout << "Sistema de distribucion de documentos \n";

    cout << "Cantidad de oficinas: ";
    cin >> cantidadOficinas;

    if (cantidadOficinas <= 0) {
        cout << "Dato no valido.\n";
        return 0;
    }

    RedDistribucion red(cantidadOficinas);

    cout << "Cantidad de rutas: ";
    cin >> cantidadRutas;

    for (int i = 0; i < cantidadRutas; i++) {

        int origen, destino;

        cout << "\nRuta " << i + 1 << endl;

        cout << "Origen: ";
        cin >> origen;

        cout << "Destino: ";
        cin >> destino;

        if (origen >= 0 && origen < cantidadOficinas &&
            destino >= 0 && destino < cantidadOficinas) {

            red.agregarRuta(origen, destino);

        } else {

            cout << "Oficina fuera de rango. Intente otra vez.\n";
            i--;
        }
    }

    red.mostrarConexiones();
    red.simularEntrega();

    return 0;
}