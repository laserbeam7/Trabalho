#include "lista_cuidador.h"

struct no
{
    Cuidador *cuidador;
    No *prox;
};

struct lista_cuidador
{
    No *primeira;
    No *ultima;
};

ListaCuidador *inicializa_lista_cuidador()
{
    ListaCuidador *lista = (ListaCuidador *)malloc(sizeof(ListaCuidador));
    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

void insere_lista_cuidador(Cuidador *cuidador, ListaCuidador *lista)
{
    No *celula = (No *)malloc(sizeof(No));
    celula->cuidador = cuidador;
    celula->prox = NULL;
    if (lista->primeira == NULL)
    {
        lista->primeira = celula;
        lista->ultima = celula;
    }
    else
    {
        lista->ultima->prox = celula;
        lista->ultima = lista->ultima->prox;
        lista->ultima->prox = NULL;
    }
}

void retira_lista_cuidador(ListaCuidador *lista, Cuidador *cuidador)
{
    No *ant = NULL;
    No *p = lista->primeira;
    while (p != NULL && p->cuidador != cuidador)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
        return;
    if (p == lista->primeira && p == lista->ultima)
    {
        lista->primeira = NULL;
        lista->ultima = NULL;
        free(p);
        return;
    }
    if (p == lista->ultima)
    {
        lista->ultima = ant;
        ant->prox = NULL;
        free(p);
        return;
    }
    if (p == lista->primeira)
        lista->primeira = p->prox;
    else
        ant->prox = p->prox;
    free(p);
}

void imprime_lista_cuidador(ListaCuidador *lista)
{
    No *aux;
    aux = lista->primeira;

    while (aux != NULL)
    {
        imprime_cuidador(aux->cuidador);
        aux = aux->prox;
    }
}

void libera_lista_cuidador(ListaCuidador *lista)
{
    No *aux;
    No *ant;
    aux = lista->primeira;
    while (aux != NULL)
    {
        ant = aux->prox;
        libera_cuidador(aux->cuidador);
        free(aux);
        aux = ant;
    }
    free(lista);
}
