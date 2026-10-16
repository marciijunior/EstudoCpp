#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Aluno {
    string nome;
    int idade;
    vector<double> notas;
};

void quantidadeMaterias(int& quantidade, string*& materias);
void adicionarMaterias(int quantidade, string* materias);
void mostrarMaterias(int quantidade, string* materias);
void modificarMaterias(int& quantidade, string*& materias);

void cadastrarAluno(vector<Aluno>& pessoas);
void adicionarNota(vector<Aluno>& pessoas);
void mostrarAlunos(const vector<Aluno>& pessoas);
void mostrarMedia(const vector<Aluno>& pessoas);
void melhorAluno(const vector<Aluno>& pessoas);
void removerAluno(vector<Aluno>& pessoas);

double calcularMedia(const Aluno& aluno);

void menu(int& quantidade, string*& materias, vector<Aluno>& pessoas);

void quantidadeMaterias(int& quantidade, string*& materias) {
    cout << "Escreva a quantidade de materias: ";
    cin >> quantidade;

    if (quantidade <= 0) {
        cout << "Quantidade invalida!" << endl;
        quantidade = 0;
        return;
    }

    if (materias != nullptr) {
        delete[] materias;
    }

    materias = new string[quantidade];
}

void adicionarMaterias(int quantidade, string* materias) {
    if (materias == nullptr || quantidade == 0) {
        cout << "Informe primeiro a quantidade de materias!" << endl;
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        cout << "Materia [" << i + 1 << "/" << quantidade << "]: ";
        cin >> materias[i];
    }
}

void mostrarMaterias(int quantidade, string* materias) {
    if (materias == nullptr || quantidade == 0) {
        cout << "Nenhuma materia cadastrada!" << endl;
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        cout << i + 1 << " - " << materias[i] << endl;
    }
}

void modificarMaterias(int& quantidade, string*& materias) {
    if (materias == nullptr) {
        cout << "Informe primeiro a quantidade de materias!" << endl;
        return;
    }

    int novaQuantidade;

    cout << "Nova quantidade de materias: ";
    cin >> novaQuantidade;

    if (novaQuantidade <= 0) {
        cout << "Quantidade invalida!" << endl;
        return;
    }

    string* novasMaterias = new string[novaQuantidade];

    int limite;

    if (quantidade < novaQuantidade) {
        limite = quantidade;
    }
    else {
        limite = novaQuantidade;
    }

    for (int i = 0; i < limite; i++) {
        novasMaterias[i] = materias[i];
    }

    delete[] materias;
    materias = novasMaterias;
    quantidade = novaQuantidade;

    cout << "Quantidade alterada!" << endl;
}

void cadastrarAluno(vector<Aluno>& pessoas) {
    Aluno aluno;

    cout << "Nome do aluno: ";
    cin >> aluno.nome;

    do {
        cout << "Idade: ";
        cin >> aluno.idade;
    } while (aluno.idade <= 0);

    pessoas.push_back(aluno);

    cout << "Aluno cadastrado!" << endl;
}

void adicionarNota(vector<Aluno>& pessoas) {
    if (pessoas.empty()) {
        cout << "Nenhum aluno cadastrado!" << endl;
        return;
    }

    string nome;
    double nota;

    cout << "Nome do aluno: ";
    cin >> nome;

    for (int i = 0; i < pessoas.size(); i++) {
        if (pessoas[i].nome == nome) {
            do {
                cout << "Nota: ";
                cin >> nota;
            } while (nota < 0 || nota > 10);

            pessoas[i].notas.push_back(nota);

            cout << "Nota adicionada!" << endl;
            return;
        }
    }

    cout << "Aluno nao encontrado!" << endl;
}

void mostrarAlunos(const vector<Aluno>& pessoas) {
    if (pessoas.empty()) {
        cout << "Nenhum aluno cadastrado!" << endl;
        return;
    }

    for (int i = 0; i < pessoas.size(); i++) {
        cout << endl;
        cout << "Aluno: " << pessoas[i].nome << endl;
        cout << "Idade: " << pessoas[i].idade << endl;
        cout << "Notas: ";

        if (pessoas[i].notas.empty()) {
            cout << "Nenhuma nota";
        }
        else {
            for (int j = 0; j < pessoas[i].notas.size(); j++) {
                cout << pessoas[i].notas[j] << " ";
            }
        }

        cout << endl;
    }
}

