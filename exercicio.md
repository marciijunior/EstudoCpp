Maior e menor número — Leia N números e encontre o maior, o menor e suas posições. Use: for, if, vetor.

Segundo maior valor — Encontre o segundo maior número de um vetor sem ordenar o vetor inteiro. Use: vetor, condicionais.

Remover duplicados — Receba vários inteiros e crie outro vetor contendo apenas valores únicos. Use: busca sequencial, loops.

Contagem de frequência — Dado um vetor, informe quantas vezes cada número aparece. Ex.: {2,2,5,2,5} → 2 = 3 vezes, 5 = 2 vezes.

Inverter vetor sem outro vetor — Inverta os elementos no próprio vetor. Use: índices e variável temporária.

Palíndromo — Leia uma palavra ou frase e determine se ela é igual de trás para frente. Tente ignorar espaços. Use: string, índices, length().

Contar caracteres — Informe quantas vogais, consoantes, números e espaços existem em uma frase.

Primeiro caractere não repetido — Ex.: "aabbcddee" → resposta: c.

FizzBuzz avançado — De 1 até N: múltiplos de 3 → Fizz, de 5 → Buzz, de ambos → FizzBuzz. Depois permita que o usuário escolha os dois divisores.

Número primo — Crie uma função bool ehPrimo(int numero) e use-a para listar todos os primos até N.

Fatorial iterativo e recursivo — Faça duas funções diferentes para calcular o mesmo fatorial e compare os resultados.

Busca sequencial — Procure um valor dentro de um vetor e retorne sua posição ou -1.

Busca binária — Faça uma busca binária manual em um vetor ordenado. Não use funções prontas.

Bubble Sort — Implemente o Bubble Sort e conte quantas comparações e trocas ocorreram.

Selection Sort — Implemente e depois compare o número de trocas com o Bubble Sort.

Insertion Sort — Ordene uma lista de notas usando Insertion Sort.

Escolher algoritmo de ordenação — Crie um menu que permita ordenar o mesmo vetor com Bubble, Selection ou Insertion Sort.

Função por valor, referência e ponteiro — Crie três funções que tentem alterar um número: uma recebe int, outra int&, outra int*. Mostre a diferença no main.

Trocar dois números usando ponteiros — Crie void trocar(int* a, int* b) sem usar std::swap.

Somar vetor usando ponteiros — Percorra um array usando apenas aritmética de ponteiros, sem vet[i].

Maior elemento usando ponteiro — Crie uma função que receba int* vet e tamanho e retorne o maior valor.

Alocação com new[] — Peça uma quantidade ao usuário, crie dinamicamente um vetor, leia os valores, calcule média e libere com delete[].

Redimensionamento manual com new[] — Comece com 3 elementos, peça um novo tamanho, crie outro bloco, copie os valores que couberem, libere o antigo e redirecione o ponteiro.

Alocação com malloc() — Repita o exercício de média usando malloc() e free() em vez de new[].

calloc() — Crie um vetor de N inteiros com calloc(), mostre os valores iniciais e depois altere alguns deles.

realloc() crescente — Comece com espaço para 3 números. Depois permita aumentar para N, preservando os números anteriores.

realloc() decrescente — Comece com 10 elementos e permita diminuir o bloco. Mostre quais valores permaneceram.

realloc() seguro — Faça o exercício anterior usando um ponteiro temporário e tratando corretamente nullptr.

Gerenciador dinâmico de números — Menu: adicionar número, listar, buscar, remover, aumentar capacidade e sair. Use obrigatoriamente malloc, realloc e free.

Struct de funcionário — Crie Funcionario com código, idade e salário. Cadastre vários funcionários e encontre o maior salário e a média salarial.

Struct dinâmica com malloc() — Crie várias structs Produto com int codigo e double preco usando malloc(). Cadastre e mostre todas.

Redimensionar vetor de structs — Comece com espaço para 2 produtos e permita aumentar a quantidade usando realloc().

Busca em vetor de structs — Procure um produto pelo código e mostre seus dados.

Remover struct de vetor — Dado um produto a remover, mova os elementos seguintes uma posição para trás e reduza o bloco com realloc().

Vector de produtos — Repita o sistema anterior usando vector<Produto> em vez de malloc. Compare mentalmente qual implementação ficou mais simples.

Cadastro sem limite conhecido — Use vector e permita cadastrar produtos até o usuário escolher sair.

Remover elemento do vector — Procure um produto pelo nome e remova usando erase().

Vector dentro de struct — Crie uma struct Aluno que tenha nome e vector<double> notas. Cadastre alunos e calcule a média individual.

Vector de structs + busca — Procure um aluno pelo nome e mostre todas as notas dele.

Enum de situação do aluno — Crie enum Situacao { Reprovado, Exame, Aprovado } e determine a situação de cada aluno de acordo com a média.

Enum class + switch — Faça um sistema de pedidos com enum class Status { Pendente, Pago, Enviado, Entregue }. Use switch para mostrar mensagens diferentes.

Union básica — Um produto pode ser vendido por unidade (int) ou por peso (double). Use enum para indicar qual membro da union está válido.

Sistema de estoque com enum + union + struct + vector — Cadastre produtos por unidade ou peso, liste, busque e remova. Este é parecido com o que já fizemos, mas faça novamente sem consultar o código anterior.

