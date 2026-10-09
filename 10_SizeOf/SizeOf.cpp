#include <iostream>
using namespace std;

int vet[20], maior, posicao;

int tamanho = sizeof(vet) / sizeof(vet[0]);

int procurarMaior(int tamanho, int vet[]);
void escreverVetor(int tamanho, int vet[]);

int procurarMaior(int x, int y[]) {
    maior = y[0];
    posicao = 0;
    for (int i = 1; i < x; i++) {
        if (maior < y[i]) {
            maior = y[i];
            posicao = i;
        }
    }
    cout << "O maior numero e " << maior << " e sua posicao e " << posicao << ".";
    return maior;
}

int main() {
    escreverVetor(tamanho, vet);
    procurarMaior(tamanho, vet);
    return 0;
}

void escreverVetor(int tamanho, int vet[]) {
    for (int i = 0; i < tamanho; i++) {
        cout << "Escreva o numero para a posicao " << i << " do vetor: ";
        cin >> vet[i];
        while (vet[i] < 0) {
            cout << "Escreva um numero positivo!" << endl;
            cout << "Escreva o numero para a posicao " << i << " do vetor: ";
            cin >> vet[i];
        }
    }
} 