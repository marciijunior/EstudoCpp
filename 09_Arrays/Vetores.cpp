#include <iostream>
using namespace std;

int buscar(int vet[], int tamanho, int procurado) {
    for (int i = 0; i < tamanho; i++) {
        if (vet[i] == procurado) {
            return i;
        }
    }

    return -1;
}

int main() {
    int numeros[5] = { 4, 8, 15, 16, 23 };

    cout << buscar(numeros, 5, 16);

    return 0;
}