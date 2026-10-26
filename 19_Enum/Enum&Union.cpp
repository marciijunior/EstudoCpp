#include <iostream>
using namespace std;

// ENUM SIMPLES
enum Status {
	Pendente,
	Aprovado,
	Reprovado
};

// ENUM COM VALOR INICIAL PERSONALIZADO
enum Nivel {
	Baixo = 1,
	Medio,
	Alto
};

// ENUM COM VALORES ESPECIFICOS
enum Codigo {
	Sucesso = 200,
	NaoEncontrado = 404,
	ErroServidor = 500
};

// ENUM CLASS
enum class StatusPedido {
	Pendente,
	Finalizado
};

enum class StatusPagamento {
	Pendente,
	Finalizado
};

// ENUM CLASS PARA CONTROLAR A UNION
enum class TipoValor {
	Inteiro,
	Decimal
};

// UNION
union Valor {
	int inteiro;
	double decimal;
};

void mostrarValor(TipoValor tipo, const Valor& valor) {
	switch (tipo) {
	case TipoValor::Inteiro:
		cout << "Valor inteiro: " << valor.inteiro << endl;
		break;

	case TipoValor::Decimal:
		cout << "Valor decimal: " << valor.decimal << endl;
		break;
	}
}

int main() {

	// ENUM SIMPLES
	Status situacao = Aprovado;
	cout << "Valor numerico do status: " << situacao << endl;
	switch (situacao) {
	case Pendente:
		cout << "Situacao pendente." << endl;
		break;
	case Aprovado:
		cout << "Situacao aprovada." << endl;
		break;
	case Reprovado:
		cout << "Situacao reprovada." << endl;
		break;
	}
	cout << endl;
	// ENUM COM SEQUENCIA PERSONALIZADA
	Nivel nivel = Alto;
	cout << "Nivel numerico: " << nivel << endl;
	cout << endl;

	// ENUM COM VALORES ESPECIFICOS
	Codigo codigo = NaoEncontrado;
	cout << "Codigo: " << codigo << endl;
	cout << endl;

	// ENUM CLASS
	StatusPedido pedido = StatusPedido::Finalizado;
	StatusPagamento pagamento = StatusPagamento::Pendente;

	if (pedido == StatusPedido::Finalizado) {
		cout << "Pedido finalizado." << endl;
	}
	if (pagamento == StatusPagamento::Pendente) {
		cout << "Pagamento pendente." << endl;
	}
	cout << endl;

	// UNION CONTROLADA POR ENUM CLASS
	Valor valor;
	TipoValor tipo = TipoValor::Inteiro;
	valor.inteiro = 20;
	mostrarValor(tipo, valor);
	tipo = TipoValor::Decimal;
	valor.decimal = 7.5;
	mostrarValor(tipo, valor);

	return 0;
}