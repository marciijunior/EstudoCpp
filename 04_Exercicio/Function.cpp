#include <iostream>
using namespace std;

int resultado, num1, num2;


int multiplicar(int num1, int num2) {
	return num1 * num2;
}

int main() {
	cout << "Digite dois numeros para multiplica-los!" << endl;
	cout << "Numero Um: ";
	cin >> num1;
	cout << "Numero dois: ";
	cin >> num2;
	
	resultado = multiplicar(num1, num2);
	cout << "Resultado da multiplicacao de " << num1 << " e " << num2 << ": " << resultado;

}