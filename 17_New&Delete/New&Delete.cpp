#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

int main() {

    // 1. NEW E DELETE COM UMA VARIAVEL

    int* numero = new int;

    *numero = 50;

    cout << "Valor: " << *numero << endl;

    delete numero;
    numero = nullptr;


    cout << endl;


    // 2. VETOR DINAMICO

    int tamanho = 3;

    int* vet = new int[tamanho];

    (*(vet)) = 10;
    (*(vet + 1)) = 20;
    (*(vet + 2)) = 30;

    cout << "Vetor original: ";

    for (int i = 0; i < tamanho; i++) {
        cout << (*(vet + i)) << " ";
    }

    cout << endl;


    // 3. REDIMENSIONAMENTO MANUAL

    int novoTamanho = 5;

    int* novoVet = new int[novoTamanho];

    for (int i = 0; i < tamanho; i++) {
        novoVet[i] = vet[i];
    }

    delete[] vet;

    vet = novoVet;

    tamanho = novoTamanho;

    vet[3] = 40;
    vet[4] = 50;

    cout << "Vetor aumentado: ";

    for (int i = 0; i < tamanho; i++) {
        cout << vet[i] << " ";
    }

    cout << endl;

    delete[] vet;
    vet = nullptr;


    cout << endl;


    // 4. NEW COM STRUCT

    Pessoa* pessoa = new Pessoa;

    pessoa->nome = "Carlos";
    pessoa->idade = 25;

    cout << "Pessoa: " << pessoa->nome << endl;
    cout << "Idade: " << pessoa->idade << endl;

    delete pessoa;
    pessoa = nullptr;


    cout << endl;


    // 5. VETOR DINAMICO DE STRUCT

    int quantidade = 2;

    Pessoa* pessoas = new Pessoa[quantidade];

    pessoas[0].nome = "Ana";
    pessoas[0].idade = 20;

    pessoas[1].nome = "Bruno";
    pessoas[1].idade = 30;

    for (int i = 0; i < quantidade; i++) {
        cout << "Nome: " << pessoas[i].nome << endl;
        cout << "Idade: " << pessoas[i].idade << endl;
    }

    delete[] pessoas;
    pessoas = nullptr;


    // 6. DANGLING POINTER

    int* ponteiroDangling = new int;

    *ponteiroDangling = 50;

    delete ponteiroDangling;

    // Neste momento ele possui um endereco antigo
    // que nao deve mais ser utilizado.

    ponteiroDangling = nullptr;


    // 7. MEMORY LEAK

    int* ponteiroLeak = new int;

    *ponteiroLeak = 100;

    ponteiroLeak = nullptr;

    // A memoria que possuia o valor 100
    // continua reservada, mas perdemos seu endereco.

    return 0;
}