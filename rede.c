#include "rede.h"

struct rede{
    ListaIdoso* amigo;
    ListaCuidador* cuidadores;
};

Rede* cria_rede(){
    Rede* apoio = (Rede*)malloc(sizeof(Rede));
    apoio->amigo = inicializa_lista_idoso();
    apoio->cuidadores = inicializa_lista_cuidador();

    return apoio;
}

void insere_rede(ListaIdoso* lista_idoso, ListaCuidador* lista_cuidadores){

}

void retira_rede(ListaIdoso* lista_idoso);