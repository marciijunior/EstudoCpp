v#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==================================================
// STRUCT PARA EXEMPLOS COM VECTOR
// ==================================================

struct Produto {
    string nome;
    double preco;
};


// ==================================================
// FUNCAO QUE APENAS LE O VECTOR
// const = nao permite alterar
// & = evita copiar todo o vector
// ==================================================

void mostrarNumeros(const vector<int>& numeros) {

    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;
}


// ==================================================
// FUNCAO QUE ALTERA O VECTOR
// & = trabalha diretamente com o vector original
// ==================================================

void adicionarNumero(vector<int>& numeros, int numero) {

    numeros.push_back(numero);
}


// ==================================================
// VECTOR COM STRUCT
// ==================================================

void mostrarProdutos(const vector<Produto>& produtos) {

    for (int i = 0; i < produtos.size(); i++) {

        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preco: R$" << produtos[i].preco << endl;
        cout << endl;
    }
}


int main() {

    // ==================================================
    // 1. CRIANDO UM VECTOR
    // ==================================================

    vector<int> numeros;


    // ==================================================
    // 2. PUSH_BACK()
    // Adiciona valores ao final
    // ==================================================

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);

    // numeros:
    // [10] [20] [30]


    // ==================================================
    // 3. SIZE()
    // Retorna a quantidade de elementos
    // ==================================================

    cout << "Quantidade: " << numeros.size() << endl;

    // Resultado:
    // 3


    // ==================================================
    // 4. ACESSANDO POSICOES COM []
    // ==================================================

    cout << numeros[0] << endl;
    cout << numeros[1] << endl;
    cout << numeros[2] << endl;

    // Índices:
    //
    //   0    1    2
    // [10] [20] [30]


    // ==================================================
    // 5. FRONT()
    // Primeiro elemento
    // ==================================================

    cout << "Primeiro: " << numeros.front() << endl;


    // ==================================================
    // 6. BACK()
    // Ultimo elemento
    // ==================================================

    cout << "Ultimo: " << numeros.back() << endl;


    // ==================================================
    // 7. EMPTY()
    // Verifica se o vector esta vazio
    // ==================================================

    if (numeros.empty()) {

        cout << "Vector vazio" << endl;
    }
    else {

        cout << "Vector possui elementos" << endl;
    }


    // ==================================================
    // 8. POP_BACK()
    // Remove o ultimo elemento
    // ==================================================

    numeros.pop_back();

    // Antes:
    // [10] [20] [30]
    //
    // Depois:
    // [10] [20]


    // ==================================================
    // 9. INSERT()
    // Insere em uma posicao especifica
    // ==================================================

    numeros.insert(numeros.begin() + 1, 15);

    // Antes:
    // [10] [20]
    //
    // Depois:
    // [10] [15] [20]


    // ==================================================
    // 10. BEGIN()
    // Representa o inicio do vector
    // ==================================================

    // numeros.begin() + 0
    // indice 0

    // numeros.begin() + 1
    // indice 1

    // numeros.begin() + 2
    // indice 2


    // ==================================================
    // 11. ERASE()
    // Remove elemento de uma posicao especifica
    // ==================================================

    numeros.erase(numeros.begin() + 1);

    // Antes:
    // [10] [15] [20]
    //
    // Depois:
    // [10] [20]


    // ==================================================
    // 12. AT()
    // Acessa uma posicao verificando se ela existe
    // ==================================================

    cout << numeros.at(0) << endl;

    // numeros[0]
    // acesso direto

    // numeros.at(0)
    // acesso com verificacao


    // ==================================================
    // 13. FOR TRADICIONAL
    // ==================================================

    cout << "FOR tradicional:" << endl;

    for (int i = 0; i < numeros.size(); i++) {

        cout << numeros[i] << " ";
    }

    cout << endl;


    // ==================================================
    // 14. RANGE-BASED FOR
    // Cada valor recebe uma COPIA do elemento
    // ==================================================

    cout << "Range-based for:" << endl;

    for (int valor : numeros) {

        cout << valor << " ";
    }

    cout << endl;


    // ==================================================
    // 15. RANGE-BASED FOR COM REFERENCIA
    // Altera os valores originais
    // ==================================================

    for (int& valor : numeros) {

        valor = valor * 2;
    }

    // Se antes:
    // [10] [20]
    //
    // Agora:
    // [20] [40]


    // ==================================================
    // 16. RANGE-BASED FOR COM CONST &
    // Nao copia e nao permite alterar
    // ==================================================

    for (const int& valor : numeros) {

        cout << valor << " ";
    }

    cout << endl;


    // ==================================================
    // 17. VECTOR EM FUNCAO
    // ==================================================

    mostrarNumeros(numeros);


    // ==================================================
    // 18. FUNCAO QUE ALTERA VECTOR
    // ==================================================

    adicionarNumero(numeros, 100);

    mostrarNumeros(numeros);


    // ==================================================
    // 19. VECTOR COM STRUCT
    // ==================================================

    vector<Produto> produtos;

    Produto p1;

    p1.nome = "Mouse";
    p1.preco = 80;

    produtos.push_back(p1);


    Produto p2;

    p2.nome = "Teclado";
    p2.preco = 150;

    produtos.push_back(p2);


    // ==================================================
    // 20. ACESSANDO STRUCT DENTRO DO VECTOR
    // ==================================================

    cout << produtos[0].nome << endl;
    cout << produtos[0].preco << endl;

    cout << produtos[1].nome << endl;
    cout << produtos[1].preco << endl;


    // ==================================================
    // 21. MOSTRANDO VECTOR DE STRUCT
    // ==================================================

    mostrarProdutos(produtos);


    // ==================================================
    // 22. SIZE() X CAPACITY()
    // ==================================================

    vector<int> valores;

    cout << "Size: " << valores.size() << endl;
    cout << "Capacity: " << valores.capacity() << endl;

    valores.push_back(10);

    cout << "Size: " << valores.size() << endl;
    cout << "Capacity: " << valores.capacity() << endl;

    valores.push_back(20);
    valores.push_back(30);

    cout << "Size: " << valores.size() << endl;
    cout << "Capacity: " << valores.capacity() << endl;

    // size()
    // quantidade REAL de elementos

    // capacity()
    // quantidade que cabe no espaco atualmente reservado


    // ==================================================
    // 23. COMO O VECTOR CRESCE
    // ==================================================

    /*
        Quando nao existe mais espaco disponivel:

        1 - O vector reserva um bloco maior de memoria

        2 - Copia ou move os elementos antigos

        3 - Libera o bloco antigo

        4 - Continua utilizando o novo bloco


        Isso lembra o processo manual:

        new[]
        copiar elementos
        delete[]

        Mas o vector faz automaticamente.
    */


    // ==================================================
    // 24. COMPARACAO COM NEW[] E DELETE[]
    // ==================================================

    int tamanho = 3;

    int* vetorDinamico = new int[tamanho];

    vetorDinamico[0] = 10;
    vetorDinamico[1] = 20;
    vetorDinamico[2] = 30;

    for (int i = 0; i < tamanho; i++) {

        cout << vetorDinamico[i] << " ";
    }

    cout << endl;

    delete[] vetorDinamico;

    vetorDinamico = nullptr;


    // ==================================================
    // 25. MESMA IDEIA UTILIZANDO VECTOR
    // ==================================================

    vector<int> vetorAutomatico;

    vetorAutomatico.push_back(10);
    vetorAutomatico.push_back(20);
    vetorAutomatico.push_back(30);

    // Nao precisamos utilizar:
    //
    // new[]
    // delete[]
    //
    // O vector gerencia a memoria.


    // ==================================================
    // 26. CLEAR()
    // Remove todos os elementos
    // ==================================================

    vetorAutomatico.clear();

    cout << "Size depois do clear: "
        << vetorAutomatico.size()
        << endl;


    // ==================================================
    // RESUMO
    // ==================================================

    /*
        vector<int> numeros;

        push_back()
        adiciona no final


        pop_back()
        remove do final


        size()
        quantidade de elementos


        capacity()
        capacidade atualmente reservada


        front()
        primeiro elemento


        back()
        ultimo elemento


        empty()
        verifica se esta vazio


        clear()
        remove todos os elementos


        insert()
        adiciona em uma posicao especifica


        erase()
        remove de uma posicao especifica


        begin()
        representa o inicio do vector


        numeros[i]
        acesso direto


        numeros.at(i)
        acesso com verificacao


        for (int valor : numeros)

        valor = copia do elemento


        for (int& valor : numeros)

        valor = referencia ao elemento original


        for (const int& valor : numeros)

        valor = referencia constante
        nao copia
        nao permite alterar


        vector<Produto> produtos;

        permite armazenar structs dentro de vector


        const vector<int>&

        usado quando a funcao apenas consulta o vector


        vector<int>&

        usado quando a funcao precisa alterar o vector
    */


    return 0;
}