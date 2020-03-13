#include "cinema.h"
#include "geresessoes.h"

int main()
{
    setlocale(LC_ALL, "");
    int opcao = 0;
    //Fun��o para carregar o vetor de sess�es no main

    char senha_adm[]={"123456"}, senha_aux[50];


    //cadastro da senha
    //printf("%s",senha_adm);

    //ingresso = arquivo_para_vetor_carregamento_do_programa(ingresso, &n);

    system("clear || cls ");
    printf("--------------------------------------------------\n");
    printf("-----O qu� voc� quer fazer no programa ?-----\n--------------------------------------------------\n\n-1) Entrar no Cinema Virtual Quixad�\n\n-2) Administrar as sess�es e dados do programa(requer senha)\n\n-3) Sair\n\n");
    opcao = menu_inicial();
    while (opcao <= 3 && opcao >= 0)
    {
        switch (opcao)
        {
        case 1:
            system("clear || cls ");
            programa_cinema_virtual();
            return 0;

        case 2:
            system("clear || cls ");
            printf("-----Sistema de Gerenciamento de Sess�es-----\n\n\n");
            printf("\nDigite a senha: ");
            scanf(" %[^\n]", senha_aux);
            if ((strcmp(senha_aux, senha_adm)) == 0)
            {
                system("clear || cls ");
                gerenciamento_sessoes();
                opcao = 0;
                //printf("Fechamento do programa autom�tico, necess�rio para salvar as sess�es, reabra o programa quando fechar");
                return 0;
            }

            else
            {
                system("clear || cls ");
                printf("\n\nVoc� errou a senha\n\n");
                opcao = 0;
                break;
            }
        case 3:

            return 0;
        default:
            printf("--------------------------------------------------\n");
            printf("-----O que voc� quer fazer no programa ?-----\n--------------------------------------------------\n\n-1) Entrar no Cinema Virtual Quixad�\n\n-2) Administrar as sess�es e dados do programa(requer senha)\n\n-3) Sair\n\n");
            opcao = menu_inicial();
        }
    }

    return 0;
}
