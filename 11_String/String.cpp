#include <iostream>
#include <string>
using namespace std;

int main() {
	char letraA = 'A';
	string meuNome = "Marcio";
	string nome;

	cout << "Digite o nome da pessoa: ";
	cin >> nome;
	cout << "Ola " << nome << "!";
	// Dessa forma, caso a pessoa digite o nome completo dela, somente o primeiro nome irá ser contabilizado. Para que os espaços sejam ignorados, utiliza-se getline().

	cout << "Digite seu nome completo: ";
	getline(cin, nome);

	cout << nome;

	return 0;
}