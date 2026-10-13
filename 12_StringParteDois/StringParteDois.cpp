#include <iostream>
#include <string>
using namespace std;

int main() {
	string nome = "Marcio";
	string sobrenome = "Junior";

	string nomecompleto = nome + " " + sobrenome;
	cout << nomecompleto << endl;

	string cumprimento = "Ola ";
	cumprimento += nome;
	cout << cumprimento << endl;

	cout << "A senha e 1234? ";
	string senha = "1234";
	if (senha == "1234") {
		cout << "Sim. Senha correta." << endl;
	}
	else {
		cout << "Não. Senha incorreta." << endl;
	}

	string frase = "O gato roeu a bota do rei de Veneza.";
	cout << frase.find("Veneza") << endl;
	
	// Quando .find() nao encontra nada, ele retorna um string::npos

	string linguagem = "Programacao em c++";
	if (linguagem.find("c++") != string::npos) {
		cout << "Possui c++ no codigo!";
	}
	else {
		cout << "Nao possui c++ no codigo!";
	}

	return 0;
}