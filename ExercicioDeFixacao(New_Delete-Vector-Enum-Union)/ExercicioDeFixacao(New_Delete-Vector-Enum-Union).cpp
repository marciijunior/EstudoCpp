#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum medida {
	unidade,
	peso
};

union valor {
	int inteiro;
	double decimal;
};

struct tipoProduto {
	string nome;
	medida tipoMedida;
	valor quantidade;
};

void PedirNome(vector<tipoProduto>& VetProdutos, int& totalProdutos) {
	tipoProduto produto;
	int opcaoMedida;

	cout << "Quantos produtos deseja adicionar? ";
	cin >> totalProdutos;

	for (int i = 0; i < totalProdutos; i++) {

		cout << "\nQual o nome do seu Produto? ";
		getline(cin >> ws, produto.nome);

		do {
			cout << "Seu produto e medido em UNIDADE ou PESO?" << endl;
			cout << "[1] - Unidade" << endl;
			cout << "[2] - Peso" << endl;
			cin >> opcaoMedida;

		} while (opcaoMedida != 1 && opcaoMedida != 2);

		if (opcaoMedida == 1) {
			produto.tipoMedida = unidade;

			cout << "Quantas unidades? ";
			cin >> produto.quantidade.inteiro;
		}
		else {
			produto.tipoMedida = peso;

			cout << "Qual a quantidade em peso? ";
			cin >> produto.quantidade.decimal;
		}

		VetProdutos.push_back(produto);
	}
}

void Exibir(const vector<tipoProduto>& produtos, int opcaoMostrar) {
	int opcaoEspecifica;

	if (produtos.empty()) {
		cout << "Nenhum produto cadastrado." << endl;
		return;
	}

	if (opcaoMostrar == 1) {

		do {
			cout << "\nEscolha um produto para ser mostrado:" << endl;

			for (int i = 0; i < produtos.size(); i++) {
				cout << "[" << i + 1 << "] - "
					<< produtos[i].nome << endl;
			}

			cin >> opcaoEspecifica;

		} while (opcaoEspecifica < 1 ||
			opcaoEspecifica > produtos.size());

		int indice = opcaoEspecifica - 1;

		cout << "\nNome: "
			<< produtos[indice].nome << endl;

		if (produtos[indice].tipoMedida == unidade) {

			cout << "Medida: Unidade" << endl;

			cout << "Quantidade: "
				<< produtos[indice].quantidade.inteiro
				<< endl;
		}
		else {

			cout << "Medida: Peso" << endl;

			cout << "Quantidade: "
				<< produtos[indice].quantidade.decimal
				<< endl;
		}
	}
	else {

		cout << "\n--- PRODUTOS CADASTRADOS ---" << endl;

		for (int i = 0; i < produtos.size(); i++) {

			cout << "\nProduto " << i + 1 << endl;

			cout << "Nome: "
				<< produtos[i].nome << endl;

			if (produtos[i].tipoMedida == unidade) {

				cout << "Medida: Unidade" << endl;

				cout << "Quantidade: "
					<< produtos[i].quantidade.inteiro
					<< endl;
			}
			else {

				cout << "Medida: Peso" << endl;

				cout << "Quantidade: "
					<< produtos[i].quantidade.decimal
					<< endl;
			}
		}
	}
}

void MostrarProdutos(const vector<tipoProduto>& produtos) {
	int opcaoMostrar;

	if (produtos.empty()) {
		cout << "Nenhum produto cadastrado." << endl;
		return;
	}

	do {
		cout << "\nDeseja mostrar quais produtos?" << endl;
		cout << "[1] - Algum produto em especifico." << endl;
		cout << "[2] - Todos." << endl;
		cin >> opcaoMostrar;

	} while (opcaoMostrar != 1 && opcaoMostrar != 2);

	Exibir(produtos, opcaoMostrar);
}

void Busca(const vector<tipoProduto>& produtos) {
	string nomeBusca;
	int posicao = -1;

	if (produtos.empty()) {
		cout << "Nenhum produto cadastrado." << endl;
		return;
	}

	cout << "\nDigite o nome do produto que deseja buscar: ";
	getline(cin >> ws, nomeBusca);

	for (int i = 0; i < produtos.size(); i++) {

		if (produtos[i].nome == nomeBusca) {
			posicao = i;
			break;
		}
	}

	if (posicao == -1) {
		cout << "Produto nao encontrado." << endl;
	}
	else {

		cout << "\nProduto encontrado!" << endl;
		cout << "Nome: " << produtos[posicao].nome << endl;

		if (produtos[posicao].tipoMedida == unidade) {
			cout << "Medida: Unidade" << endl;
			cout << "Quantidade: " << produtos[posicao].quantidade.inteiro << endl;
		}
		else {
			cout << "Medida: Peso" << endl;
			cout << "Quantidade: " << produtos[posicao].quantidade.decimal << endl;
		}
	}
}

int main() {
	int totalProdutos = 0;

	vector<tipoProduto> VetProdutos;
	PedirNome(VetProdutos, totalProdutos);
	MostrarProdutos(VetProdutos);
	Busca(VetProdutos);

	return 0;
}