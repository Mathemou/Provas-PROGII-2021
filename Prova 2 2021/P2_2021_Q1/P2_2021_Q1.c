#include <stdio.h>
#include <string.h>

typedef struct Texto
{
    char palavra[30][40];
    int linhas;
    int letras_linha;
} tTexto;

typedef struct Alvo
{
    char palavra[40];
    int qnt;
    int pos_ini[2];
    int pos_fim[2];
} tAlvo;

tTexto LeTexto();

void ImprimeTexto(tTexto texto);

void LeAlvo(tTexto texto);

tAlvo ProcuraPalavra(tAlvo alvo, tTexto texto);


int main(void)
{
    tTexto texto;
    char palavra[40];
    texto = LeTexto();
    LeAlvo(texto);
    return 0;
}

tTexto LeTexto()
{
    int li=0, cf=0;
    char c;
    tTexto texto;
    while(1)
    {
        scanf("%s", texto.palavra[li]);
        if (strcmp(texto.palavra[li], "#")==0)
        {
            break;
        }
        li++;
    }
    texto.linhas=li;
    return texto;
}

void ImprimeTexto(tTexto texto)
{
    int i=0, j=0;
    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[i]); j++)
        {
            printf("%c", texto.palavra[i][j]);
        }
        printf("\n");
    }
}

void LeAlvo(tTexto texto)
{
    tAlvo alvo;
    alvo.qnt=0;
    while(scanf("%s", alvo.palavra)==1)
    {
        alvo = ProcuraPalavra(alvo, texto);
        if (alvo.qnt>0)
        {
            printf("%s - (%d,%d) - (%d,%d)\n", alvo.palavra, alvo.pos_ini[0]+1, alvo.pos_ini[1]+1, alvo.pos_fim[0], alvo.pos_fim[1]+1);
        }
        else
        {
            printf("%s - NAO ENCONTRADA!\n", alvo.palavra);
        }
    }
}

tAlvo ProcuraPalavra(tAlvo alvo, tTexto texto)
{
    int i=0, j=0, k=0, l=0, m=0, n=0, o=0, ver=0, pos_ini[2], pos_fim[2];
    alvo.qnt=0;
    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[i]); j++)
        {
            if (texto.palavra[i][j]==alvo.palavra[0])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=j, l=0; l<strlen(alvo.palavra); k++,l++)
                {
                    if (texto.palavra[i][k]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if (ver==1)
                {
                    alvo.pos_ini[0]=pos_ini[0];
                    alvo.pos_ini[1]=pos_ini[1];
                    alvo.pos_fim[0]=i+1;
                    alvo.pos_fim[1]=k-1;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(j=0; j<strlen(texto.palavra[0]); j++)
    {
        for(i=0; i<texto.linhas; i++)
        {
            if(texto.palavra[i][j]==alvo.palavra[0])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=i, l=0; l<strlen(alvo.palavra); k++, l++)
                {
                    if (texto.palavra[k][j]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if(ver==1)
                {
                    alvo.pos_ini[0]=pos_ini[0];
                    alvo.pos_ini[1]=pos_ini[1];
                    alvo.pos_fim[0]=k;
                    alvo.pos_fim[1]=j;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[i]); j++)
        {
            if (texto.palavra[i][j]==alvo.palavra[strlen(alvo.palavra)-1])
            {
                pos_fim[0]=i+1;
                pos_fim[1]=j;
                ver=1;
                for(k=j, l=strlen(alvo.palavra)-1; l>=0; k++,l--)
                {
                    if (texto.palavra[i][k]!=alvo.palavra[l])
                    {

                        ver=0;
                    }
                }
                if (ver==1)
                {
                    alvo.pos_fim[0]=pos_fim[0];
                    alvo.pos_fim[1]=pos_fim[1];
                    alvo.pos_ini[0]=i;
                    alvo.pos_ini[1]=k-1;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(j=0; j<strlen(texto.palavra[0]); j++)
    {
        for(i=0; i<texto.linhas; i++)
        {
            if(texto.palavra[i][j]==alvo.palavra[strlen(alvo.palavra)-1])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=i, l=strlen(alvo.palavra)-1; l>=0; k++, l--)
                {
                    if (texto.palavra[k][j]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if(ver==1)
                {
                    alvo.pos_ini[0]=k-1;
                    alvo.pos_ini[1]=j;
                    alvo.pos_fim[0]=pos_ini[0]+1;
                    alvo.pos_fim[1]=pos_ini[1];
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[0]); j++)
        {
            if(texto.palavra[i][j]==alvo.palavra[0])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=j, m=i, l=0; l<strlen(alvo.palavra); k++, m++, l++)
                {
                    if (texto.palavra[m][k]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if(ver==1)
                {
                    alvo.pos_ini[0]=pos_ini[0];
                    alvo.pos_ini[1]=pos_ini[1];
                    alvo.pos_fim[0]=m;
                    alvo.pos_fim[1]=k-1;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[0]); j++)
        {
            if(texto.palavra[i][j]==alvo.palavra[0])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=j, m=i, l=0; l<strlen(alvo.palavra); k--, m--, l++)
                {
                    if (texto.palavra[m][k]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if(ver==1)
                {
                    alvo.pos_ini[0]=pos_ini[0];
                    alvo.pos_ini[1]=pos_ini[1];
                    alvo.pos_fim[0]=m+2;
                    alvo.pos_fim[1]=k+1;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[0]); j++)
        {
            if(texto.palavra[i][j]==alvo.palavra[0])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=j, m=i, l=0; l<strlen(alvo.palavra); k++, m--, l++)
                {
                    if (texto.palavra[m][k]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if(ver==1)
                {
                    alvo.pos_ini[0]=pos_ini[0];
                    alvo.pos_ini[1]=pos_ini[1];
                    alvo.pos_fim[0]=m+2;
                    alvo.pos_fim[1]=k-1;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }

    for(i=0; i<texto.linhas; i++)
    {
        for(j=0; j<strlen(texto.palavra[0]); j++)
        {
            if(texto.palavra[i][j]==alvo.palavra[0])
            {
                pos_ini[0]=i;
                pos_ini[1]=j;
                ver=1;
                for(k=j, m=i, l=0; l<strlen(alvo.palavra); k--, m++, l++)
                {
                    if (texto.palavra[m][k]!=alvo.palavra[l])
                    {
                        ver=0;
                    }
                }
                if(ver==1)
                {
                    alvo.pos_ini[0]=pos_ini[0];
                    alvo.pos_ini[1]=pos_ini[1];
                    alvo.pos_fim[0]=m;
                    alvo.pos_fim[1]=k+1;
                    alvo.qnt++;
                }
                ver=0;
            }
        }
    }
    return alvo;
}

