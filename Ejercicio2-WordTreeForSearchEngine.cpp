#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Nodo {
public:
    string palabra;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(string p) {
        palabra = p;
        izquierda = NULL;
        derecha = NULL;
    }
};

class ArbolABB {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, string palabra) {
        if (nodo == NULL)
            return new Nodo(palabra);

        if (palabra < nodo->palabra)
            nodo->izquierda = insertar(nodo->izquierda, palabra);
        else if (palabra > nodo->palabra)
            nodo->derecha = insertar(nodo->derecha, palabra);

        return nodo;
    }

    void inOrden(Nodo* nodo) {
        if (nodo != NULL) {
            inOrden(nodo->izquierda);
            cout << nodo->palabra << endl;
            inOrden(nodo->derecha);
        }
    }

    bool buscar(Nodo* nodo, string palabra) {
        if (nodo == NULL)
            return false;

        if (nodo->palabra == palabra)
            return true;

        if (palabra < nodo->palabra)
            return buscar(nodo->izquierda, palabra);

        return buscar(nodo->derecha, palabra);
    }

public:
    ArbolABB() {
        raiz = NULL;
    }

    void insertarPalabra(string palabra) {
        raiz = insertar(raiz, palabra);
    }

    void mostrarOrdenadas() {
        cout << "\nPalabras en orden alfabetico:\n";
        inOrden(raiz);
    }

    void buscarPalabra(string palabra) {
        if (buscar(raiz, palabra))
            cout << "\nLa palabra existe.\n";
        else
            cout << "\nLa palabra no existe.\n";
    }

    void mostrarNiveles() {
        if (raiz == NULL)
            return;

        queue<Nodo*> cola;
        cola.push(raiz);

        int nivel = 0;

        cout << "\nCantidad de palabras por nivel:\n";

        while (!cola.empty()) {
            int cantidad = cola.size();

            cout << "Nivel " << nivel << ": "
                 << cantidad << " palabra(s)" << endl;

            for (int i = 0; i < cantidad; i++) {
                Nodo* actual = cola.front();
                cola.pop();

                if (actual->izquierda)
                    cola.push(actual->izquierda);

                if (actual->derecha)
                    cola.push(actual->derecha);
            }

            nivel++;
        }
    }
};

int main() {
    ArbolABB arbol;

    arbol.insertarPalabra("computadora");
    arbol.insertarPalabra("algoritmo");
    arbol.insertarPalabra("programacion");
    arbol.insertarPalabra("datos");
    arbol.insertarPalabra("estructura");

    arbol.mostrarOrdenadas();
    arbol.buscarPalabra("datos");
    arbol.mostrarNiveles();

    return 0;
}