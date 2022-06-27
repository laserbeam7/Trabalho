#ifndef LISTA_IDOSO_H_
#define LISTA_IDOSO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "idoso.h"


typedef struct lista_idoso ListaIdoso;
typedef struct no No;

ListaIdoso* inicializa_lista_idoso();
void insere_lista_idoso(Idoso* paciente, ListaIdoso* lista);
void retira_lista_idoso(ListaIdoso* lista, Idoso* paciente);
void imprime_lista_idoso(ListaIdoso* lista);
void libera_lista_idoso(ListaIdoso* lista);
Idoso* get_idoso(ListaIdoso* lista, int n);
Idoso* get_idoso_ultima(ListaIdoso* lista);
int retorna_numero_idosos(ListaIdoso* lista);

#endif /*LISTA_IDOSO_H_*/