#include <stdio.h>
#include "agenda.h"

int main() {
    Contato listaContatos[MAX_CONTACTS];
    int totalContatos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(listaContatos, &totalContatos);
                break;
            case 2:
                listarContatos(listaContatos, totalContatos);
                break;
            case 3:
                deletarContato(listaContatos, &totalContatos);
                break;
            case 4:
                salvarAgenda(listaContatos, totalContatos);
                break;
            case 5:
                carregarAgenda(listaContatos, &totalContatos);
                break;
            case 6:
                printf("Você esta saindo :(\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}
