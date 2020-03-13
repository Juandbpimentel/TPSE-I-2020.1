#include "geresessoes.h"

//Fun��es para a cria��o se sess�es.

    int menu_inicial_sessoes()
    {
        char operacao[100];
        int a = 0;
        printf("\n\n1/2/3/4: ");

        scanf(" %[^\n]", operacao);

        a = (int)operacao[0] - (int)'0';

        return a;
    }

    /*int menu_gerenciamento_sessoes()
    {
        char operacao[100];
        int a = 0;
        printf("Bem vindo(a) ao menu de gerenciamento de sessoes");
        printf("O qu� voc� que fazer? :");
        printf("   1) Cadastrar nova sess�o");
        printf("   2-) Imprimir sess�es");
        printf("   3-)Sair");
        printf("");

        printf("----------------Digite sua op��o:----------------\n\n");
        printf("1/2/3: ");

        scanf(" %[^\n]", operacao);

        a = (int)operacao[0] - (int)'0';

        return a;
    }*/

    sessao* cadastro_sessao(sessao* v, int* n,int *randon_id)
    {
        printf("\n--------------------Cadastrador de sess�es--------------------\n\n\n");

        if(*n>0)
        {
            v = realloc( v , (*n+1) * (sizeof(sessao)) );
        }

        else
        {
            v = malloc((*n+1) * (sizeof(sessao) ) );
        }

        if(v==0)
        {
            printf("Deu erro");
            return v;
        }

        srand( (unsigned)time(NULL) );
        v[*n].id_sessao = rand();
        *randon_id = v[*n].id_sessao;
        printf("\n Qual � o nome da %d� sess�o : ", (*n + 1));
        scanf(" %[^\n]", v[*n].nome_da_sessao);

        printf("\n Qual � o tamanho das fileiras da %d� sess�o : ", (*n + 1));
        scanf(" %d", &v[*n].tamanho_das_fileiras);

        printf("\n Quantas cadeiras tem na %d� sess�o : ", (*n + 1));
        scanf(" %d", &v[*n].ingressos);

        return v;

    }

    vetor_cadeiras_da_sessao* cadastro_sessao_cadeiras(sessao *v, vetor_cadeiras_da_sessao*aux, int* n,int *randon_id )
    {
        char abc = 0;
        for (int i = 0; i < *n+1; i++)
        {
            v[i].v2 = realloc(v[i].v2, (v[i].ingressos) * sizeof(vetor_cadeiras_da_sessao) );
        }

        if(v[*n].v2==0)
        {
            printf("Erro, Memória cheia, Tente abrir o programa de novo");
            return aux;
        }

        for (int i = 0, m=0; i < *n; i++)
                for (int k = 0; k < v[i].ingressos ; k++,m++)
                    v[i].v2[k] = aux[m] ;


        for (int j = 0 ; j < v[*n].ingressos; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                v[*n].v2[j].numero[k] = 0;
            }

            for (int k = 0; k < 100; k++)
            {
                v[*n].v2[j].cpf[k] = 0;
            }

            v[*n].v2[j].ocupada = 0;
            v[*n].v2[j].id = *randon_id;
            v[*n].v2[j].inteira_ou_meia = 0;
        }



        for (int k=0 , j = (v[*n].ingressos)-1 ; j >= 0  ; j--,k++)
        {
            if (k+1<=9)
            {
                v[*n].v2[j].numero[0] = ((k+1)%10)+'0';
            }

            else if((k+1)>=10 && (k+1)<100)
            {
                v[*n].v2[j].numero[0] = ((k+1)/10)+'0';
                v[*n].v2[j].numero[1] = ((k+1)%10) +'0';
            }

            else if((k+1)>=100 &&(k+1)<1000)
            {
                v[*n].v2[j].numero[0] = (((k+1)/100)%10)+'0';
                v[*n].v2[j].numero[1] = (((k+1)/10)%10)+'0';
                v[*n].v2[j].numero[2] = (((k+1)%100)%10)+'0';
            }

            else if( (k+1)>=1000&&(k+1)<10000 )
            {
                v[*n].v2[j].numero[0] = (((k+1)/1000)%10)+'0';
                v[*n].v2[j].numero[1] = (((k+1)/100)%10)+'0';
                v[*n].v2[j].numero[2] = (((k+1)/10%10))+'0';
                v[*n].v2[j].numero[3] = ((((k+1)%1000)%100)%10)+'0';
            }

            v[*n].v2[j].cpf[0]  = 'x' ;
        }


        *n = *n+1;
        int l = 0;

        for (int i = 0; i < *n; i++)
            l += v[i].ingressos;

        aux = realloc( aux , l * sizeof(vetor_cadeiras_da_sessao) );

        if(aux==0){ printf("Deu merda"); return 0; }

        for (int i = *n-1, m = l-v[*n-1].ingressos; i < *n; i++)
            for (int k = 0; k < v[i].ingressos ; k++,m++)
                aux[m] = v[i].v2[k] ;
        system("clear || cls ");
        printf("\n\n\n Cadastro realizado com sucesso\n");

        printf(" Quer ver o mapeamento da sala? S|N: ");
        scanf(" %c", &abc);

        system("clear || cls ");
        if ((abc == 's') || (abc =='S'))
        {
            printar_sessao_individual_cadastro(v,aux,n);
            return aux;
        }

        else
        {
            printf("\n\n Tudo certo ent�o, cadastro finalizado\n\n\n");
            return aux;
        }

        return aux;
    }

    vetor_cadeiras_da_sessao* remover_sessao(sessao *v, vetor_cadeiras_da_sessao*aux, int* n,int id)
    {
        int achou = 0;
        //Carregar os ingressos;
            for (int i = 0; i < *n; i++)
            {
                v[i].v2 = malloc(v[i].ingressos * sizeof(vetor_cadeiras_da_sessao));
                if(v[i].v2==0)
                {
                    system("clear || cls ");
                    printf("Erro, Memória cheia, Tente abrir o programa de novo");
                    return aux;
                }

            }
            for (int i = 0, m=0; i < *n; i++)
                    for (int k = 0; k < v[i].ingressos ; k++,m++)
                        v[i].v2[k] = aux[m] ;

        for ( int i = 0, t_ingr = 0 ; i < *n ; i++ )
        {
            if(i==id)
            {
                achou = 1 ;
                if(*n>1)
                {
                    v[i] = v[*n - 1];
                    v[i].v2 = v[*n - 1].v2;
                    srand( (unsigned)time(NULL) );
                    v[i].id_sessao = rand();
                    for (int k = 0; k < v[i].ingressos; k++)
                    {
                        v[i].v2[k].id = v[i].id_sessao;
                    }
                    for(int i = 0; i < *n-1 ; i++)
                    {
                        t_ingr += v[i].ingressos;
                    }
                    *n = *n - 1;

                        aux = realloc(aux,t_ingr*sizeof(vetor_cadeiras_da_sessao) );
                        v = realloc(v,(*n)*sizeof(vetor_cadeiras_da_sessao) );
                    break;
                }

                if(*n==1)
                {
                    aux = 0;
                    v = 0;
                    *n = 0;
                    break;
                }
            }
        }

        if(*n>=1)
            for (int i = 0, m=0; i < *n; i++)
                for (int k = 0; k < v[i].ingressos ; k++,m++)
                aux[m] = v[i].v2[k];

        if(achou == 1)
        {
            system("clear || cls ");
            printf("\nSess�o e ingressos removidos com sucesso!\n\n");
        }

        if (achou == 0)
        {
            system("clear || cls ");
            printf("\nSess�o n�o encontradas.\n\n");
        }

        return aux;
    }

    void printar_sessao_individual_cadastro(sessao *v, vetor_cadeiras_da_sessao * aux, int *n)
    {

        v[*n - 1].v2 = malloc( v[*n-1].ingressos * sizeof(vetor_cadeiras_da_sessao));

        for (int i = 0, l = 0; i < *n; i++)
        {
            for (int k = 0; k < v[i].ingressos; k++, l++)
            {
                v[i].v2[k] = aux[l];
            }
        }

            printf("\n\n\n----------Mapa da Sess�o----------");

            printf("\n\n\n>>>>>>>>>>> Sess�o : %s <<<<<<<<<<<<\n\n",v[*n-1].nome_da_sessao);
            for (int j = 0,k = v[*n-1].ingressos; j < v[*n-1].ingressos; j++,k--)
            {
                if(k>99&&k<999)
                {
                    printf("[ %c%c%c ] " , v[*n-1].v2[j].numero[0], v[*n-1].v2[j].numero[1], v[*n-1].v2[j].numero[2]);
                }

                if(k>=9&&k<=99)
                {
                    printf("[ %c%c  ] " , v[*n-1].v2[j].numero[0], v[*n-1].v2[j].numero[1]);
                }

                if(k<9)
                {
                    printf("[  %c  ] " , v[*n-1].v2[j].numero[0]);
                }

                if((j+1)%v[*n-1].tamanho_das_fileiras==0)
                    printf("\n\n");
            }

            printf("\n\n\n---Lista de Ingressos da Sess�e---\n\n\n");


            printf("\n\n\n>>>>>>>>>>> Sess�o : %s <<<<<<<<<<<<\n\n",v[*n-1].nome_da_sessao);
            for (int j = 0,k = v[*n-1].ingressos; j < v[*n-1].ingressos; j++,k--)
            {
                printf("\n  -)Cadeira %d)\n", k);

                if(k>99&&k<999)
                {
                    printf("     -)N�mero da cadeira : %c%c%c\n" , v[*n-1].v2[j].numero[0], v[*n-1].v2[j].numero[1], v[*n-1].v2[j].numero[2]);

                }

                if(k>=9&&k<99)
                {
                    printf("     -)N�mero da cadeira : %c%c\n" , v[*n-1].v2[j].numero[0], v[*n-1].v2[j].numero[1]);

                }

                if(k<9)
                {
                    printf("     -)N�mero da cadeira : %c\n" , v[*n-1].v2[j].numero[0]);
                }


                printf("     -)cpf do comprador  : %s\n", v[*n-1].v2[j].cpf);
                if (v[*n-1].v2[j].ocupada)
                {
                    printf("     -)Ocupada\n");
                }
                else
                {
                    printf("     -)Vazia\n");
                }

                if (v[*n-1].v2[j].inteira_ou_meia==0)
                {
                    printf("     -)Sem Classifica��o\n\n\n");
                }

                else if (v[*n-1].v2[j].inteira_ou_meia==1)
                {
                    printf("     -)Inteira\n\n\n");
                }

                else
                {
                    printf("     -)Meia\n\n\n");
                }
            }
        return;
    }

    void printar_todas_sessoes(sessao *v, vetor_cadeiras_da_sessao * aux, int *n)
    {

        for (int i = 0; i < *n ; i++)
            v[i].v2 = malloc(v[i].ingressos * sizeof(vetor_cadeiras_da_sessao));

        for (int i = 0, l = 0; i < *n; i++)
        {
            for (int k = 0; k < v[i].ingressos; k++, l++)
                v[i].v2[k] = aux[l];
        }

            printf("\n\n\n----------Mapa das Sess�es Cadastradas----------");
            for (int i = 0; i < *n ; i++)
            {
                printf("\n\n\n>>>>>>>>>>> Sess�o : %s <<<<<<<<<<<<\n\n", v[i].nome_da_sessao);
                for (int j = 0, k = v[i].ingressos; j < v[i].ingressos; j++, k--)
                {
                    if (k > 99 && k < 999)
                    {
                        if (v[i].v2[j].ocupada == 0)
                        {
                            printf("[ %c%c%c ] ", v[i].v2[j].numero[0], v[i].v2[j].numero[1], v[i].v2[j].numero[2]);
                        }
                        else
                            printf("[  x  ]");
                    }

                    if (k >= 9 && k <= 99)
                    {
                        if (v[i].v2[j].ocupada == 0)
                        {
                            printf("[ %c%c  ] ", v[i].v2[j].numero[0], v[i].v2[j].numero[1]);
                        }
                        else
                            printf("[  x  ]");
                    }

                    if (k < 9)
                    {
                        if (v[i].v2[j].ocupada == 0)
                        {
                            printf("[  %c  ] ", v[i].v2[j].numero[0]);
                        }
                        else
                            printf("[  x  ]");
                    }

                    if ((j + 1) % v[i].tamanho_das_fileiras == 0)
                        printf("\n\n");
                }
            }
            printf("\n\n\n---Lista de Ingressos da Sess�e---\n\n\n");
            for (int i = 0; i < *n ; i++)
            {

                printf("\n\n\n>>>>>>>>>>> Sess�o : %s <<<<<<<<<<<<\n\n", v[i].nome_da_sessao);
                for (int j = 0, k = v[i].ingressos; j < v[i].ingressos; j++, k--)
                {
                    printf("\n  -)Cadeira %d)\n", k);

                    if (k > 99 && k < 999)
                    {
                        printf("     -)N�mero da cadeira : %c%c%c\n", v[i].v2[j].numero[0], v[i].v2[j].numero[1], v[i].v2[j].numero[2]);
                    }

                    if (k >= 9 && k < 99)
                    {
                        printf("     -)N�mero da cadeira : %c%c\n", v[i].v2[j].numero[0], v[i].v2[j].numero[1]);
                    }

                    if (k < 9)
                    {
                        printf("     -)N�mero da cadeira : %c\n", v[i].v2[j].numero[0]);
                    }

                    printf("     -)cpf do comprador  : %s\n", v[i].v2[j].cpf);
                    if (v[i].v2[j].ocupada)
                    {
                        printf("     -)Ocupada\n");
                    }
                    else
                    {
                        printf("     -)Vazia\n");
                    }

                    if (v[i].v2[j].inteira_ou_meia == 0)
                    {
                        printf("     -)Sem Classifica��o\n\n\n");
                    }

                    else if (v[i].v2[j].inteira_ou_meia == 1)
                    {
                        printf("     -)Inteira\n\n\n");
                    }

                    else
                    {
                        printf("     -)Meia\n\n\n");
                    }
                }
            }
        return;
    }

    int gerenciamento_sessoes()
    {
    	setlocale(LC_ALL, "");
        int n=0, id=0 ,randon_id=0 ;

        sessao *sessao_atual = 0;
        vetor_cadeiras_da_sessao *ingressos_aux = 0;

        sessao_atual=arquivo_para_vetor_carregamento_do_programa_v(sessao_atual, &n);
        ingressos_aux=arquivo_para_vetor_carregamento_do_programa_aux(sessao_atual, &n);

        int opcao = 0;
        system("clear || cls ");
        printf("-----Sistema de Gerenciamento de Sess�es-----\n\n\n");
        while (opcao <= 4 && opcao >= 0)
        {
            switch (opcao)
            {
            case 1:
                system("clear || cls ");
                sessao_atual = cadastro_sessao(sessao_atual,&n,&randon_id);
                ingressos_aux = cadastro_sessao_cadeiras(sessao_atual, ingressos_aux, &n,&randon_id);
                opcao = 0;
                break;

            case 2:
                if(n>0)
                {
                    system("clear || cls ");
                    printf("Escolha a sess�o que quer remover:\n\n");
                    for (int i = 0; i < n; i++)
                        printf("%d-)Id da Sess�o: %d | Nome da sess�o: %s\n", i,sessao_atual[i].id_sessao,sessao_atual[i].nome_da_sessao);

                    printf("\n\nQual sess�o quer remover(Digite o n�mero da op��o e n�o o id): ");

                    scanf("%d", &id);

                    ingressos_aux = remover_sessao(sessao_atual, ingressos_aux, &n, id);

                    opcao = 0;
                }

                else
                {
                    system("clear || cls ");
                    printf("N�o h� nenhuma sess�o para remover.\n\n");
                    opcao = 0;
                }

                break;

            case 3:
            system("clear || cls ");
            if(n>0)
                printar_todas_sessoes(sessao_atual, ingressos_aux, &n);
            else
            {
                printf("Ainda n�o h� nenhuma sess�o cadastrada.\n\n");
            }

                opcao = 0;
                break;

            case 4:
            system("clear || cls ");
                printf("\n\n     ---------------------------------------       \n");
                    printf("     |              Ad�os ;-;              |       \n");
                    printf("     ---------------------------------------       \n");
                sessao_para_arquivo(sessao_atual, ingressos_aux, n);

                return 0;
                break;

            default:
                {
                    printf("--------------------------------------------------\n");
                    printf("-----O que voc� quer fazer no programa ?-----\n--------------------------------------------------\n\n-1) Cadastrar Sess�o\n\n-2) Remover Sess�o\n\n-3) Imprimir todas as sess�es\n\n-4) Sair\n\n\n\n");
                    opcao = menu_inicial_sessoes();

                    while(opcao!=4&&opcao!=3&&opcao!=2&&opcao!=1&&opcao!=0)
                    {
                        system("clear || cls ");
                        printf("Op��o inv�lida! Digite uma opcao v�lida.\n\n");
                        printf("--------------------------------------------------\n");
                        printf("-----O que voc� quer fazer no programa ?-----\n--------------------------------------------------\n\n-1) Cadastrar Sess�o\n\n-2) Remover Sess�o\n\n-3) Imprimir todas as sess�es\n\n-3) Sair\n\n\n\n");
                        opcao = menu_inicial_sessoes();
                    }
                }
            }
        }
        return 0;
    }
