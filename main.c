#include "agenda.h" // Inclui o arquivo de cabeçalho agenda.h, que contém definições de estruturas e protótipos de funções.
#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C para usar funções como printf() e scanf().

int main() {
  Contato listaContatos[MAX_CONTACTS]; // Declara um array de contatos com o tamanho máximo definido em MAX_CONTACTS.
  int totalContatos = 0; // Inicializa o número total de contatos como zero.
  int opcao; // Declara uma variável para armazenar a opção escolhida pelo usuário.

  do {
    printf("\nMenu:\n");
    printf("1. Adicionar contato\n");
    printf("2. Listar contatos\n");
    printf("3. Deletar contato\n");
    printf("4. Salvar agenda\n");
    printf("5. Carregar agenda\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao); // Solicita ao usuário que escolha uma opção e armazena o valor na variável 'opcao'.

    switch (opcao) { // Inicia uma estrutura switch-case para executar diferentes ações com base na opção escolhida pelo usuário.
    case 1: // Se a opção for 1:
      adicionarContato(listaContatos, &totalContatos); // Chama a função adicionarContato() para adicionar um novo contato.
      break; // Sai do switch-case.
    case 2: // Se a opção for 2:
      listarContatos(listaContatos, totalContatos); // Chama a função listarContatos() para exibir todos os contatos.
      break; // Sai do switch-case.
    case 3: // Se a opção for 3:
      deletarContato(listaContatos, &totalContatos); // Chama a função deletarContato() para deletar um contato existente.
      break; // Sai do switch-case.
    case 4: // Se a opção for 4:
      salvarAgenda(listaContatos, totalContatos); // Chama a função salvarAgenda() para salvar os contatos em um arquivo.
      break; // Sai do switch-case.
    case 5: // Se a opção for 5:
      carregarAgenda(listaContatos, &totalContatos); // Chama a função carregarAgenda() para carregar os contatos de um arquivo.
      break; // Sai do switch-case.
    case 6: // Se a opção for 6:
      printf("Você está saindo :(\n"); // Exibe uma mensagem indicando que o usuário está saindo.
      break; // Sai do switch-case.
    default: // Se a opção não corresponder a nenhum dos casos anteriores:
      printf("Opção inválida!\n"); // Exibe uma mensagem indicando que a opção é inválida.
    }
  } while (opcao != 6); // Repete o loop enquanto a opção escolhida pelo usuário for diferente de 6 (sair).

  return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}
