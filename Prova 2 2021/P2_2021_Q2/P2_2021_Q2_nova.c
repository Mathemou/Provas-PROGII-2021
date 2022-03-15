#include <stdio.h>
#include <string.h>

//Tipos------------------------------
typedef struct Filme
{
    int codigo;
    char nome[20];
    int valor;
    int quantidade;
    int quantidade_alugada;
} tFilme;

typedef struct Locadora
{
    tFilme filme[100];
    int qnt_filmes;
    int lucro_total;
} tLocadora;

//Funções-----------------------------
tLocadora CadastrarFilmeLocadora(tLocadora locadora, char nome[], int codigo, int valor, int quantidade);

tLocadora AlugarFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos);

tLocadora DevolverFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos);

void ConsultarEstoqueLocadora(tLocadora locadora);

tLocadora OrdenarFilmesLocadora (tLocadora locadora);

int TipoDeOperacao(char operacao[]);

tLocadora RealizaOperacaoLocadora (tLocadora locadora, int op);

void ImprimeLucroTotalLocadora(tLocadora locadora);

tLocadora IniciaLocadora(tLocadora locadora);

tLocadora LeOperacoes(tLocadora locadora);


int main(void)
{
    tLocadora locadora;
    locadora = IniciaLocadora(locadora);
    locadora = LeOperacoes(locadora);
    ImprimeLucroTotalLocadora(locadora);
    return 0;
}

tLocadora CadastrarFilmeLocadora(tLocadora locadora, char nome[], int codigo, int valor, int quantidade)
{
    int i=0, ver=1;
    for(i=0; i<locadora.qnt_filmes; i++)
    {
        if (codigo==locadora.filme[i].codigo)
        {
            ver=0;
        }
    }
    if(ver==1)
    {
        locadora.filme[locadora.qnt_filmes].codigo = codigo;
        strcpy(locadora.filme[locadora.qnt_filmes].nome, nome);
        locadora.filme[locadora.qnt_filmes].valor = valor;
        locadora.filme[locadora.qnt_filmes].quantidade = quantidade;
        locadora.filme[locadora.qnt_filmes].quantidade_alugada=0;
        printf("Filme cadastrado %d - %s\n", locadora.filme[locadora.qnt_filmes].codigo, locadora.filme[locadora.qnt_filmes].nome);
        locadora.qnt_filmes++;
    }
    else
    {
        printf("Filme ja cadastrado no estoque\n");
    }


    return locadora;
}

void ConsultarEstoqueLocadora(tLocadora locadora)
{
    int i=0;
    printf("~ESTOQUE~\n");
    for(i=0; i<locadora.qnt_filmes; i++)
    {
        printf("%d - %s Fitas em estoque: %d\n", locadora.filme[i].codigo, locadora.filme[i].nome, locadora.filme[i].quantidade);
    }
}

tLocadora OrdenarFilmesLocadora (tLocadora locadora)
{
    int i=1, j=0, r;
    tFilme aux;
    for(i=0; i<locadora.qnt_filmes; i++)
    {
        for (j=i+1; j<locadora.qnt_filmes; j++)
        {
            if (strcmp(locadora.filme[i].nome, locadora.filme[j].nome)>0)
            {
                aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }
        }
    }

    return locadora;
}

tLocadora AlugarFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos)
{
    int i=0, j=0, ver=0, custo=0, qnt_filmes_alugados_com_sucesso=0;
    for(i=0; i<quantidadeCodigos; i++)
    {
        for(j=0; j<locadora.qnt_filmes; j++)
        {
            if(codigos[i]==locadora.filme[j].codigo&&locadora.filme[j].quantidade>0)
            {
                qnt_filmes_alugados_com_sucesso++;
                custo+=locadora.filme[j].valor;
                locadora.filme[j].quantidade--;
                locadora.filme[j].quantidade_alugada++;
                ver=1;
            }
            else if (codigos[i]==locadora.filme[j].codigo&&locadora.filme[j].quantidade==0)
            {
                printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                ver=1;
            }

        }
        if (ver==0)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
        ver=0;
    }
    if(qnt_filmes_alugados_com_sucesso>0)
    {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qnt_filmes_alugados_com_sucesso, custo);
    }

    return locadora;
}

