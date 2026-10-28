#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	srand(time(0));
	
	int quantidade;
	quantidade = rand() % 100 + 1;

	int* num;
	num = (int*)malloc(quantidade * sizeof(int));

	for (int i = 0; i < quantidade; i++) {
		num[i] = rand() % quantidade; 
		cout << "[" << num[i] << "]" << endl;
	}

	int menor = 0;
	int maior = 0;
	int x = 0;

	for (int i = 0; i < quantidade; i++) {
		if (num[maior] < num[i]) {
			maior = i;
		}
	}
	for (int i = 0; i < quantidade; i++) {
		if (num[menor] > num[i]) {
			menor = i;
		}
	}

	cout << "O maior número é: " << num[maior] << " | Sua posição: " << maior + 1 << endl;
	cout << "O menor número é: " << num[menor] << " | Sua posição: " << menor + 1 << endl;

	free(num);
	num = nullptr;
	
	return 0;
}