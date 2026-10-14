#include <iostream>
#include <string>
using namespace std;

const int maxFuncionarios = 100;
const int maxProvas = 10;

struct funcionario {
	string nomeCompleto;
	int idade;
	double notas[maxProvas];
	double media;
};

void escolherTotalEquipe(int& totalFuncionarios) {
	cout << "Escolha a quantidade maxima de integrantes na sua equipe: " << endl;
	cin >> totalFuncionarios;
	while (totalFuncionarios <= 0 || totalFuncionarios > maxFuncionarios) {
		cout << "Escolha no minimo 1 ou no maximo 100 funcionarios. Escolha novamente a quantidade maxima de integrante na sua equipe: " << endl;
		cin >> totalFuncionarios;
	}
}

void lerNome(funcionario pessoa[], int totalFuncionarios) {
	for (int i = 0; i < totalFuncionarios; i++) {
		cout << "Informe o nome do candidato: " << endl;
		cin.ignore();
		getline(cin, pessoa[i].nomeCompleto);
	}
}

void quantasProvas(int& totalProvas) {
	do {
		cout << "Informe a quantidade de provas(1...10): ";
		cin >> totalProvas;
		if (totalProvas <= 0 || totalProvas > maxProvas) {
			cout << "Quantidade invalida de provas! ";
		}
	} while (totalProvas <= 0 || totalProvas > maxProvas);
}

int historico() {

}

int main() {
	funcionario pessoa[maxFuncionarios];
	int totalFuncionarios = 0;
	int totalProvas = 0;
	escolherTotalEquipe(totalFuncionarios);
	lerNome(pessoa, totalFuncionarios);
	quantasProvas(totalProvas);

}