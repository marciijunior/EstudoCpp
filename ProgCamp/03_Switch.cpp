#include <iostream>
using namespace std;

int main() {
	int opcao;
	int num1;
	int num2;
	int resultado;

	cout << "1 - somar" << endl;
	cout << "2 - subtrair" << endl;
	cout << "3 - sair" << endl;
	cout << "Escolha uma opcao: ";
	cin >> opcao;

	while (opcao < 1 || opcao > 3) {
		cout << "Escolha somente 1, 2 ou 3." << endl;
		cout << "1 - somar" << endl;
		cout << "2 - subtrair" << endl;
		cout << "3 - sair" << endl;
		cout << "Escolha uma opcao: ";
		cin >> opcao;
	}

	if (opcao != 3) {
	cout << "Escolha dois numero:" << endl;
	cout << "Digite o numero um: ";
	cin >> num1;
	cout << "Digite o numero dois";
	cin >> num2;
	}

	switch (opcao) {
	case 1: 
		cout << "Voce escolheu somar" << endl;
		resultado = num1 + num2;
		cout << "A soma dos numeros e igual a " << resultado;
		break;
	case 2:
		cout << "Voce escolheu subtrair" << endl;
		resultado = num1 - num2;
		cout << "A subtracao dos numeros e igual a " << resultado;
		break;
	case 3:
		cout << "Voce escolheu sair";
		break;

	default:
		cout << "Opcao invalida";

		return 0;
	}
}