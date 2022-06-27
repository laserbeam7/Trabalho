#ifndef CUIDADOR_H_
#define CUIDADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cuidador Cuidador;

Cuidador* cria_cuidador();

void set_latitude_cuidador(Cuidador* cuidador, int latitude);

void set_longitude_cuidador(Cuidador* cuidador, int longitude);

void set_nome_cuidador(Cuidador* cuidador, char* nome);

void imprime_cuidador(Cuidador* cuidador);

void libera_cuidador(Cuidador* cuidador);

#endif /*CUIDADOR_H_*/