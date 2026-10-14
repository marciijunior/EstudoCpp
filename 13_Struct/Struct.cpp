#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int maxProvas = 100;

struct candidato {
    string nome;
    int idade;
    double nota[maxProvas];
    double media;
};

double calculoMedia(candidato p[], int i, int numeroDeProvas);

void cadastrar(candidato p[], int numeroDeCandidatos, int numeroDeProvas) {
    for (int i = 0; i < numeroDeCandidatos; i++) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Escreva o nome do candidato de numero " << i + 1 << ": ";
        getline(cin, p[i].nome);
        cout << "Digite a idade do candidato de numero " << i + 1 << ": ";
        cin >> p[i].idade;
        while (p[i].idade <= 0) {
            cout << "Idade invalida, digite uma idade maior que 0: ";
            cin >> p[i].idade;
        }
        cout << "Digite todas as notas do candidato numero " << i + 1 << ":" << endl;
        for (int x = 0; x < numeroDeProvas; x++) {
            cout << "Prova numero " << x + 1 << ": ";
            cin >> p[i].nota[x];
            while (p[i].nota[x] < 0 || p[i].nota[x] > 10) {  
                cout << "Nota invalida. Digite uma nota entre 0 e 10: ";
                cin >> p[i].nota[x];
            }
        }
        p[i].media = calculoMedia(p, i, numeroDeProvas);
    }
}


void quantidadeCandidatos(int tamanhoMaximo, int& numeroDeCandidatos) {
    cout << "Escreva a quantidade de candidatos existente: ";
    cin >> numeroDeCandidatos;

    while (numeroDeCandidatos <= 0 || numeroDeCandidatos > tamanhoMaximo) {
        cout << "Selecione uma quantidade entre 1 e " << tamanhoMaximo << ": ";
        cin >> numeroDeCandidatos;
    }
}

void numeroDeProvas(int tamanhoMaximoDeProvas, int& quantidadeDeProvas) {
    cout << "Escreva quantas provas tiveram: ";
    cin >> quantidadeDeProvas;

    while (quantidadeDeProvas <= 0 ||
        quantidadeDeProvas > tamanhoMaximoDeProvas) {
        cout << "A quantidade de provas deve estar entre 1 e " << tamanhoMaximoDeProvas << ": ";
        cin >> quantidadeDeProvas;
    }
}


double calculoMedia(candidato p[], int i, int numeroDeProvas) {
    double notaTotal = 0;
    for (int x = 0; x < numeroDeProvas; x++) {
        notaTotal += p[i].nota[x];
    }
    return notaTotal / numeroDeProvas;
}


int main() {
    const int max = 100;
    
    int qtdCandidatos;
    int qtdProvas;
    int maiorMedia = 0;

    candidato p[max];

    quantidadeCandidatos(max, qtdCandidatos);
    numeroDeProvas(maxProvas, qtdProvas);
    cadastrar(p, qtdCandidatos, qtdProvas);

    cout << endl << "RESULTADOS:" << endl;

    for (int i = 0; i < qtdCandidatos; i++) {
        cout << endl;
        cout << "Candidato: " << p[i].nome << endl;
        cout << "Idade: " << p[i].idade << endl;
        cout << "Media: " << p[i].media << endl << endl;
        if (p[maiorMedia].media < p[i].media) {
            maiorMedia = i;
        }
    }

    cout << "A maior media foi do(a): " << endl;
    cout << p[maiorMedia].nome << ", Nota: " << p[maiorMedia].media;
    return 0;
}