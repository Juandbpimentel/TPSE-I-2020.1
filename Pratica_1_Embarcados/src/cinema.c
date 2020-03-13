#include "cinema.h"
#include "compartilhadas.h"
//Funções de compra de ingressos.

    //Texto do menu da loja.
    void inicio()
    {
        printf("\n\n\n-------------------------------------------------\n");
        printf("|           Bem vindo ao Cinema-Online !        |\n");
        printf("-------------------------------------------------\n\n\n");

        printf("-------------------------------------------------\n");
        printf("|           O que deseja senhor(a)?             |\n");
        printf("-------------------------------------------------\n");
        printf("|        1 - Comprar ingressos                  |\n");
        printf("-------------------------------------------------\n");
        printf("|        2 - Checar compra                      |\n");
        printf("-------------------------------------------------\n");
        printf("|        3 - Sair                               |\n");
        printf("-------------------------------------------------\n");
    }

    //fun��oo para repetir o menu sem o bem-vindo.
    void depois_do_inicio()
    {
        printf("\n\n\n-------------------------------------------------\n");
        printf("|               Menu Principal                  |\n");
        printf("-------------------------------------------------\n\n\n");

        printf("-------------------------------------------------\n");
        printf("|           O que deseja senhor(a)?             |\n");
        printf("-------------------------------------------------\n");
        printf("|        1 - Comprar ingressos                  |\n");
        printf("-------------------------------------------------\n");
        printf("|        2 - Checar compra                      |\n");
        printf("-------------------------------------------------\n");
        printf("|        3 - Sair                               |\n");
        printf("-------------------------------------------------\n");
    }

    //Texto do menu após um erro (operação escolhida n�o � nunhuma das do menu).
    void inicio_erro()
    {

        printf("\n\n\n-------------------------------------------------\n");
        printf("|      Op��o inv�lida, escolha novamente !      |\n");
        printf("-------------------------------------------------\n\n\n");

        printf("-------------------------------------------------\n");
        printf("|           O que deseja senhor(a)?             |\n");
        printf("-------------------------------------------------\n");
        printf("|        1 - Comprar ingressos                  |\n");
        printf("-------------------------------------------------\n");
        printf("|        2 - Checar compra                      |\n");
        printf("-------------------------------------------------\n");
        printf("|        3 - Sair                               |\n");
        printf("-------------------------------------------------\n");
    }

    //Input da escolha de operação do usuário, sendo com char.
    int menu_loja_virtual_quixada()
    {
        char operacao[100];
        int a = 0;

        printf("----------------Digite sua op��o:----------------\n\n");
        printf("1/2/3: ");

        scanf(" %[^\n]", operacao);

        a = (int)operacao[0] - (int)'0';

        return a;
    }

    int printar_sessao_compra(sessao *v, vetor_cadeiras_da_sessao * aux, int *n, int sessao_aux )
    {
        for (int i = 0; i < *n ; i++)
            v[i].v2 = malloc(v[i].ingressos * sizeof(vetor_cadeiras_da_sessao));

        for (int i = 0, l = 0; i < *n; i++)
            for (int k = 0; k < v[i].ingressos; k++, l++)
                v[i].v2[k] = aux[l];

        for (int i = 0; i < *n; i++)
        {
            if ( i == sessao_aux )
            {
                printf("\n\n\n----------Mapa da Sess�o----------");
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
                return v[i].id_sessao;
            }
        }
        return 0;
    }

    int checar_compra_id(sessao *v, vetor_cadeiras_da_sessao * aux, int n, int sessao_aux )
    {
        for (int i = 0; i < n ; i++)
        {
            v[i].v2 = malloc(v[i].ingressos * sizeof(vetor_cadeiras_da_sessao));
        }

        for (int i = 0, l = 0; i < n; i++)
            for (int k = 0; k < v[i].ingressos; k++, l++)
                v[i].v2[k] = aux[l];
        for (int i = 0; i < n; i++)
        {
            if ( i == sessao_aux )
            {
                return v[i].id_sessao;
            }

        }

        return -1;
    }

    void checar_compra(sessao *v, vetor_cadeiras_da_sessao *aux,int *n)
    {
        //Carregar os ingressos;
            for (int i = 0; i < *n; i++)
            {
                v[i].v2 = realloc(v[i].v2,v[i].ingressos * sizeof(vetor_cadeiras_da_sessao));
                if(v[i].v2==0)
                {
                    printf("Erro, Mem�ria cheia, Tente abrir o programa de novo");
                    return;
                }
            }

            for (int i = 0, m=0; i < *n; i++)
                    for (int k = 0; k < v[i].ingressos ; k++,m++)
                        v[i].v2[k] = aux[m] ;



            int escolha_sessao=0,id_aux=0,achou1=0,achou2=0;
            char cpf[100];
            printf("   Qual � o seu CPF ?  ");
            scanf(" %[^\n]", cpf);

            system("clear || cls");

            printf("   Sess�es De Agora :\n\n");
            for (int i = 0; i < *n; i++)
            printf("   %d-)Nome da sess�o: %s\n", i,v[i].nome_da_sessao);

            printf("\n   Qual � a sua sess�o(escolha o n�mero da op��o): ");

            scanf(" %d",&escolha_sessao);

            system("clear || cls");

            id_aux = checar_compra_id(v,aux,*n,escolha_sessao);

            while(id_aux == -1)
            {
                system("clear || cls");
                printf("Sess�o n�o encontrada, Tente novamente");
                printf("   Sess�es Dispon�veis :\n\n");
                for (int i = 0; i < *n; i++)
                printf(" %d-)Nome da sess�o: %s\n", i,v[i].nome_da_sessao);

                printf("\n\n Escolha o n�mero da op��o que � o filme que voc� quer assistir: ");

                scanf(" %d",&escolha_sessao);
                system("clear || cls");

                id_aux = checar_compra_id(v,aux,*n,escolha_sessao);
            }

            for (int i = 0, m=0; i < *n; i++)
                for (int k = 0; k < v[i].ingressos; k++,m++)
                    if( (aux[m].id == id_aux) && ((strcmp(aux[m].cpf,cpf))==0) )
                    {
                        achou1 = 1;
                        for (int l = 0; l < *n ; l++)
                        {
                            if(id_aux == v[l].id_sessao)
                            {
                                for (int j = 0, w = v[l].ingressos; j < v[l].ingressos; j++, w--)
                                {
                                    if ((strcmp(cpf,v[l].v2[j].cpf))==0 )
                                    {
                                        achou2 = 1;
                                        //printf("\n\n\n>>>>>>>>>>> Sess�o : %s <<<<<<<<<<<<\n\n", v[i].nome_da_sessao);

                                        printf("   Um ingresso(s) foi achado U.U !\n\n");

                                        printf("   ------------------------------------------\n");

                                        if (w > 99 && w < 999)
                                        {
                                            printf("     -)N�mero da cadeira : %c%c%c\n", v[l].v2[j].numero[0], v[l].v2[j].numero[1], v[l].v2[j].numero[2]);
                                        }

                                        if (w >= 9 && w < 99)
                                        {
                                            printf("     -)N�mero da cadeira : %c%c\n", v[l].v2[j].numero[0], v[l].v2[j].numero[1]);
                                        }

                                        if (w < 9)
                                        {
                                            printf("     -)N�mero da cadeira : %c\n", v[l].v2[j].numero[0]);
                                        }

                                        printf("     -)Cpf do comprador  : %s\n", v[l].v2[j].cpf);
                                        if (v[l].v2[j].ocupada)
                                        {
                                            printf("     -)Ocupada\n");
                                        }
                                        else
                                        {
                                            printf("     -)Vazia\n");
                                        }

                                        if (v[l].v2[j].inteira_ou_meia == 1)
                                        {
                                            printf("     -)Inteira\n");
                                        }

                                        else
                                        {
                                            printf("     -)Meia\n\n");
                                        }
                                        printf("\n   ------------------------------------------\n\n");

                                        if(j == ( (v[l].ingressos)-1 ) )
                                        {
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                        return;
                    }

            if(achou1 == 0 )
            {
                if(achou2 == 0)
                {
                    system("clear || cls");
                    printf("   Ingresso n�o encontrado.\n\n");
                    return;
                }
                else
                {
                    system("clear || cls");
                    printf("   Ingresso encontrado, mas n�o nessa sess�o.\n\n");
                    return;
                }
            }
            else
            {
                return;

            }
}

    //Input de todas as informações do ingresso, ela � usada na função comprar.
    vetor_cadeiras_da_sessao* ler_pedido_e_salvar_no_vetor(vetor_cadeiras_da_sessao *aux, sessao* v, int *n)
    {
        //Carregar os ingressos;
            for (int i = 0; i < *n; i++)
            {
                v[i].v2 = malloc(v[i].ingressos * sizeof(vetor_cadeiras_da_sessao));
                if(v[i].v2==0)
                {
                    system("clear || cls");
                    printf("Erro, Mem�ria cheia, Tente abrir o programa de novo");
                    return aux;
                }

            }

            for (int i = 0, m=0; i < *n; i++)
                    for (int k = 0; k < v[i].ingressos ; k++,m++)
                        v[i].v2[k] = aux[m] ;


        vetor_cadeiras_da_sessao novo;
        int escolha_sessao=0,id_aux=0;
        char escolha_cadeira[6];
        printf("   Qual � o seu CPF ? :");
        scanf(" %[^\n]", novo.cpf);

        system("clear || cls");

        printf("   Sess�es Dispon�veis :\n\n");
        for (int i = 0; i < *n; i++)
        printf("   %d-)Nome da sess�o: %s\n", i,v[i].nome_da_sessao);

        printf("\n\n   Escolha o n�mero da op��o que � o filme que voc� quer assistir: ");

        scanf(" %d",&escolha_sessao);

        system("clear || cls");

        id_aux = printar_sessao_compra(v,aux,n,escolha_sessao);

        while(id_aux == 0)
            {
                system("clear || cls");
                printf("   Sess�o n�o encontrada, Tente novamente");
                printf("   Sess�es Dispon�veis :\n\n");
                for (int i = 0; i < *n; i++)
                printf("   %d-)Nome da sess�o: %s\n", i,v[i].nome_da_sessao);

                printf("\n\n   Escolha o n�mero da op��o que � o filme que voc� quer assistir: ");

                scanf(" %d",&escolha_sessao);

                id_aux = printar_sessao_compra(v,aux,n,escolha_sessao);
            }

            novo.id = id_aux;
            printf("   Qual cadeira voc� quer ? :");
            scanf(" %[^\n]", escolha_cadeira);
            system("clear || cls");
                for (int i = 0; i < *n; i++)
                {
                    for (int k = 0; k < v[i].ingressos; k++)
                        if (novo.id == v[i].id_sessao && (strcmp(v[i].v2[k].numero, escolha_cadeira)) == 0)
                        {
                            if (v[i].v2[k].ocupada == 0)
                            {
                                strcpy(novo.numero, v[i].v2[k].numero);
                                novo.ocupada = 1;
                                printf("   Inteira ou Meia (Digite 1 para Inteira e 0 para Meia)? :");
                                scanf(" %d", &novo.inteira_ou_meia);

                                v[i].v2[k] = novo;

                                for (int z = 0, m = 0; z < *n; z++)
                                    for (int w = 0; w < v[z].ingressos; w++, m++)
                                        aux[m] = v[z].v2[w];

                                system("clear || cls");
                                printf("------------------------------------------------------\n");
                                printf("| Compra finalizada, cadastro de ingresso registrado |\n");
                                printf("------------------------------------------------------\n\n\n");
                                return aux;
                            }

                            else if(k == ((v[i].ingressos)-1) )
                            {
                                system("clear || cls");
                                printf("   N�o foi poss�vel comprar sua cadeira pois ela j� est�o ocupada ou n�o existe na sess�o. Quando for comprar de novo escolha uma cadeira que n�o tenha um x marcado.\n\n");
                                return aux;
                            }
                        }
                    }
        return aux;
    }

    //op��o de compra de ingressos da interface de usuário.
    vetor_cadeiras_da_sessao* comprar_ingresso(vetor_cadeiras_da_sessao *aux,sessao* v, int *n)
    {
        int Q_ingressos, i;

        //Ver n�mero de ingressos que a pessoa quer comprar.
        printf("  Quantidade de ingressos: ");
        scanf("%d", &Q_ingressos);
        system("clear || cls");
        for (i = 0; i < Q_ingressos; i++)
        {

            //Ler o pedido
            printf("\n");
            printf("  Compra - Ingresso(s) %d:\n\n", i + 1);
            aux = ler_pedido_e_salvar_no_vetor(aux,v,n);

        }


        //for(int i=0; i<2140000000; i++);

        printf("\n\n\n\n\n");

        return aux;
    }

    void programa_cinema_virtual()
    {
    	setlocale(LC_ALL, "");
        int n = 0;

        sessao  *v = 0;
        vetor_cadeiras_da_sessao *aux = 0;

        v = arquivo_para_vetor_carregamento_do_programa_v(v, &n);
        aux = arquivo_para_vetor_carregamento_do_programa_aux(v, &n);


        //declarando variaveis que serão utilizadas en todo o programa como parametro e/ou ponteiro.
        int k = 0;
        int operacao_main = 0;
        system("clear || cls ");

        while (operacao_main <= 3 && operacao_main >= 0)
        {

            //Looping de funcionamento do programa enquanto n�o pedido o fechamento.

            //Checar a op��o do usuário e rodar ela se ela for uma op��o valida.
            switch (operacao_main)
            {
                case 1:
                {
                    if(n>0)
                    {
                        system("clear || cls ");
                        aux = comprar_ingresso(aux,v,&n);
                        operacao_main = 0;
                        break;
                    }
                    else
                    {
                        system("clear || cls ");
                        printf("Ainda n�o h� nenhuma sess�o cadastrada, desculpe o transtorno.");
                        operacao_main = 0;
                        break;
                    }
                }

                case 2:
                {
                    if(n>0)
                    {
                        system("clear || cls ");
                        checar_compra(v,aux,&n);
                        operacao_main = 0;
                        break;
                    }
                    else
                    {
                        system("clear || cls ");
                        printf("Ainda n�o h� nenhuma sess�o cadastrada, desculpe o transtorno.");
                        operacao_main = 0;
                        break;
                    }
                }

                case 3:
                {
                    system("clear || cls ");
                    printf("     ---------------------------------------       \n");
                    printf("     |              Ad�os ;-;              |       \n");
                    printf("     ---------------------------------------       \n");

                    sessao_para_arquivo(v,aux,n);

                    return;
                }

                default:
                {
                    if (k == 0)
                    {
                        inicio();
                        operacao_main = menu_loja_virtual_quixada();
                        k++;
                        while (operacao_main != 0 && operacao_main != 1 && operacao_main != 2 && operacao_main != 3)
                        {
                            operacao_main = 0;
                            inicio_erro();
                            operacao_main = menu_loja_virtual_quixada();
                        }
                        break;
                    }

                    depois_do_inicio();
                    operacao_main = menu_loja_virtual_quixada();

                    while (operacao_main != 0 && operacao_main != 1 && operacao_main != 2 && operacao_main != 3)
                    {
                        operacao_main = 0;
                        inicio_erro();
                        operacao_main = menu_loja_virtual_quixada();
                    }
                    break;
                }
            }
        }
        return;
    }
