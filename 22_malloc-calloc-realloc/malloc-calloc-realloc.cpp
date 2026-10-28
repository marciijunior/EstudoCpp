#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int* numeros;
	int* temporario;
	int quantidade = 3;

	// =====================================================
	// MALLOC
	// Reserva memoria, mas nao inicializa os valores.
	// =====================================================

	numeros = (int*)malloc(quantidade * sizeof(int));

	if (numeros == nullptr) {
		cout << "Erro ao alocar memoria." << endl;
		return 1;
	}

	cout << "=== MALLOC ===" << endl;

	for (int i = 0; i < quantidade; i++) {
		numeros[i] = (i + 1) * 10;
	}

	for (int i = 0; i < quantidade; i++) {
		cout << "numeros[" << i << "] = " << numeros[i] << endl;
	}

	free(numeros);
	numeros = nullptr;

	// =====================================================
	// CALLOC
	// Reserva memoria e inicializa os bytes com zero.
	// =====================================================

	numeros = (int*)calloc(quantidade, sizeof(int));

	if (numeros == nullptr) {
		cout << "Erro ao alocar memoria." << endl;
		return 1;
	}

	cout << "\n=== CALLOC ===" << endl;

	for (int i = 0; i < quantidade; i++) {
		cout << "numeros[" << i << "] = " << numeros[i] << endl;
	}

	// Agora colocamos valores
	numeros[0] = 10;
	numeros[1] = 20;
	numeros[2] = 30;

	// =====================================================
	// REALLOC
	// Altera o tamanho do bloco ja existente.
	// =====================================================

	cout << "\n=== REALLOC ===" << endl;

	int novaQuantidade = 5;

	temporario = (int*)realloc(
		numeros,
		novaQuantidade * sizeof(int)
	);

	if (temporario != nullptr) {
		numeros = temporario;
		quantidade = novaQuantidade;
	}
	else {
		cout << "Erro ao redimensionar memoria." << endl;

		free(numeros);
		numeros = nullptr;

		return 1;
	}

	// Os antigos continuam:
	// numeros[0] = 10
	// numeros[1] = 20
	// numeros[2] = 30

	// Preenchemos os novos espacos
	numeros[3] = 40;
	numeros[4] = 50;

	for (int i = 0; i < quantidade; i++) {
		cout << "numeros[" << i << "] = " << numeros[i] << endl;
	}

	// =====================================================
	// FREE
	// Libera a memoria reservada.
	// =====================================================

	free(numeros);
	numeros = nullptr;

	return 0;
}