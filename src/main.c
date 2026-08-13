#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char chave[50];
    char texto[1000];
} Snippet;


Snippet snippets[100];
int quantidade = 0;

int main (void)
{
    int opcao;
    while (1)
    {
        printf("======================\n");
        printf("     SNIPPET MANAGER\n");
        printf("======================\n");
        printf("1. Criar snippet\n");
        printf("2. Listar snippets\n");
        printf("3. Buscar snippet\n");
        printf("4. Editar snippet\n");
        printf("5. Excluir snippet\n");
        printf("6. Sair\n\n");

        printf("Escolha (numero): ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
            case 1:
                criar_snippet();
                break;
        
            case 2:
                listar_snippets();
                break;

            case 3:
                buscar_snippet();
                break;

            case 4:
                // editar snippet
                break;

            case 5:
                // excluir snippet
                break;

            case 6:
                return 0;
        }
    }


}

