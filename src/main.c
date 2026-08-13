#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char chave[50];
    char texto[1000];
} Snippet;

void criar_snippet();
void listar_snippets();
void buscar_snippet();

Snippet snippets[100];
int quantidade = 0;

int main(void)
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

            default:
                printf("Opcao invalida.\n");
                break;
        }

        printf("\n");
    }
}

void criar_snippet()
{
    if (quantidade >= 100)
    {
        printf("Limite de snippets atingido.\n");
        return;
    }

    printf("Chave: ");
    fgets(snippets[quantidade].chave, 50, stdin);

    snippets[quantidade].chave[
        strcspn(snippets[quantidade].chave, "\n")
    ] = '\0';

    printf("Texto: ");
    fgets(snippets[quantidade].texto, 1000, stdin);

    snippets[quantidade].texto[
        strcspn(snippets[quantidade].texto, "\n")
    ] = '\0';

    quantidade++;

    printf("Snippet criado!\n");
}

void listar_snippets()
{
    if (quantidade == 0)
    {
        printf("Nenhum snippet cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("\n--- Snippet %d ---\n", i + 1);
        printf("Chave: %s\n", snippets[i].chave);
        printf("Texto: %s\n", snippets[i].texto);
    }
}

void buscar_snippet()
{
    char chave[50];
    int encontrado = 0;

    printf("Chave: ");
    fgets(chave, 50, stdin);

    chave[strcspn(chave, "\n")] = '\0';

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(chave, snippets[i].chave) == 0)
        {
            printf("\nSnippet encontrado!\n");
            printf("Chave: %s\n", snippets[i].chave);
            printf("Texto: %s\n", snippets[i].texto);

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
    {
        printf("Snippet nao encontrado.\n");
    }
}