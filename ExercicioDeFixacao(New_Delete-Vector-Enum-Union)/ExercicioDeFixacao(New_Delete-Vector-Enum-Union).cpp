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

void DefinirSetores(string*& setores, int& quantidadeSetores) {
	if (setores != nullptr) {
		cout << "Os setores ja foram definidos. Use a opcao 3 para alterar." << endl;
		return;
	}
	do {
		cout << "Quantos setores deseja criar? ";
		cin >> quantidadeSetores;
	} while (quantidadeSetores <= 0);
	setores = new string[quantidadeSetores];
	cout << "Espaco para os setores criado." << endl;
}

void CadastrarSetores(string* setores, int quantidadeSetores) {
	if (setores == nullptr) {
		cout << "Primeiro defina a quantidade de setores." << endl;
		return;
	}
	for (int i = 0; i < quantidadeSetores; i++) {
		cout << "Nome do setor " << i + 1 << ": ";
		getline(cin >> ws, setores[i]);
	}
}

void AlterarQuantidadeSetores(string*& setores, int& quantidadeSetores) {
	int novaQuantidade;
	do {
		cout << "Digite a nova quantidade de setores: ";
		cin >> novaQuantidade;
	} while (novaQuantidade <= 0);

	string* novosSetores = new string[novaQuantidade];

	for (int i = 0; i < quantidadeSetores && i < novaQuantidade; i++) {
		novosSetores[i] = setores[i];
	}

	delete[] setores;
	setores = novosSetores;
	quantidadeSetores = novaQuantidade;

	cout << "Quantidade de setores alterada." << endl;
}

void MostrarSetores(const string* setores, int quantidadeSetores) {
	if (setores == nullptr || quantidadeSetores == 0) {
		cout << "Nenhum setor cadastrado." << endl;
		return;
	}
	cout << "\n--- SETORES ---" << endl;
	for (int i = 0; i < quantidadeSetores; i++) {
		cout << "[" << i + 1 << "] - ";
		if (setores[i].empty())
			cout << "Sem nome";
		else
			cout << setores[i];
		cout << endl;
	}
}

void PedirNome(vector<tipoProduto>& VetProdutos) {
	tipoProduto produto;
	int totalProdutos;
	int opcaoMedida;

	do {
		cout << "Quantos produtos deseja adicionar? ";
		cin >> totalProdutos;
	} while (totalProdutos <= 0);

	for (int i = 0; i < totalProdutos; i++) {
		cout << "Qual o nome do seu produto? ";
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

void MostrarUmProduto(const tipoProduto& produto) {
	cout << "Nome: " << produto.nome << endl;

	if (produto.tipoMedida == unidade) {
		cout << "Medida: Unidade" << endl;
		cout << "Quantidade: " << produto.quantidade.inteiro << endl;
	}
	else {
		cout << "Medida: Peso" << endl;
		cout << "Quantidade: " << produto.quantidade.decimal << endl;
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
			cout << "Escolha um produto:" << endl;
			for (int i = 0; i < produtos.size(); i++) {
				cout << "[" << i + 1 << "] - " << produtos[i].nome << endl;
			}
			cin >> opcaoEspecifica;
		} while (opcaoEspecifica < 1 || opcaoEspecifica > produtos.size());

		MostrarUmProduto(produtos[opcaoEspecifica - 1]);
	}
	else {
		for (int i = 0; i < produtos.size(); i++) {
			cout << "\nProduto " << i + 1 << endl;
			MostrarUmProduto(produtos[i]);
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
		cout << "Deseja mostrar quais produtos?" << endl;
		cout << "[1] - Algum produto em especifico" << endl;
		cout << "[2] - Todos" << endl;
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

	cout << "Digite o nome do produto que deseja buscar: ";
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
		cout << "Produto encontrado!" << endl;
		MostrarUmProduto(produtos[posicao]);
	}
}

void RemoverProduto(vector<tipoProduto>& produtos) {
	string nomeBusca;
	int posicao = -1;

	if (produtos.empty()) {
		cout << "Nenhum produto cadastrado." << endl;
		return;
	}

	cout << "Digite o nome do produto que deseja remover: ";
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
		produtos.erase(produtos.begin() + posicao);
		cout << "Produto removido." << endl;
	}
}

void MostrarQuantidadeProdutos(const vector<tipoProduto>& produtos) {
	cout << "Quantidade de produtos cadastrados: " << produtos.size() << endl;
}

int main() {
	vector<tipoProduto> VetProdutos;
	string* setores = nullptr;
	int quantidadeSetores = 0;
	int opcao;

	do {
		cout << "\n===== MENU =====" << endl;
		cout << "[1] - Definir quantidade de setores" << endl;
		cout << "[2] - Cadastrar setores" << endl;
		cout << "[3] - Alterar quantidade de setores" << endl;
		cout << "[4] - Mostrar setores" << endl;
		cout << "[5] - Cadastrar produtos" << endl;
		cout << "[6] - Mostrar produtos" << endl;
		cout << "[7] - Buscar produto pelo nome" << endl;
		cout << "[8] - Remover produto" << endl;
		cout << "[9] - Mostrar quantidade de produtos" << endl;
		cout << "[10] - Sair" << endl;
		cout << "Opcao: ";
		cin >> opcao;

		switch (opcao) {
		case 1:
			DefinirSetores(setores, quantidadeSetores);
			break;
		case 2:
			CadastrarSetores(setores, quantidadeSetores);
			break;
		case 3:
			AlterarQuantidadeSetores(setores, quantidadeSetores);
			break;
		case 4:
			MostrarSetores(setores, quantidadeSetores);
			break;
		case 5:
			PedirNome(VetProdutos);
			break;
		case 6:
			MostrarProdutos(VetProdutos);
			break;
		case 7:
			Busca(VetProdutos);
			break;
		case 8:
			RemoverProduto(VetProdutos);
			break;
		case 9:
			MostrarQuantidadeProdutos(VetProdutos);
			break;
		case 10:
			cout << "Até mais..." << endl;
			break;
		default:
			cout << "Opcao invalida." << endl;
		}
	} while (opcao != 10);

	delete[] setores;
	setores = nullptr;

	return 0;
}