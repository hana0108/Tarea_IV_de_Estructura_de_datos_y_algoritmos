#include <iostream>
using namespace std;

// Nodo del árbol
class Nodo {
public:
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = NULL;
        derecha = NULL;
    }
};

// Clase Árbol Binario de Búsqueda
class ABB {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, int valor) {
        if (nodo == NULL)
            return new Nodo(valor);

        if (valor < nodo->dato)
            nodo->izquierda = insertar(nodo->izquierda, valor);
        else
            nodo->derecha = insertar(nodo->derecha, valor);

        return nodo;
    }

    void inOrden(Nodo* nodo) {
        if (nodo != NULL) {
            inOrden(nodo->izquierda);
            cout << nodo->dato << " ";
            inOrden(nodo->derecha);
        }
    }

    int contarHojas(Nodo* nodo) {
        if (nodo == NULL)
            return 0;

        if (nodo->izquierda == NULL && nodo->derecha == NULL)
            return 1;

        return contarHojas(nodo->izquierda) +
               contarHojas(nodo->derecha);
    }

    int altura(Nodo* nodo) {
        if (nodo == NULL)
            return 0;

        int altIzq = altura(nodo->izquierda);
        int altDer = altura(nodo->derecha);

        if (altIzq > altDer)
            return altIzq + 1;
        else
            return altDer + 1;
    }

public:
    ABB() {
        raiz = NULL;
    }

    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }

    void mostrarInOrden() {
        inOrden(raiz);
    }

    int obtenerHojas() {
        return contarHojas(raiz);
    }

    int obtenerAltura() {
        return altura(raiz);
    }
};

int main() {
    ABB arbol;

    int primos[15] = {
        2, 3, 5, 7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47
    };

    for (int i = 0; i < 15; i++) {
        arbol.insertar(primos[i]);
    }

    cout << "Primos en recorrido InOrder: ";
    arbol.mostrarInOrden();

    cout << "\n\nCantidad de nodos hoja: "
         << arbol.obtenerHojas();

    cout << "\nAltura del arbol: "
         << arbol.obtenerAltura();

    return 0;
}