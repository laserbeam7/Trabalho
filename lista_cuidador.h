#ifndef LISTA_CUIDADOR_H_
#define LISTA_CUIDADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuidador.h"

typedef struct lista_cuidador ListaCuidador;
typedef struct no No;

ListaCuidador* inicializa_lista_cuidador();
void insere_lista_cuidador(Cuidador* cuidador, ListaCuidador* lista);
void imprime_lista_cuidador(ListaCuidador* lista);
void libera_lista_cuidador(ListaCuidador *lista);
#endif /*LISTA_CUIDADOR_H_*/