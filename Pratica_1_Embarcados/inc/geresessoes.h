#ifndef GERESESSOES_H
#define GERESESSOES_H

#include "compartilhadas.h"

int menu_inicial_sessoes();
sessao *cadastro_sessao(sessao *v, int *n, int *randon_id);
vetor_cadeiras_da_sessao *cadastro_sessao_cadeiras(sessao *v, vetor_cadeiras_da_sessao *aux, int *n, int *randon_id);
vetor_cadeiras_da_sessao *remover_sessao(sessao *v, vetor_cadeiras_da_sessao *aux, int *n, int id);
void printar_sessao_individual_cadastro(sessao *v, vetor_cadeiras_da_sessao *aux, int *n);
void printar_todas_sessoes(sessao *v, vetor_cadeiras_da_sessao *aux, int *n);
int gerenciamento_sessoes();

#endif
