#include <iostream>
#include <string>
using namespace std;
// Conteudo visto: String, Nome[0], nome.length(), getline(cin, nome), cin.ignore() - para cin seguido de getline.

int main() {
	char letraA = 'A';
	string meuNome = "Marcio";
	cout << meuNome[0] << endl;
	// "M" 
	
	string nome;
	cout << "Digite o nome da pessoa: ";
	cin >> nome;
	cout << "Ola " << nome << "!" << endl;
	// Dessa forma, caso a pessoa digite o nome completo dela, somente o primeiro nome irá ser contabilizado. Para que os espaços sejam ignorados, utiliza-se getline().

	string nomeCompleto;
	cout << "Digite seu nome completo: ";
	cin.ignore();
	// Por termos utilizado um cin logo acima e um getline em seguida, um \n fica no buffer, fazendo com que o getline leia e pule imediatamente o cin do nome completo.
	getline(cin, nomeCompleto);
	cout << nomeCompleto << endl;

	int tamanho;
	cout << nome << endl;
	tamanho = nome.length();
	cout << "Seu nome tem " << tamanho << " letras." << endl;
	// Ou
	cout << "Seu nome tem " << nome.length() << " letras." << endl;

	// É possível percorrer uma string com for.
	string palavra = "Transformer";

	for (int i = 0; i < palavra.length(); i++) {
		cout << palavra[i] << endl;
	}

	return 0;
}