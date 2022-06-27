#ifndef ARQUIVOS_H_
#define ARQUIVOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "idoso.h"
#include "cuidador.h"
#include "lista_idoso.h"
#include "lista_cuidador.h"

typedef struct node Node;
typedef struct lista_circular ListaCircular;

FILE* abrir_arquivo(char* arquivo);
ListaCircular* inicializa_lista_circular(int num_pacientes);
void le_arquivo(FILE* arquivo);
ListaIdoso* le_arquivo_paciente(int n);
Cuidador* le_arquivo_cuidador(FILE *arquivo);
ListaIdoso* le_arquivo_apoio();
ListaCircular* abre_arquivo_idoso(ListaIdoso* lista);
char* prepara_nome_arquivo_idoso(char* nome);
void remove_enter(char * str);

#endif /*ARQUIVOS_H_*/