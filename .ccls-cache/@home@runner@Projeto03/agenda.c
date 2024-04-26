#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C para usar funções como printf() e scanf().
#include <stdlib.h> // Inclui a biblioteca padrão de funções utilitárias em C, como malloc() e free().
#include <string.h> // Inclui a biblioteca padrão de manipulação de strings em C, como strcpy() e strcmp().
#include "agenda.h" // Inclui o arquivo de cabeçalho agenda.h, que contém definições de estruturas e protótipos de funções.

void adicionarContato(Contato lista[], int *totalContatos) {
    if (*totalContatos < MAX_CONTACTS) { // Verifica se o número total de contatos é menor que o máximo permitido.
        Contato novoContato; // Declara uma variável do tipo Contato para armazenar um novo contato.
        printf("Digite o nome: ");
        scanf("%s", novoContato.nome); // Solicita ao usuário que digite o nome do novo contato e armazena na variável novoContato.nome.
        printf("Digite o sobrenome: ");
        scanf("%s", novoContato.sobrenome); // Solicita ao usuário que digite o sobrenome do novo contato e armazena na variável novoContato.sobrenome.
        printf("Digite o email: ");
        scanf("%s", novoContato.email); // Solicita ao usuário que digite o email do novo contato e armazena na variável novoContato.email.
        printf("Digite o telefone: ");
        scanf("%s", novoContato.telefone); // Solicita ao usuário que digite o telefone do novo contato e armazena na variável novoContato.telefone.
        lista[*totalContatos] = novoContato; // Adiciona o novo contato à lista de contatos na posição indicada por totalContatos.
        (*totalContatos)++; // Incrementa o número total de contatos.
        printf("Contato adicionado com sucesso!\n"); // Exibe uma mensagem indicando que o contato foi adicionado com sucesso.
    } else {
        printf("A lista de contatos está cheia!\n"); // Exibe uma mensagem indicando que a lista de contatos está cheia.
    }
}

void listarContatos(Contato lista[], int totalContatos) {
    if (totalContatos == 0) { // Verifica se não há contatos na lista.
        printf("A lista de contatos está vazia!\n"); // Exibe uma mensagem indicando que a lista de contatos está vazia.
    } else {
        printf("Lista de contatos:\n");
        for (int i = 0; i < totalContatos; i++) { // Percorre a lista de contatos e exibe as informações de cada contato.
            printf("%d: %s %s, Email: %s, Telefone: %s\n", i+1, lista[i].nome, lista[i].sobrenome, lista[i].email, lista[i].telefone);
        }
    }
}

void deletarContato(Contato lista[], int *totalContatos) {
    if (*totalContatos == 0) { // Verifica se não há contatos na lista.
        printf("A lista de contatos está vazia!\n"); // Exibe uma mensagem indicando que a lista de contatos está vazia.
        return; // Retorna da função, pois não há contatos para deletar.
    }

    char telefone[15]; // Declara uma variável para armazenar o número de telefone do contato a ser deletado.
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%s", telefone); // Solicita ao usuário que digite o número de telefone do contato a ser deletado e armazena na variável telefone.

    int i;
    for (i = 0; i < *totalContatos; i++) { // Percorre a lista de contatos para encontrar o contato com o número de telefone especificado.
        if (strcmp(lista[i].telefone, telefone) == 0) { // Compara o número de telefone do contato atual com o número de telefone especificado.
            for (int j = i; j < *totalContatos - 1; j++) { // Move os contatos para frente na lista para preencher o espaço do contato deletado.
                lista[j] = lista[j + 1];
            }
            (*totalContatos)--; // Decrementa o número total de contatos.
            printf("Contato deletado com sucesso!\n"); // Exibe uma mensagem indicando que o contato foi deletado com sucesso.
            return; // Retorna da função após encontrar e deletar o contato.
        }
    }
    printf("Contato não encontrado!\n"); // Exibe uma mensagem indicando que o contato não foi encontrado na lista.
}

void carregarAgenda(Contato lista[], int *totalContatos) {
    FILE *arquivo; // Declara um ponteiro para um arquivo.
    arquivo = fopen("agenda.bin", "rb"); // Abre o arquivo "agenda.bin" para leitura binária.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Erro ao abrir o arquivo!\n"); // Exibe uma mensagem de erro caso não seja possível abrir o arquivo.
        return; // Retorna da função em caso de erro.
    }
    *totalContatos = fread(lista, sizeof(Contato), MAX_CONTACTS, arquivo); // Lê os contatos do arquivo para a lista de contatos.
    fclose(arquivo); // Fecha o arquivo após a leitura.
    printf("Sua agenda foi carregada com sucesso!\n"); // Exibe uma mensagem indicando que a agenda foi carregada com sucesso.
}
