#include <iostream>
#include <string>
using namespace std;

int main() {
    int numero = 8;
    int* p = &numero;
    int* x = nullptr;  // Com isso, nao e possivel depurar e executar
    int vet[3] = { 10, 20, 30 };

    *p = 20;

    cout << "Valor de numero: " << numero << endl;
    cout << "Valor acessado pelo ponteiro: " << *p << endl;
    cout << "Endereco inicial do vetor: " << vet << endl;

    cout << endl << "TAMANHO DOS TIPOS:" << endl;

    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "char: " << sizeof(char) << " byte" << endl;
    cout << "bool: " << sizeof(bool) << " byte(s)" << endl;

    cout << endl << "TAMANHO DAS VARIAVEIS: " << endl;

    cout << "numero: " << sizeof(numero) << " bytes" << endl;
    cout << "vet: " << sizeof(vet) << " bytes" << endl;

    int tamanhoVetor = sizeof(vet) / sizeof(vet[0]);

    cout << "Quantidade de elementos do vetor: "
        << tamanhoVetor << endl;

    int* ponteiroVet = vet;

    cout << endl << "VALORES PELO PONTEIRO: " << endl;

    cout << *ponteiroVet << endl;
    cout << *(ponteiroVet + 1) << endl;
    cout << *(ponteiroVet + 2) << endl;

    return 0;
}