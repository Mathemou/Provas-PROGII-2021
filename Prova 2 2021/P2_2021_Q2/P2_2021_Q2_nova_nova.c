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

int CodigoDoFilme(tFilme filme);

int QuantidadeDoFilme(tFilme filme);

int ValorDoFilme(tFilme filme);

int QuantidadeAlugadaDoFilme(tFilme filme);

tFilme CriaFilme(char nome[], int cod, int valor, int quantidade);

int ComparaFilmes(tFilme filme1, tFilme filme2);

tFilme AtualizaEstoqueFilmeAlugar(tFilme filme);

tFilme AtualizaEstoqueFilmeDevolver(tFilme filme);

void PrintaFilmeCadastrado(tFilme filme);

void PrintaFilmeEmEstoque(tFilme filme);

void PrintaFilmeNaoDisponivel(tFilme filme);

void PrintaFilmeDevolvido(tFilme filme);

void PrintaNaoFoiPossivelDevolverFilme(tFilme filme);




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
        if (codigo==CodigoDoFilme(locadora.filme[i]))
        {
            ver=0;
        }
    }
    if(ver==1)
    {
        locadora.filme[locadora.qnt_filmes]=CriaFilme(nome, codigo, valor, quantidade);
        PrintaFilmeCadastrado(locadora.filme[locadora.qnt_filmes]);
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
        PrintaFilmeEmEstoque(locadora.filme[i]);
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
            if (ComparaFilmes(locadora.filme[i], locadora.filme[j])>0)
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
            if(codigos[i]==CodigoDoFilme(locadora.filme[j])&&QuantidadeDoFilme(locadora.filme[j])>0)
            {
                qnt_filmes_alugados_com_sucesso++;
                custo+=ValorDoFilme(locadora.filme[j]);
                locadora.filme[j]=AtualizaEstoqueFilmeAlugar(locadora.filme[j]);
                ver=1;
            }
            else if (codigos[i]==CodigoDoFilme(locadora.filme[j])&&QuantidadeDoFilme(locadora.filme[j])==0)
            {
                PrintaFilmeNaoDisponivel(locadora.filme[j]);
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
            if(codigos[i]==CodigoDoFilme(locadora.filme[j])&&QuantidadeAlugadaDoFilme(locadora.filme[j])>0)
            {
                locadora.filme[j] = AtualizaEstoqueFilmeDevolver(locadora.filme[j]);
                locadora.lucro_total+=ValorDoFilme(locadora.filme[j]);
                PrintaFilmeDevolvido(locadora.filme[j]);
                ver=1;
            }
            else if (codigos[i]==CodigoDoFilme(locadora.filme[j])&&QuantidadeAlugadaDoFilme(locadora.filme[j])==0)
            {
                PrintaNaoFoiPossivelDevolverFilme(locadora.filme[j]);
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

int CodigoDoFilme(tFilme filme)
{
    return filme.codigo;
}

int QuantidadeDoFilme(tFilme filme)
{
    return filme.quantidade;
}

int ValorDoFilme(tFilme filme)
{
    return filme.valor;
}

int QuantidadeAlugadaDoFilme(tFilme filme)
{
    return filme.quantidade_alugada;
}

void PrintaFilmeCadastrado(tFilme filme)
{
    printf("Filme cadastrado %d - %s\n", CodigoDoFilme(filme), filme.nome);
}

void PrintaFilmeEmEstoque(tFilme filme)
{
    printf("%d - %s Fitas em estoque: %d\n", filme.codigo, filme.nome, filme.quantidade);
}

void PrintaFilmeNaoDisponivel(tFilme filme)
{
    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", filme.codigo, filme.nome);
}

void PrintaFilmeDevolvido(tFilme filme)
{
    printf("Filme %d - %s Devolvido!\n", filme.codigo, filme.nome);
}

void PrintaNaoFoiPossivelDevolverFilme(tFilme filme)
{
    printf("Nao e possivel devolver o filme %d - %s.\n", filme.codigo, filme.nome);
}

int ComparaFilmes(tFilme filme1, tFilme filme2)
{
    return strcmp(filme1.nome, filme2.nome);
}

tFilme AtualizaEstoqueFilmeAlugar(tFilme filme)
{
    filme.quantidade--;
    filme.quantidade_alugada++;
    return filme;
}

tFilme AtualizaEstoqueFilmeDevolver(tFilme filme)
{
    filme.quantidade++;
    filme.quantidade_alugada--;
    return filme;
}

tFilme CriaFilme(char nome[], int cod, int valor, int quantidade)
{
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = cod;
    filme.valor = valor;
    filme.quantidade = quantidade;
    filme.quantidade_alugada=0;

    return filme;
}
