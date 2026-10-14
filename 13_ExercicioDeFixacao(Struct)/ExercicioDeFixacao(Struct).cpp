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
	cout << endl << endl << "NUMERO TOTAL DE INTEGRANTES NA EQUIPE: " << endl;
	cout << "Escolha a quantidade maxima de integrantes na sua equipe: " << endl;
	cin >> totalFuncionarios;
	while (totalFuncionarios <= 0 || totalFuncionarios > maxFuncionarios) {
		cout << "Escolha no minimo 1 ou no maximo 100 funcionarios. Escolha novamente a quantidade maxima de integrante na sua equipe: " << endl;
		cin >> totalFuncionarios;
	}
}

void lerNome(int totalFuncionarios, funcionario pessoa[]) {
	cout << endl << endl << "LEITURA DE NOMES: " << endl;
	for (int i = 0; i < totalFuncionarios; i++) {
		cout << "Informe sobre o funcionario. " << endl;
		cout << "Nome: ";
		cin.ignore();
		getline(cin, pessoa[i].nomeCompleto);
		cout << "Idade: ";
		cin >> pessoa[i].idade;
		while (pessoa[i].idade < 1) {
			cout << "Informe novamente sua idade: " << endl;
			cin >> pessoa[i].idade;
		}
	}
}

void quantasProvas(int& totalProvas) {
	cout << endl << endl << "QUANTIDADE DE PROVAS REALIZADAS: " << endl;
	do {
		cout << "Informe a quantidade de provas(1...10): " << endl;
		cin >> totalProvas;
		if (totalProvas <= 0 || totalProvas > maxProvas) {
			cout << "Quantidade invalida de provas! " << endl;
		}
	} while (totalProvas <= 0 || totalProvas > maxProvas);
}

void atribuirNotas(int totalFuncionarios, int totalProvas, funcionario pessoa[]) {
	cout << endl << endl << "ATRIBUIR NOTAS: " << endl;
	cout << "As notas devem ser de 0 a 10." << endl;
	for (int i = 0; i < totalFuncionarios; i++) {
		for (int j = 0; j < totalProvas; j++) {
			cout << "Informe a nota[" << j << "/" << totalProvas << "] de " << pessoa[i].nomeCompleto << ": " << endl;
			cin >> pessoa[i].notas[j];
			while (pessoa[i].notas[j] < 0 || pessoa[i].notas[j] > 10) {
				cout << "Informe novamente, deve ser de 0 a 10!" << endl;
				cin >> pessoa[i].notas[j];
			}
		}
	}
}

void calcularMedia(int totalFuncionarios, int totalProvas, funcionario pessoa[]) {
	for (int i = 0; i < totalFuncionarios; i++) {
		double somaNotas = 0;
		for (int j = 0; j < totalProvas; j++) {
			somaNotas += pessoa[i].notas[j];
		}
		pessoa[i].media = somaNotas/totalProvas;
	}
}

void exibirInformacoes(int totalFuncionarios, int totalProvas, funcionario pessoa[]) {
	cout << endl << endl << "EXIBIR INFORMACOES: " << endl;
	for (int i = 0; i < totalFuncionarios; i++) {
		cout << "Funcionario numero " << i << "." << endl;
		cout << "Nome: " << pessoa[i].nomeCompleto << endl;
		cout << "Idade: " << pessoa[i].idade << endl; 
		cout << "Notas das provas: " << endl;
		for (int j = 0; j < totalProvas; j++) {
			cout << "Nota[" << j << "]: " << pessoa[i].notas[j] << endl;
		}
		cout << "Media: " << pessoa[i].media << endl << endl;
	}
}

void procurarMaiorMedia(int totalFuncionarios, funcionario pessoa[], int& maiorMedia) {
	for (int i = 1; i < totalFuncionarios; i++) {
		if (pessoa[maiorMedia].media < pessoa[i].media) {
			maiorMedia = i;
		}
	}
}

void mostrarMaiorMedia(funcionario pessoa[], int maiorMedia) {
	cout << endl << endl << "MOSTRAR MAIOR MEDIA: " << endl;
	cout << "O funcionario com a maior media foi: " << endl;
	cout << pessoa[maiorMedia].nomeCompleto << endl;
	cout << pessoa[maiorMedia].media << endl;
}

void maiorSete(int totalFuncionarios, funcionario pessoa[]) {
	int totalMaiorSete = 0;
	cout << endl << endl << "NOTAS MAIORES OU IGUAIS A 7: " << endl;
	cout << "Os seguintes funcionarios tem media maior ou igual a sete: ";
	for (int i = 0; i < totalFuncionarios; i++) {
		if (pessoa[i].media >= 7) {
			cout << pessoa[i].nomeCompleto;
			totalMaiorSete++;
		}
	}
	cout << "Quantidade de aprovados: " << totalMaiorSete;
}

void pesquisarNome(int totalFuncionarios, funcionario pessoa[]) {
	cout << endl << endl << "PESQUISAR O NOME COMPLETO: " << endl;
	string nomePessoa;
	int encontrou = 0;
	cout << "Digite um nome completo para pesquisar: ";
	cin.ignore();
	getline(cin, nomePessoa);
	for (int i = 0; i < totalFuncionarios; i++) {
		if (nomePessoa == pessoa[i].nomeCompleto) {
			cout << pessoa[i].nomeCompleto << endl;
			cout << pessoa[i].idade << endl;
			cout << pessoa[i].media << endl;
			encontrou++;
		}
	}
	if (encontrou == 0) {
		cout << "Funcionario nao encontrado.";
	}
}

int main() {
	funcionario pessoa[maxFuncionarios];
	int totalFuncionarios;
	int totalProvas;
	int maiorMedia = 0;
	escolherTotalEquipe(totalFuncionarios);
	lerNome(totalFuncionarios, pessoa);
	quantasProvas(totalProvas);
	atribuirNotas(totalFuncionarios, totalProvas, pessoa);
	calcularMedia(totalFuncionarios, totalProvas, pessoa);
	exibirInformacoes(totalFuncionarios, totalProvas, pessoa);
	procurarMaiorMedia(totalFuncionarios, pessoa, maiorMedia);
	mostrarMaiorMedia(pessoa, maiorMedia);
	maiorSete(totalFuncionarios, pessoa);
	pesquisarNome(totalFuncionarios, pessoa);
}