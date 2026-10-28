#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct VarProdutos {
	string nome;
	int quantidade;
};

// ofstream - Escreve um arquivo.
// ifstream - Ler um arquivo.
// fstream - Lê e escreve.

int main() {

	VarProdutos p;
	cout << "Nome: ";
	getline(cin, p.nome);

	cout << "Quantidade: ";
	cin >> p.quantidade;

	ifstream arquivo;
	string nome;
	string quantidadeTexto;
	int quantidade;

	arquivo.open("produtos.txt");

	getline(arquivo, nome, ','); // Esse getline(), lê até a vírgula, e deixa a leitura estacionada até que o próximo getline chegue.
	getline(arquivo, quantidadeTexto); // Por isso, ao chegar aqui, ele pega somente o que tem depois da vírgula.

	quantidade = stoi(quantidadeTexto);

	cout << "Nome: " << nome << endl;
	cout << "Quantidade: " << quantidade << endl;

	arquivo.close();

	return 0;
}