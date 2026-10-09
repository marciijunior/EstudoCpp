#include <iostream>
using namespace std;

int multiplicar(int x, int y); // Aviso (Prototipo de funcao), sem ele nao funcionaria, a funcao procuraria um multiplicar e nao encontrarial.

int main() {
	int num1, num2;
	
	cout << "Escreva dois numero:" << endl;
	cout << "Primeiro: ";
	cin >> num1;
	cout << "Segundo: ";
	cin >> num2;
	cout << "O resultado foi: " << multiplicar(num1, num2);

}

int multiplicar(int x, int y) {
	return x * y;
}

// Mesmo vindo depois, e possivel usar ja que foi dado um aviso para a funcao.