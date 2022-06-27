#include "cuidador.h"

struct cuidador{
    int latitude;
    int longitude;
    char* nome;
};

Cuidador* cria_cuidador(){
    Cuidador* cuidador = (Cuidador*)malloc(sizeof(Cuidador));
    cuidador->latitude = 0;
    cuidador->longitude = 0;
    cuidador->nome = NULL;

    return cuidador;
}

void set_latitude_cuidador(Cuidador* cuidador, int latitude){
    cuidador->latitude = latitude;
}

void set_longitude_cuidador(Cuidador* cuidador, int longitude){
    cuidador->longitude = longitude;
}

void set_nome_cuidador(Cuidador* cuidador, char* nome){
    cuidador->nome = strdup(nome);
}

void imprime_cuidador(Cuidador* cuidador){
    printf("\nNome: %s\nLat: %d\nLong: %d\n", cuidador->nome, cuidador->latitude, cuidador->longitude);
}

void libera_cuidador(Cuidador* cuidador){
    
}