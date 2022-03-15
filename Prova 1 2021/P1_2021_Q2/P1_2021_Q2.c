#include <stdio.h>
void flush_in()
{
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ) {}
}

int main(void)
{
    int n, i=0, nota, maior_nota=-1, menor_nota=6, soma_notas=0, cont_notas=0, ver=1, maior_nota_g=0, menor_nota_g=6, crit_f=0, maior_critf=0, crit_g=0, maior_critg=0, maior_media_g=0, mngpnota=0, sem_crit=0;
    char c1, c2, c3, aux, f1, f2, f3, maiorf1, maiorf2, maiorf3, menorf1, menorf2, menorf3, maiorgf1, maiorgf2, maiorgf3, menorgf1, menorgf2, menorgf3, notachar, fmp1, fmp2, fmp3, gmp1, gmp2, gmp3, mmg1, mmg2, mmg3, mngp1, mngp2, mngp3;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        //printf("Digite a categoria: ");
        if (ver==1)
        {
            flush_in();
            ver=0;
        }
        scanf("#%c%c%c", &c1, &c2, &c3);
        while(1)
        {
            //printf("Digite o filme = ");
            flush_in();
            scanf("%c%c%c", &f1, &f2, &f3);
            if (f1=='F'&&f2=='I'&&f3=='M')
            {
                scanf("\n");
                break;
            }
            scanf(" [");
            while(1)
            {
                scanf("%c", &notachar);
                if (notachar==']')
                {
                    sem_crit++;
                    crit_f=0;
                    break;
                }
                nota = notachar - '0';
                soma_notas+=nota;
                cont_notas++;
                crit_f++;
                if (nota>maior_nota)
                {
                    maior_nota=nota;
                    maiorf1=f1;
                    maiorf2=f2;
                    maiorf3=f3;
                }
                if (nota<menor_nota)
                {
                    menor_nota=nota;
                    menorf1=f1;
                    menorf2=f2;
                    menorf3=f3;
                }
                if (nota>maior_nota_g)
                {
                    maior_nota_g=nota;
                    maiorgf1=f1;
                    maiorgf2=f2;
                    maiorgf3=f3;
                }
                if (nota<menor_nota_g)
                {
                    menor_nota_g=nota;
                    menorgf1=f1;
                    menorgf2=f2;
                    menorgf3=f3;
                }
                if (crit_f>maior_critf)
                {
                    maior_critf = crit_f;
                    fmp1=f1;
                    fmp2=f2;
                    fmp3=f3;
                }
                if (cont_notas>maior_critg)
                {
                    maior_critg=cont_notas;
                    gmp1=c1;
                    gmp2=c2;
                    gmp3=c3;
                    mngp1=maiorf1;
                    mngp2=maiorf2;
                    mngp3=maiorf3;
                    mngpnota = maior_nota_g;
                }
                scanf("%c", &aux);
                if (aux==']')
                {
                    crit_f=0;
                    break;
                }

            }

        }
        printf("FILME DO GENERO %c%c%c COM MAIOR NOTA: %c%c%c (%d)\n", c1, c2, c3, maiorf1, maiorf2, maiorf3, maior_nota);
        printf("FILME DO GENERO %c%c%c COM MENOR NOTA: %c%c%c (%d)\n", c1, c2, c3, menorf1, menorf2, menorf3, menor_nota);
        printf("MEDIA DO GENERO %c%c%c: %d\n\n", c1, c2, c3, (soma_notas/cont_notas));
        if ((soma_notas/cont_notas)>maior_media_g)
        {
            maior_media_g = (soma_notas/cont_notas);
            mmg1=c1;
            mmg2=c2;
            mmg3=c3;
        }
        maior_nota=-1;
        menor_nota=6;
        soma_notas=0;
        cont_notas=0;
        crit_g=0;


    }
    printf("FILME GERAL COM MAIOR NOTA: %c%c%c (%d)\n", maiorgf1, maiorgf2, maiorgf3, maior_nota_g);

    printf("FILME GERAL COM MENOR NOTA: %c%c%c (%d)\n", menorgf1, menorgf2, menorgf3, menor_nota_g);

    printf("FILME MAIS POPULAR: %c%c%c (%d CRITICAS)\n", fmp1,fmp2,fmp3, maior_critf);

    printf("GENERO MAIS POPULAR: %c%c%c (%d CRITICAS)\n", gmp1, gmp2, gmp3, maior_critg);

    printf("GENERO COM MAIOR MEDIA TRUNCADA: %c%c%c (%d)\n", mmg1, mmg2, mmg3, maior_media_g);

    printf("FILME COM MAIOR NOTA DO GENERO MAIS POPULAR: %c%c%c (%d)\n", mngp1, mngp2, mngp3, mngpnota);

    printf("FILMES QUE NAO POSSUEM CRITICAS: %d", sem_crit);
    return 0;
}
