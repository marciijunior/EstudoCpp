#include <iostream>
#include <string>
using namespace std;

void mostrarQuantidade(int quantidade) {
	cout << "Quantidade atual: " << quantidade << endl;
}

void preencherMaterias(int quantidade, string* materias) {
	for (int i = 0; i < quantidade; i++) {
		cout << "Materia [" << i + 1 << "]: ";
		cin >> materias[i];
	}
}

void recriarMaterias(int& quantidade, string*& materias) {
	int novaQuantidade;
	cout << "Digite a nova quantidade de materias: ";
	cin >> novaQuantidade;
	if (novaQuantidade <= 0) {
		cout << "Quantidade invalida!" << endl;
		return;
	}
	string* novasMaterias = new string[novaQuantidade];
	for (int i = 0; i < quantidade && i < novaQuantidade; i++) {
		novasMaterias[i] = materias[i];
	}
	delete[] materias;
	materias = novasMaterias;
	quantidade = novaQuantidade;
}

int main() {
	int quantidade = 3;

	string* materias = new string[quantidade];
	mostrarQuantidade(quantidade);
	preencherMaterias(quantidade, materias);
	recriarMaterias(quantidade, materias);
	mostrarQuantidade(quantidade);
	preencherMaterias(quantidade, materias);
	delete[] materias;
	materias = nullptr;

	return 0;
}