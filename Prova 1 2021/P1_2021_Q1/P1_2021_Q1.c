#include <stdio.h>
//Operações-----------------------------------------------
int Soma(int x, int y)
{
    return x+y;
}
int Multi(int x, int y)
{
    return x*y;
}
int Div(int x, int y)
{
    return x/y;
}
//Verificador---------------------------------------------
int EhVar(char c)
{
    if (c=='a'||c=='b'||c=='c'||c=='d'||c=='e')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EhNumero(char c)
{
    if (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Calculadoras--------------------------------------------
int CalculaPosFixado(int v1, int v2, char opr)
{
    if(opr=='A')
    {
        return Soma(v1, v2);
    }
    else if (opr=='M')
    {
        return Multi(v1, v2);
    }
    else if (opr=='D')
    {
        return Div(v1,v2);
    }
    return -1;
}

int ConverteCharPraInt(char i)
{
    char c, aux;
    int n;
    n = (i-'0');
    while(1)
    {
        scanf("%c", &aux);
        if (aux==' ')
        {
            break;
        }
        n *=10;
        n+=(aux-'0');
    }
    return n;
}

int ReduzExpressao(int a, int b, int c, int d, int e)
{
    char v1, v2, aux, aux2;
    char opr, letra;
    int n1, n2, result;
    scanf(" %c", &v1);
    if (EhNumero(v1))
    {
        n1 = (v1-'0');
        while(1)
        {
            scanf("%c", &aux);
            if (aux==' ')
            {
                break;
            }
            else if (aux=='.')
            {
                return n1;
            }
            n1 *=10;
            n1+=(aux-'0');
        }
    }
    else if (v1=='a')
    {
        if (a==-1)
        {
            return -1;
        }
        n1 = a;
        scanf("%c", &aux);
        if (aux=='.')
        {
            return n1;
        }
    }
    else if (v1=='b')
    {
        if (b==-1)
        {
            return -1;
        }
        n1 = b;
        scanf("%c", &aux);
        if (aux=='.')
        {
            return n1;
        }
    }
    else if (v1=='c')
    {
        if (c==-1)
        {
            return -1;
        }
        n1 = c;
        scanf("%c", &aux);
        if (aux=='.')
        {
            return n1;
        }
    }
    else if (v1=='d')
    {
        if (d==-1)
        {
            return -1;
        }
        n1 = d;
        scanf("%c", &aux);
        if (aux=='.')
        {
            return n1;
        }
    }
    else if (v1=='e')
    {
        if (e==-1)
        {
            return -1;
        }
        n1 = e;
        scanf("%c", &aux);
        if (aux=='.')
        {
            return n1;
        }
    }
    while(1)
    {
        scanf("%c", &v2);
        /*if (v2=='.'){
          break;
        }*/
        if (EhNumero(v2))
        {
            n2 = ConverteCharPraInt(v2);
        }
        else if (v2=='a')
        {
            if (a==-1)
            {
                return -1;
            }
            n2 = a;
            scanf(" ");
        }
        else if (v2=='b')
        {
            if (b==-1)
            {
                return -1;
            }
            n2 = b;
            scanf(" ");
        }
        else if (v2=='c')
        {
            if (c==-1)
            {
                return -1;
            }
            n2 = c;
            scanf(" ");
        }
        else if (v2=='d')
        {
            if (d==-1)
            {
                return -1;
            }
            n2 = d;
            scanf(" ");
        }
        else if (v2=='e')
        {
            if (e==-1)
            {
                return -1;
            }
            n2 = e;
            scanf(" ");
        }
        scanf("%c", &opr);
        scanf("%c", &aux2);
        n1 = CalculaPosFixado(n1,n2, opr);
        if (aux2=='.')
        {
            break;
        }
    }
    return n1;
}
//Principal-----------------------------------------------
int main(void)
{
    char letra;
    int a=-1, b=-1, c=-1, d=-1, e=-1,aux, senha=1, ver=1;
    while(scanf("%c", &letra)==1)
    {
        if (letra=='#')
        {
            printf("COMECOU\n");
            while (1)
            {
                scanf("%c", &letra);
                //condição de parada
                if (letra=='#')
                {
                    printf("TERMINOU\n\n");
                    break;
                }

                if (letra=='a')
                {
                    scanf(" = ");
                    a = ReduzExpressao(a, b, c, d, e);
                    if (a==-1&&ver==1)
                    {
                        printf("IGNORAR RESTANTE DESTE TRECHO\n");
                        ver=0;
                    }
                    //senha *= a;
                }
                else if (letra=='b')
                {
                    scanf(" = ");
                    b = ReduzExpressao(a, b, c, d, e);
                    if (b==-1&&ver==1)
                    {
                        printf("IGNORAR RESTANTE DESTE TRECHO\n");
                        ver=0;
                    }
                    //senha *= b;
                }
                else if (letra=='c')
                {
                    scanf(" = ");
                    c = ReduzExpressao(a, b, c, d, e);
                    if (c==-1&&ver==1)
                    {
                        printf("IGNORAR RESTANTE DESTE TRECHO\n");
                        ver=0;
                    }
                    //senha *= c;
                }
                else if (letra=='d')
                {
                    scanf(" = ");
                    d = ReduzExpressao(a, b, c, d, e);
                    if (d==-1&&ver==1)
                    {
                        printf("IGNORAR RESTANTE DESTE TRECHO\n");
                        ver=0;
                    }
                    //senha *= d;
                }
                else if (letra=='e')
                {
                    scanf(" = ");
                    e = ReduzExpressao(a, b, c, d, e);
                    if (e==-1&&ver==1)
                    {
                        printf("IGNORAR RESTANTE DESTE TRECHO\n");
                        ver=0;
                    }
                    //senha *= e;
                }
                else if (letra=='?')
                {
                    aux = ReduzExpressao(a, b, c, d, e);
                    if (aux==-1&&ver==1)
                    {
                        printf("IGNORAR RESTANTE DESTE TRECHO\n");
                        ver=0;
                    }
                    if (ver==1)
                    {
                        senha *= aux;
                        printf("%d\n", aux);
                    }
                }
            }
        }
        a=-1;
        b=-1;
        c=-1;
        d=-1;
        e=-1;
        ver = 1;
    }
    printf("SENHA: %d", senha);
    return 0;
}
