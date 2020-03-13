#ifndef CINEMA_H
#define CINEMA_H

#include "compartilhadas.h"

void inicio();
void depois_do_inicio();
void inicio_erro();
int menu_loja_virtual_quixada();
int printar_sessao_compra(sessao *v, vetor_cadeiras_da_sessao *aux, int *n, int sessao_aux);
int checar_compra_id(sessao *v, vetor_cadeiras_da_sessao *aux, int n, int sessao_aux);
void checar_compra(sessao *v, vetor_cadeiras_da_sessao *aux, int *n);
vetor_cadeiras_da_sessao *ler_pedido_e_salvar_no_vetor(vetor_cadeiras_da_sessao *aux, sessao *v, int *n);
vetor_cadeiras_da_sessao *comprar_ingresso(vetor_cadeiras_da_sessao *aux, sessao *v, int *n);
void programa_cinema_virtual();

#endif
