#include <iostream>
#include <string>
using namespace std;

const int maxProdutos = 50;

struct estoque {
    string nomeProduto;
    double preco;
    int quantidade;
};

void qtdRealProdutos(int* numRealProduto) {
    do {
        cout << "Escreva a quantidade de produtos que deseja informar (No maximo 50): ";
        cin >> *numRealProduto;
    } while (*numRealProduto < 1 || *numRealProduto > maxProdutos);
}

void lerNome(int numRealProduto, estoque produto[]) {
    cin.ignore();

    for (int i = 0; i < numRealProduto; i++) {
        cout << "Escreva o nome do produto[" << i + 1
            << "/" << numRealProduto << "]: ";

        getline(cin, produto[i].nomeProduto);
    }
}

void lerPreco(int numRealProduto, estoque produto[]) {
    for (int i = 0; i < numRealProduto; i++) {
        cout << "Escreva o preco do produto[" << i + 1
            << "/" << numRealProduto << "]: ";

        cin >> produto[i].preco;
    }
}

void quantificar(int numRealProduto, estoque produto[]) {
    for (int i = 0; i < numRealProduto; i++) {
        cout << "Escreva a quantidade do produto[" << i + 1
            << "/" << numRealProduto << "]: ";

        cin >> produto[i].quantidade;
    }
}

void maiorPreco(int numRealProduto, estoque produto[]) {
    int maiorValor = 0;

    for (int i = 1; i < numRealProduto; i++) {
        if (produto[maiorValor].preco < produto[i].preco) {
            maiorValor = i;
        }
    }

    cout << "O produto com maior valor: "
        << produto[maiorValor].nomeProduto
        << ", R$" << produto[maiorValor].preco << endl;
}

void valorTotal(double& vTotal, int numRealProduto, estoque produto[]) {
    vTotal = 0;

    for (int i = 0; i < numRealProduto; i++) {
        vTotal += produto[i].preco * produto[i].quantidade;
    }

    cout << "Valor total do estoque: R$" << vTotal << endl;
}

void mostrarProdutos(int numRealProduto, estoque* pontProd) {
    for (int i = 0; i < numRealProduto; i++) {
        cout << "Produto " << i + 1 << ": ";
        cout << "Nome do produto: " << (*(pontProd + i)).nomeProduto;
        cout << "Preco: " << (*(pontProd + i)).preco;
        cout << "Quantidade: " << (*(pontProd + i)).quantidade;
        cout << endl;
    }
}

int main() {
    int numRealProduto = 0;
    double vTotal = 0;
    int opcao;

    estoque produto[maxProdutos];
    estoque* pontProd = produto;

    do {
        cout << endl;
        cout << "     MENU     " << endl;
        cout << "[1 - Cadastrar produto]" << endl;
        cout << "[2 - Mostrar produto mais caro]" << endl;
        cout << "[3 - Valor total do estoque]" << endl;
        cout << "[4 - Mostrar produtos]" << endl;
        cout << "[5 - Sair]" << endl;

        cin >> opcao;

        switch (opcao) {

        case 1:
            qtdRealProdutos(&numRealProduto);
            lerNome(numRealProduto, produto);
            lerPreco(numRealProduto, produto);
            quantificar(numRealProduto, produto);
            break;

        case 2:
            if (numRealProduto == 0) {
                cout << "Cadastre os produtos primeiro!" << endl;
            }
            else {
                maiorPreco(numRealProduto, produto);
            }
            break;

        case 3:
            if (numRealProduto == 0) {
                cout << "Cadastre os produtos primeiro!" << endl;
            }
            else {
                valorTotal(vTotal, numRealProduto, produto);
            }
            break;
        case 4:
            if (numRealProduto == 0) {
                cout << "Cadastre os produtos primeiro!" << endl;
            }
            else {
                mostrarProdutos(numRealProduto, pontProd);
            }
            break;

        case 5:
            cout << "Adeus!" << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 5);

    return 0;
}