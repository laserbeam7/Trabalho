#include "arquivos.h"

#define MAXCHAR 1000

struct node{
    FILE* arquivo;
    Node* prox;
};

struct lista_circular{
    Node* primeira;
    Node* ultima;
};

ListaCircular* inicializa_lista_circular(int num_pacientes){
    int i;

    ListaCircular* lc = (ListaCircular*)malloc(sizeof(ListaCircular));
    lc->primeira = NULL;
    lc->ultima = NULL;
    Node* aux;
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->arquivo = NULL;
    novo->prox = NULL;
    lc->primeira = novo;
    for (i = 0; i < num_pacientes - 1; i++)
    {
       aux = (Node*)malloc(sizeof(Node));
       aux->prox = NULL;
       novo->prox = aux;
       novo = aux;
    }
    lc->ultima = novo;
    lc->ultima->prox = lc->primeira;

    return lc;
}

FILE *abrir_arquivo(char *arquivo)
{
    FILE *ler;
    ler = fopen(arquivo, "r");
    if (ler == NULL)
    {
        printf("Nao foi possivel abrir o arquivo desejado!!");
    }

    return ler;
}

void le_arquivo(FILE *arquivo)
{
    char row[MAXCHAR];
    char *token;

    while (feof(arquivo) != 1)
    {
        if (fgets(row, MAXCHAR, arquivo) == NULL)
        {
            break;
        }
        printf("Linha: %s\n", row);
        token = strtok(row, ";");

        while (token != NULL)
        {
            printf("Token: %s\n", token);
            token = strtok(NULL, ";");
        }
    }
}

ListaIdoso *le_arquivo_paciente(int n)
{
    int i;
    int count;
    int num_pacientes = 1;
    char row[MAXCHAR];
    char *token;
    float temperatura;
    int latitude;
    int longitude;
    int queda;
    FILE *fp;
    ListaCircular* lc;
    ListaIdoso *lista_pacientes;
    Idoso *aux;

    lista_pacientes = le_arquivo_apoio();
    lc = abre_arquivo_idoso(lista_pacientes);

    for (i = 0; i < n; i++)
    {
        while (num_pacientes <= retorna_numero_idosos(lista_pacientes))
        {
            count = 0;
            //aux = get_idoso(lista_pacientes, num_pacientes);
            //fp = abrir_arquivo(get_arquivo_idoso(aux));

            if (fgets(row, MAXCHAR, fp) == NULL)
            {
                return NULL;
            }

            if (strcmp(row, "falecimento\n") == 0)
            { // Implementar retirada caso haja falecimento
            }

            token = strtok(row, ";");

            while (token != NULL)
            {
                switch (count)
                {
                case 0:
                    temperatura = atof(token);
                    set_temperatura_idoso(aux, temperatura);
                    break;
                case 1:
                    latitude = atoi(token);
                    set_latitude_idoso(aux, latitude);
                    break;
                case 2:
                    longitude = atoi(token);
                    set_longitude_idoso(aux, longitude);
                    break;
                case 3:
                    queda = atoi(token);
                    set_queda_idoso(aux, queda);
                    break;
                }
                token = strtok(NULL, ";");
                count++;
            }
            num_pacientes++;
        }
        imprime_lista_idoso(lista_pacientes);
        //imprime_lista_idoso(lista_pacientes);
    }
    
    return lista_pacientes;
}

Cuidador *le_arquivo_cuidador(FILE *arquivo)
{
    int count = 0;
    char row[MAXCHAR];
    char *token;
    int latitude;
    int longitude;
    char *nome;

    Cuidador *cuidador;
    cuidador = cria_cuidador();

    if (fgets(row, MAXCHAR, arquivo) == NULL)
    {
        return NULL;
    }
    token = strtok(row, ";");

    while (token != NULL)
    {
        switch (count)
        {
        case 0:
            latitude = atoi(token);
            set_latitude_cuidador(cuidador, latitude);
            break;
        case 1:
            longitude = atoi(token);
            set_longitude_cuidador(cuidador, longitude);
            break;
        }
        token = strtok(NULL, ";");
        count++;
    }
    return cuidador;
}

ListaIdoso *le_arquivo_apoio()
{
    FILE *fp = abrir_arquivo("apoio.txt");
    char row[MAXCHAR];
    char *token;
    Idoso *paciente;
    ListaIdoso *lista_idosos;

    lista_idosos = inicializa_lista_idoso();

    if (fgets(row, MAXCHAR, fp) == NULL)
    {
        return NULL;
    }
    token = strtok(row, ";");

    while (token != NULL)
    {
        paciente = cria_idoso();
        set_nome_idoso(paciente, token);
        set_nome_arquivo_idoso(paciente, prepara_nome_arquivo_idoso(token));
        insere_lista_idoso(paciente, lista_idosos);
        token = strtok(NULL, ";");
    }
    token = strtok(get_nome_idoso(paciente), "\n");
    return lista_idosos;
}

ListaCircular* abre_arquivo_idoso(ListaIdoso* lista){
    FILE* fp;
    Node* aux;
    Idoso* paciente;
    ListaCircular* lc;
    int n = retorna_numero_idosos(lista);

    lc = inicializa_lista_circular(n);
    aux = lc->primeira;
    int i;
    for(i = 0; i < n; i++){
        paciente = get_idoso(lista, n);
        aux->arquivo = abrir_arquivo(get_arquivo_idoso(paciente));
        aux = aux->prox;
    }
    return lc;
}   

char *prepara_nome_arquivo_idoso(char *nome)
{
    char *copia;
    strcpy(copia, nome);
    remove_enter(copia);
    strcat(copia, ".txt");
    return copia;
}

void remove_enter(char *str)
{
    int i, j;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '\n')
        {
            for (j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
}