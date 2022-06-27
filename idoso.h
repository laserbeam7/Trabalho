#ifndef IDOSO_H_
#define IDOSO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct idoso Idoso;

Idoso* cria_idoso();

void set_temperatura_idoso(Idoso* paciente, float temperatura);

void set_latitude_idoso(Idoso* paciente, int latitude);

void set_longitude_idoso(Idoso* paciente, int longitude);

void set_queda_idoso(Idoso* paciente, int queda);

void set_nome_idoso(Idoso* paciente, char* nome);

void set_nome_arquivo_idoso(Idoso* paciente, char* nome_arquivo);

void set_faleceu_idoso(Idoso* paciente);

void imprime_idoso(Idoso* paciente);

void libera_idoso(Idoso* paciente);

void checa_gravidade(Idoso* paciente);

char* get_nome_idoso(Idoso* paciente);

char* get_arquivo_idoso(Idoso* paciente);

#endif /*IDOSO_H_*/