Pilha manual — Implemente uma pilha de inteiros usando array e variável topo. Operações: empilhar, desempilhar e mostrar.

Fila manual — Implemente uma fila usando array com inicio e fim. Operações: inserir, remover e mostrar.

Verificar parênteses — Dada uma expressão como ((2+3)*5), verifique se os parênteses estão balanceados usando lógica de pilha.

Histórico de comandos — Simule um sistema de “desfazer” usando uma pilha de strings.

Arquivo de produtos — Cadastre produtos e salve como nome,quantidade usando ofstream.

Carregar arquivo para vector — Leia produtos.txt, reconstrua structs e coloque todas em um vector.

Buscar produto carregado de arquivo — Carregue o arquivo e permita buscar pelo nome.

Alterar produto persistente — Carregue para o vector, altere um produto e reescreva o arquivo inteiro.

Excluir produto persistente — Carregue, use erase() e reescreva o arquivo sem o produto removido.

CRUD completo em arquivo — Menu com cadastrar, listar, buscar, alterar, remover e sair. Os dados devem continuar existindo depois que o programa fechar.

Ranking de candidatos — Crie uma struct Candidato com nome, três notas e média. Armazene em vector, calcule médias, ordene por maior média e salve o ranking em arquivo.

Sistema de funcionários — Cadastre funcionários dinamicamente. Cada um possui código, salário e setor. Permita busca, alteração, remoção e ordenação por salário.

Sistema híbrido vector + new[] — Produtos ficam em vector, mas setores devem ser armazenados com new string[]. Permita redimensionar os setores preservando os antigos.

Sistema híbrido vector + malloc — Produtos ficam em vector, mas códigos temporários devem ser armazenados em bloco criado por malloc e redimensionado com realloc.

Detectar memory leak — Receba vários pequenos códigos contendo malloc, realloc e free e diga onde existe vazamento, ponteiro pendente ou double free. Depois corrija cada um.

Implementar seu próprio “vector” simplificado — Use int* dados, int tamanho e int capacidade. Comece com capacidade 2. Quando encher, dobre a capacidade com realloc(). Implemente adicionar, mostrar e remover.

Vector manual com struct — Faça o exercício anterior, mas armazenando Produto em vez de int.

Sistema de votação — struct Candidato, cadastro de candidatos, votos, busca por código, contagem, vencedor e persistência em arquivo. Use vector.

Sistema bancário simples — struct Conta com número, saldo e status. Permita depósito, saque, transferência, busca e salvar em arquivo. Use enum para status da conta.

Controle de estacionamento — Cada veículo tem placa, hora de entrada e tipo. Busque pela placa, remova na saída e calcule cobrança. Salve histórico em arquivo.

Agenda de contatos — Nome, telefone e idade. Cadastrar, buscar, alterar, remover, ordenar alfabeticamente e salvar/carregar arquivo.

Sistema de notas acadêmicas — Cada aluno possui quantidade variável de notas. Use vector<double> dentro da struct. Calcule média, maior nota, menor nota e situação por enum.

Análise de texto — Leia um arquivo de texto inteiro e informe quantidade de linhas, palavras, caracteres, vogais e a palavra que mais aparece.

Ordenação de arquivo — Leia números de um arquivo para um vector, ordene usando um algoritmo criado por você e grave o resultado em outro arquivo.

Interseção de vetores — Dados dois vetores, crie um terceiro contendo apenas elementos presentes nos dois, sem duplicação.

Two Sum — Dado um vetor e um valor alvo, encontre dois números cuja soma seja igual ao alvo. Ex.: {2,7,11,15}, alvo 9 → 2 + 7.

Mover zeros para o final — {0,1,0,3,12} deve virar {1,3,12,0,0}, tentando evitar criar outro vetor.

Maior sequência crescente — Encontre o maior trecho consecutivo crescente em um vetor. Ex.: {1,2,3,1,2} → tamanho 3.

Rotacionar vetor — Rotacione os elementos k posições para a direita. Ex.: {1,2,3,4,5}, k=2 → {4,5,1,2,3}.

Mesclar dois vetores ordenados — Receba dois vetores já ordenados e produza um terceiro também ordenado sem usar sort().

Remover duplicados de vetor ordenado — Faça a remoção tentando trabalhar no próprio vetor.

Frequência de palavras — Leia uma frase e informe a frequência de cada palavra.

Produto mais vendido — Leia um arquivo de vendas no formato produto,quantidade e descubra qual produto teve maior quantidade total.

Mini banco de dados em TXT — Cada linha representa uma pessoa: codigo,nome,idade. Faça CRUD, busca por código e persistência.

Sistema de estoque completo — Produto possui código, nome, medida (enum), quantidade (union) e preço. Faça CRUD, ordenação, busca e arquivo.

Gerenciador de memória de produtos — Faça o estoque anterior sem vector, usando apenas Produto*, malloc(), realloc() e free().

Desafio final de entrevista — Desenvolva um sistema de candidatos em que a quantidade inicialmente é desconhecida. Use malloc/realloc para armazená-los, struct para os dados, enum para situação, funções com ponteiros/referências, busca sequencial, algoritmo de ordenação próprio, remoção dinâmica, salvamento em arquivo e carregamento dos dados ao iniciar. O programa deve liberar toda a memória corretamente antes de encerrar.