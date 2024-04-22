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