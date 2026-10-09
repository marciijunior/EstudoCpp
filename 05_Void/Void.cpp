#include <iostream>
using namespace std;

void aumentar(int& x) {
	x = x + 1;
}

int main() {
	int numero = 10;

	aumentar(numero);

	cout << numero;
}