tLocadora DevolverFilmesLocadora(tLocadora locadora, int codigos[], int quantidadeCodigos)
{
    int i=0, j=0, ver=0, custo=0, qnt_filmes_alugados_com_sucesso=0;
    for(i=0; i<quantidadeCodigos; i++)
    {
        for(j=0; j<locadora.qnt_filmes; j++)
        {
            if(codigos[i]==locadora.filme[j].codigo&&locadora.filme[j].quantidade_alugada>0)
            {
                locadora.filme[j].quantidade++;
                locadora.filme[j].quantidade_alugada--;
                locadora.lucro_total+=locadora.filme[j].valor;
                printf("Filme %d - %s Devolvido!\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                ver=1;
            }
            else if (codigos[i]==locadora.filme[j].codigo&&locadora.filme[j].quantidade_alugada==0)
            {
                printf("Nao e possivel devolver o filme %d - %s.\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                ver=1;
            }
        }
        if(ver==0)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    return locadora;
}

int TipoDeOperacao(char operacao[])
{
    if(strcmp(operacao, "Cadastrar")==0)
    {
        return 1;
    }
    else if (strcmp(operacao, "Estoque")==0)
    {
        return 2;
    }
    else if (strcmp(operacao, "Alugar")==0)
    {
        return 3;
    }
    else if (strcmp(operacao, "Devolver")==0)
    {
        return 4;
    }
    return 0;
}

tLocadora RealizaOperacaoLocadora(tLocadora locadora, int op)
{
    char nome[20];
    int val, qnt, cod;
    int cods_aluguel[20], qnt_filmes_alugados=0;
    int cods_devolucao[20], qnt_filmes_devolvidos=0;
    switch (op)
    {
    case 1:
        while(scanf("%d", &cod)==1)
        {
            scanf(",%[^,],%d,%d\n", nome, &val, &qnt);
            locadora = CadastrarFilmeLocadora(locadora, nome, cod, val, qnt);
        }
        locadora = OrdenarFilmesLocadora(locadora);
        printf("\n");
        break;

    case 2:
        ConsultarEstoqueLocadora(locadora);
        printf("\n");
        break;

    case 3:
        while(scanf("%d", &cods_aluguel[qnt_filmes_alugados])==1)
        {
            qnt_filmes_alugados++;
        }
        locadora = AlugarFilmesLocadora(locadora, cods_aluguel, qnt_filmes_alugados);
        qnt_filmes_alugados=0;
        printf("\n");
        break;

    case 4:
        while(scanf("%d", &cods_devolucao[qnt_filmes_devolvidos])==1)
        {
            qnt_filmes_devolvidos++;
        }
        locadora = DevolverFilmesLocadora(locadora, cods_devolucao, qnt_filmes_devolvidos);
        qnt_filmes_devolvidos=0;
        printf("\n");
        break;

    default:
        break;
    }
    return locadora;
}

void ImprimeLucroTotalLocadora(tLocadora locadora)
{
    if (locadora.lucro_total>0)
    {
        printf("Lucro total R$%d\n", locadora.lucro_total);
    }
}

tLocadora IniciaLocadora(tLocadora locadora)
{
    locadora.qnt_filmes=0;
    locadora.lucro_total=0;
    return locadora;
}

tLocadora LeOperacoes(tLocadora locadora)
{
    char operacao[20];
    while(scanf("%s\n", operacao)==1)
    {
        locadora = RealizaOperacaoLocadora(locadora, TipoDeOperacao(operacao));
    }
    return locadora;
}
