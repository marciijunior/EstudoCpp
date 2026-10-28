#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int quantidade;

	cout << "Escreva a quantidade de números que deseja armazenar: ";
	cin >> quantidade;

	int* p; // "int" é o tipo primitivo, "*" significa: Ponteiro para. No caso, refere-se a um número inteiro. Lendo essa linha ficaria: Ponteiro para o tipo inteiro chamado p.
	p = (int*)malloc(quantidade*sizeof(int));

	for (int i = 0; i < quantidade; i++) {
		cout << "Número " << i << ": ";
		cin >> p[i];
	}

	for (int i = 0; i < quantidade; i++) {
		cout << p[i] << endl;
	}

	free(p);
	p = nullptr;

	return 0;
}