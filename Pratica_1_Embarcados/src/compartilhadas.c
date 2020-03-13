#include "compartilhadas.h"


//Fun��es universáis(Glória a DeuXXXXXXXX).

    //texto do menu de programa.
    int menu_inicial()
    {
    	setlocale(LC_ALL, "");
        char operacao[100];
        int a = 0;

        printf("----------------Digite sua op��o:----------------\n\n");
        printf("1/2/3: ");

        scanf(" %[^\n]", operacao);

        a = (int)operacao[0] - (int)'0';

        return a;
    }

    vetor_cadeiras_da_sessao* arquivo_para_vetor_carregamento_do_programa_aux( sessao *v , int *n)
    {
        vetor_cadeiras_da_sessao *aux2 =  0;

        FILE *f = fopen("ingressos.txt", "r");
        FILE *g = fopen("n_sessoes.txt", "r");

        if (f == 0|| g==0)
        {
            return 0;
        }

        int a = 0,z=0;

        fscanf(g, "%d", &a );

        for (int i = 0 ; i < *n ; i++)
        {
            z += v[i].ingressos;
        }

        for (int j = 0 , l=0 ; j < *n; j++)
        {
            fscanf(g, " %d %[^\n] %d %d", &v[j].id_sessao, v[j].nome_da_sessao, &v[j].tamanho_das_fileiras, &v[j].ingressos);
            for (int k = 0; k < v[j].ingressos; k++, l++)
            {

                aux2 = realloc(aux2,(z) * sizeof(vetor_cadeiras_da_sessao));
                if (aux2 == 0)
                {
                    printf("Erro ao recarregar informa��es do arquivo, favor reiniciar o programa.");
                    return 0;
                }
                fscanf(f, " %d %[^\n] %[^\n] %d %d", &aux2[l].id, aux2[l].numero, aux2[l].cpf, &aux2[l].ocupada, &aux2[l].inteira_ou_meia);
            }
        }

        return aux2;
    }

    sessao* arquivo_para_vetor_carregamento_do_programa_v( sessao *v , int *n)
    {
        FILE *f = fopen("ingressos.txt", "r");
        FILE *g = fopen("n_sessoes.txt", "r");
        if (f == 0|| g==0)
        {
            printf("<13021302>\n\n\n");
            return 0;
        }

        int l = 0, a = 0;

        fscanf(g, "%d", &a );
        *n = a;

        v = malloc(*n * (sizeof(sessao)));
        if (f == 0|| g==0)
        {
            printf("<<<<<<<<<<<<<<<<<<<<13021302>>>>>>>>>>>>>>>>>>>>\n\n\n");
            return 0;
        }

        for (int j = 0; j < *n; j++, l++)
            fscanf(g, " %d %[^\n] %d %d", &v[j].id_sessao, v[j].nome_da_sessao, &v[j].tamanho_das_fileiras, &v[j].ingressos);
        return v;
    }

    //Guardar dados dos ingressos em um arquivo.
    void sessao_para_arquivo(sessao *sessoes,vetor_cadeiras_da_sessao *aux, int n)
    {
        FILE *f = fopen("ingressos.txt", "w");
        FILE *g = fopen("n_sessoes.txt", "w");

        if (f == 0|| g==0)
        {
            printf("Erro ao abrir arquivo para salvar ingressos, favor reiniciar o programa.");
            return;
        }

        //int com o número de sess�es de numero de sess�es
        fprintf(g, "%d\n", n );



        int l = 0;
        for (int i = 0; i < n; i++)
        {
            fprintf(g, "%d\n", sessoes[i].id_sessao );

            fprintf(g, "%s\n", sessoes[i].nome_da_sessao );

            fprintf(g, "%d\n", sessoes[i].tamanho_das_fileiras );

            fprintf(g, "%d\n", sessoes[i].ingressos );

            for (int k = 0 ; k < sessoes[i].ingressos; k++,l++)
                fprintf(f, "\n\n%d\n%s\n%s\n%d\n%d\n\n", aux[l].id,aux[l].numero,aux[l].cpf,aux[l].ocupada,aux[l].inteira_ou_meia );
        }

        fclose(f);
        fclose(g);
        return;
    }
