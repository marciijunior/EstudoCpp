#include <iostream>
#include <string>
using namespace std;

void trocar(int* x, int* y) {
	int reserva = *y;
	*y = *x;
	*x = reserva;
}

int main() {
	int a = 10;
	int b = 20;

	cout << "a: " << a;
	cout << "b: " << b;

	trocar(&a, &b);

	cout << "a: " << a;
	cout << "b: " << b;
}