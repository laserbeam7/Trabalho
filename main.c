#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "lista_idoso.h"

int main(int argc, char *argv[])
{

    ListaIdoso *pacientes;
    ListaCuidador *cuidadores;
    
    if(argv[1] == NULL){
        printf("Digite o numero de leituras! Programa finalizado.\n");
        return 0;
    }
    pacientes = le_arquivo_paciente(atoi(argv[1]));

    libera_lista_idoso(pacientes);

    return 0;
}