double calcularMedia(const Aluno& aluno) {
    if (aluno.notas.empty()) {
        return 0;
    }

    double soma = 0;

    for (int i = 0; i < aluno.notas.size(); i++) {
        soma += aluno.notas[i];
    }

    return soma / aluno.notas.size();
}

void mostrarMedia(const vector<Aluno>& pessoas) {
    if (pessoas.empty()) {
        cout << "Nenhum aluno cadastrado!" << endl;
        return;
    }

    string nome;

    cout << "Nome do aluno: ";
    cin >> nome;

    for (int i = 0; i < pessoas.size(); i++) {
        if (pessoas[i].nome == nome) {
            if (pessoas[i].notas.empty()) {
                cout << "Aluno ainda nao possui notas!" << endl;
                return;
            }

            double media = calcularMedia(pessoas[i]);

            cout << "Media: " << media << endl;
            return;
        }
    }

    cout << "Aluno nao encontrado!" << endl;
}

void melhorAluno(const vector<Aluno>& pessoas) {
    if (pessoas.empty()) {
        cout << "Nenhum aluno cadastrado!" << endl;
        return;
    }

    int melhor = -1;
    double maiorMedia = 0;

    for (int i = 0; i < pessoas.size(); i++) {
        if (!pessoas[i].notas.empty()) {
            double media = calcularMedia(pessoas[i]);

            if (melhor == -1 || media > maiorMedia) {
                melhor = i;
                maiorMedia = media;
            }
        }
    }

    if (melhor == -1) {
        cout << "Nenhum aluno possui notas!" << endl;
        return;
    }

    cout << "Melhor aluno: " << pessoas[melhor].nome << endl;
    cout << "Media: " << maiorMedia << endl;
}

void removerAluno(vector<Aluno>& pessoas) {
    if (pessoas.empty()) {
        cout << "Nenhum aluno cadastrado!" << endl;
        return;
    }

    string nome;

    cout << "Nome do aluno que deseja remover: ";
    cin >> nome;

    for (int i = 0; i < pessoas.size(); i++) {
        if (pessoas[i].nome == nome) {
            pessoas.erase(pessoas.begin() + i);

            cout << "Aluno removido!" << endl;
            return;
        }
    }

    cout << "Aluno nao encontrado!" << endl;
}

void menu(int& quantidade, string*& materias, vector<Aluno>& pessoas) {
    int opcao;

    do {
        cout << endl;
        cout << "---------- MENU ----------" << endl;
        cout << "[1] - Informar quantidade de materias" << endl;
        cout << "[2] - Adicionar materias" << endl;
        cout << "[3] - Mostrar materias" << endl;
        cout << "[4] - Alterar quantidade de materias" << endl;
        cout << "[5] - Cadastrar aluno" << endl;
        cout << "[6] - Adicionar nota" << endl;
        cout << "[7] - Mostrar alunos" << endl;
        cout << "[8] - Mostrar media de um aluno" << endl;
        cout << "[9] - Mostrar melhor aluno" << endl;
        cout << "[10] - Remover aluno" << endl;
        cout << "[11] - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            quantidadeMaterias(quantidade, materias);
            break;

        case 2:
            adicionarMaterias(quantidade, materias);
            break;

        case 3:
            mostrarMaterias(quantidade, materias);
            break;

        case 4:
            modificarMaterias(quantidade, materias);
            break;

        case 5:
            cadastrarAluno(pessoas);
            break;

        case 6:
            adicionarNota(pessoas);
            break;

        case 7:
            mostrarAlunos(pessoas);
            break;

        case 8:
            mostrarMedia(pessoas);
            break;

        case 9:
            melhorAluno(pessoas);
            break;

        case 10:
            removerAluno(pessoas);
            break;

        case 11:
            cout << "Saindo..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 11);
}

int main() {
    int quantidade = 0;
    string* materias = nullptr;
    vector<Aluno> pessoas;

    menu(quantidade, materias, pessoas);

    delete[] materias;
    materias = nullptr;

    return 0;
}