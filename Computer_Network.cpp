/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Red {
private:
    int totalComputadoras;
    std::vector<std::vector<int>> conexiones;

public:
    Red(int cantidad) {
        totalComputadoras = cantidad;
        conexiones.resize(cantidad);
    }

    // Conecta dos computadoras de la red
    void conectarComputadoras(int a, int b) {
        conexiones[a].push_back(b);
        conexiones[b].push_back(a);
    }

    // Busca la ruta de propagación y los saltos mínimos usando BFS
    void simularPropagacion(int origen, int destino) {

        if (origen < 0 || origen >= totalComputadoras ||
            destino < 0 || destino >= totalComputadoras) {
            std::cout << "Computadora no valida.\n";
            return;
        }

        std::vector<bool> visitado(totalComputadoras, false);
        std::vector<int> distancia(totalComputadoras, -1);
        std::vector<int> anterior(totalComputadoras, -1);

        std::queue<int> cola;

        visitado[origen] = true;
        distancia[origen] = 0;
        cola.push(origen);

        while (!cola.empty()) {
            int actual = cola.front();
            cola.pop();

            for (int vecino : conexiones[actual]) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    distancia[vecino] = distancia[actual] + 1;
                    anterior[vecino] = actual;
                    cola.push(vecino);
                }
            }
        }

        if (!visitado[destino]) {
            std::cout << "No existe una ruta entre la computadora "
                      << origen << " y la computadora "
                      << destino << ".\n";
            return;
        }

        std::vector<int> ruta;
        int nodo = destino;

        while (nodo != -1) {
            ruta.push_back(nodo);
            nodo = anterior[nodo];
        }

        std::reverse(ruta.begin(), ruta.end());

        std::cout << "\nRuta de propagacion: ";

        for (size_t i = 0; i < ruta.size(); i++) {
            std::cout << ruta[i];

            if (i < ruta.size() - 1) {
                std::cout << " -> ";
            }
        }

        std::cout << "\nNumero minimo de saltos: "
                  << distancia[destino] << "\n";
    }
};

int main() {

    // Red de 7 computadoras (la 6 queda aislada para hacer pruebas)
    Red red(7);

    red.conectarComputadoras(0, 1);
    red.conectarComputadoras(0, 2);
    red.conectarComputadoras(1, 3);
    red.conectarComputadoras(2, 3);
    red.conectarComputadoras(3, 4);
    red.conectarComputadoras(4, 5);

    int origen, destino;

    std::cout << "Simulacion de actualizacion en la red\n";
    std::cout << "Computadoras disponibles: 0 a 6\n\n";

    std::cout << "Ingrese la computadora de origen: ";
    std::cin >> origen;

    std::cout << "Ingrese la computadora de destino: ";
    std::cin >> destino;

    red.simularPropagacion(origen, destino);

    return 0;
}