#ifndef COMPARTILHADAS_H
#define COMPARTILHADAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//cadastro de sessoes(Cadeiras).
    typedef struct vetor_cadeiras_da_sessao
    {
        int id;
        char numero[6];
        char cpf[100];
        int ocupada;
        int inteira_ou_meia;

    } vetor_cadeiras_da_sessao;
    //cadastro de sessoes(Salas).
    typedef struct sessao_nome
    {
        int id_sessao;
        char nome_da_sessao[100];
        int tamanho_das_fileiras;
        int ingressos;
        vetor_cadeiras_da_sessao* v2;
    } sessao;


int menu_inicial();
vetor_cadeiras_da_sessao *arquivo_para_vetor_carregamento_do_programa_aux(sessao *v, int *n);
sessao *arquivo_para_vetor_carregamento_do_programa_v(sessao *v, int *n);
void sessao_para_arquivo(sessao *sessoes, vetor_cadeiras_da_sessao *aux, int n);

#endif
