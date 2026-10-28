#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	srand(time(0));

	int vet[10];
	int maior = 0;
	int alvo = 0;

	for (int i = 0; i < 10; i++) {
		vet[i] = rand() % 100 + 1;
		cout << "[" << vet[i] << "]" << endl;
	}

	for (int i = 0; i < 10; i++) {
		if (vet[maior] < vet[i] ) {
			alvo = maior;	
			maior = i;
		}
	}

	cout << "O maior número é: " << vet[maior] << endl;
	cout << "O segundo maior número é: " << vet[alvo] << endl;

	return 0;
}