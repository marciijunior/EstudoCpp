#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
	string nome;
	int idade;
	double altura;
};

struct Carro {
	string modelo;
	int portas;
	string cor;
};

int main() {
	Pessoa pessoa1;

	pessoa1.nome = "Roberta";
	pessoa1.idade = 54;
	pessoa1.altura = 1.78;

	Pessoa* ptr = &pessoa1;

	cout << pessoa1.altura << endl;
	cout << (*ptr).altura << endl;

	(*ptr).altura = 1.50;
	ptr->altura = 1.50;

	cout << pessoa1.altura << endl;
	cout << ptr->altura << endl;

	// Percorrer um vetor normal, mas acessando cada struct com um ponteiro.

	Carro empresa[3];
	Carro* p = empresa; // Carro* p = empresa[0];

	cout << endl << endl << "PERCORRENDO UM STRUCT COM PONTEIROS: " << endl;
	for (int i = 0; i < 3; i++) {
		cout << endl << "____________________________________________________________________________________________" << endl;
		cout << "Escreva o modelo do veiculo [" << i + 1 << "/3]: " << endl;
		cin >> (*(p + i)).modelo;
		cout << "Escreva o total de portas do veiculo [" << i + 1 << "/3]: " << endl;
		cin >> (*(p + i)).portas;
		cout << "Escreva a cor do veiculo [" << i + 1 << "/3]: " << endl;
		cin >> (*(p + i)).cor;
	}
	
	for (int i = 0; i < 3; i++) {
		cout << "Escreva o modelo do veiculo: " << (*(p + i)).modelo << endl;
		cout << "Escreva o total de portas do veiculo: " << (*(p + i)).portas << endl;
		cout << "Escreva o modelo do veiculo: " << (*(p + i)).cor << endl;
	}

	return 0;
}