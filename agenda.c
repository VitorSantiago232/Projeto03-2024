#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void adicionarContato(Contato lista[], int *totalContatos) {
    if (*totalContatos < MAX_CONTACTS) {
        Contato novoContato;
        printf("Digite o nome: ");
        scanf("%s", novoContato.nome);
        printf("Digite o sobrenome: ");
        scanf("%s", novoContato.sobrenome);
        printf("Digite o email: ");
        scanf("%s", novoContato.email);
        printf("Digite o telefone: ");
        scanf("%s", novoContato.telefone);
        lista[*totalContatos] = novoContato;
        (*totalContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A lista de contatos está cheia!\n");
    }

}

void listarContatos(Contato lista[], int totalContatos) {
    if (totalContatos == 0) {
        printf("A lista de contatos está vazia!\n");
    } else {
        printf("Lista de contatos:\n");
        for (int i = 0; i < totalContatos; i++) {
            printf("%d: %s %s, Email: %s, Telefone: %s\n", i+1, lista[i].nome, lista[i].sobrenome, lista[i].email, lista[i].telefone);
        }
    }
}

void deletarContato(Contato lista[], int *totalContatos) {
    if (*totalContatos == 0) {
        printf("A lista de contatos está vazia!\n");
        return;
    }

    char telefone[15];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%s", telefone);

    int i;
    for (i = 0; i < *totalContatos; i++) {
        if (strcmp(lista[i].telefone, telefone) == 0) {
            for (int j = i; j < *totalContatos - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*totalContatos)--;
            printf("Contato deletado com sucesso!\n");
            return;
        }
    }
    printf("Contato não encontrado!\n");
}
}

