#ifndef AGENDA_H // Diretiva de inclusão condicional: verifica se AGENDA_H não foi definido anteriormente
#define AGENDA_H 
// Define AGENDA_H para evitar múltiplas inclusões do mesmo arquivo de cabeçalho

#define MAX_CONTACTS 255 
// Define o tamanho máximo da lista de contatos

typedef struct { // Define uma estrutura chamada Contato para armazenar informações sobre um contato
    char nome[50]; // Campo para o nome do contato
    char sobrenome[50]; // Campo para o sobrenome do contato
    char email[100]; // Campo para o email do contato
    char telefone[15]; // Campo para o telefone do contato
} Contato; // Final da definição da estrutura

// Protótipos de função para manipular contatos
void adicionarContato(Contato lista[], int *totalContatos); // Adiciona um novo contato à lista
void listarContatos(Contato lista[], int totalContatos); // Lista todos os contatos da lista
void deletarContato(Contato lista[], int *totalContatos); // Deleta um contato da lista
void salvarAgenda(Contato lista[], int totalContatos); // Salva os contatos em um arquivo
void carregarAgenda(Contato lista[], int *totalContatos); // Carrega os contatos de um arquivo para a lista

#endif // Fim da diretiva de inclusão condicional
