#include "idoso.h"

struct idoso
{
    float temperatura;
    int latitude;
    int longitude;
    int queda;
    char *nome;
    int cont_febre;
    char* nome_arquivo;
    int falecido;
};

Idoso *cria_idoso()
{
    Idoso *paciente = (Idoso *)malloc(sizeof(Idoso));
    paciente->temperatura = 0;
    paciente->latitude = 0;
    paciente->longitude = 0;
    paciente->queda = 0;
    paciente->nome = NULL;
    paciente->cont_febre = 0;
    paciente->nome_arquivo = NULL;
    paciente->falecido = 0;

    return paciente;
}

void set_temperatura_idoso(Idoso *paciente, float temperatura)
{
    paciente->temperatura = temperatura;
}

void set_latitude_idoso(Idoso *paciente, int latitude)
{
    paciente->latitude = latitude;
}

void set_longitude_idoso(Idoso *paciente, int longitude)
{
    paciente->longitude = longitude;
}

void set_queda_idoso(Idoso *paciente, int queda)
{
    paciente->queda = queda;
}

void set_nome_idoso(Idoso *paciente, char *nome)
{
    paciente->nome = strdup(nome);
}

void set_nome_arquivo_idoso(Idoso* paciente, char* nome_arquivo){
    paciente->nome_arquivo = strdup(nome_arquivo);
}

void set_faleceu_idoso(Idoso* paciente){
    paciente->falecido = 1;
}

void imprime_idoso(Idoso *paciente)
{
    printf("\nNome: %s\nTemp: %f\nLat: %d\nLong: %d\nQueda: %d\n", paciente->nome, paciente->temperatura,
           paciente->latitude, paciente->longitude, paciente->queda);
}

void libera_idoso(Idoso* paciente){
    free(paciente->nome);
    free(paciente);
}

void checa_gravidade(Idoso* paciente){
    if(paciente->temperatura >= 38){
        printf("\nFEBRE ALTA, ACIONA CUIDADOR\n");
    }
    else if(paciente->queda == 1){
        printf("\nQUEDA, ACIONA CUIDADOR\n");
    }
    else if(paciente->temperatura <= 38 && paciente->temperatura >= 37){
        paciente->cont_febre++;
        if(paciente->cont_febre == 4){
            printf("\nFEBRE BAIXA, ACIONA CUIDADOR\n");
            paciente->cont_febre = 0;
        } else {
            printf("\nFEBRE BAIXA, ACIONA AMIGO\n");
        }
    } else {
        printf("\nTUDO OK!\n");
    }
}

char* get_nome_idoso(Idoso* paciente){
    return paciente->nome;
}

char* get_arquivo_idoso(Idoso* paciente){
    return paciente->nome_arquivo;
}