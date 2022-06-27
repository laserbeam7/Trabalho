#include "lista_idoso.h"

struct no
{
    Idoso *paciente;
    No *prox;
};

struct lista_idoso
{
    No *primeira;
    No *ultima;
    int num_pacientes;
};

ListaIdoso *inicializa_lista_idoso()
{
    ListaIdoso *lista = (ListaIdoso *)malloc(sizeof(ListaIdoso));
    lista->primeira = NULL;
    lista->ultima = NULL;
    lista->num_pacientes = 0;

    return lista;
}

void insere_lista_idoso(Idoso *paciente, ListaIdoso *lista)
{
    No *celula = (No *)malloc(sizeof(No));
    celula->paciente = paciente;
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
    lista->num_pacientes++;
}

void retira_lista_idoso(ListaIdoso *lista, Idoso *paciente)
{
    No *ant = NULL;
    No *p = lista->primeira;
    while (p != NULL && p->paciente != paciente)
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

void imprime_lista_idoso(ListaIdoso *lista)
{
    No *aux;
    aux = lista->primeira;

    while (aux != NULL)
    {
        imprime_idoso(aux->paciente);
        aux = aux->prox;
    }
}

void libera_lista_idoso(ListaIdoso *lista)
{
    No *aux;
    No *ant;
    aux = lista->primeira;
    while (aux != NULL)
    {
        ant = aux->prox;
        libera_idoso(aux->paciente);
        free(aux);
        aux = ant;
    }
    free(lista);
}

Idoso* get_idoso(ListaIdoso* lista, int n){
    No* aux = lista->primeira;
    int i;
    for(i = 0; i < n - 1; i++){
        aux = aux->prox;
    }   
    
    return aux->paciente;
}

Idoso* get_idoso_ultima(ListaIdoso* lista){
    return lista->ultima->paciente;
}

int retorna_numero_idosos(ListaIdoso* lista){
    return lista->num_pacientes;
}
