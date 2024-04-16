#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CONTACTS 255

typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
} Contato;

void adicionarContato(Contato lista[], int *totalContatos);
void listarContatos(Contato lista[], int totalContatos);
void deletarContato(Contato lista[], int *totalContatos);
void salvarAgenda(Contato lista[], int totalContatos);
void carregarAgenda(Contato lista[], int *totalContatos);

#endif /* AGENDA_H */
