// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ########################## TAD X.h ######################################

// ###################### Funcoes e Procedimentos do programa ##############

int verifica(int num)
{
    int vetorMAX[num], i, j, aux = 0;
    int raiz = sqrt(num);

    for (i = 2; i < num; i++) //preenchendo vetor de tamanho "max"
    {
        vetorMAX[i] = i;
    }

    for (i = 2; i <= num; i++) //método "Crivo de Erastótenes"
    {
        if (vetorMAX[i] == i) //"i" é primo
        {
            for (j = i + i; j <= num; j += i) //como "i" é primo, seus multiplos nao serao;
            {                                 //assim, zeramos os seus multiplos, para encurtar o vetor
                vetorMAX[j] = 0;
            }
        }
    }

    for (i = 2; i < num; i++)
    {
        if (vetorMAX[i] != 0) //nem verifica para alguns casos, zerados por serem multiplos de outro numero
        {
            for (j = i; j < num; j++)
            {
                if (vetorMAX[i] + vetorMAX[j] == num) //ve se a soma de algum dos numeros é igual o informado
                {                                     //para verificar a quantidade de possibilidades de
                    aux++;                            //escrever o numero como soma de primos
                }                                     //soma quantas vezes existe a soma em um
            }                                         //contador
        }
    }
    return aux;
}

// ############################ Principal ###################################

int main()
{
    int num;

    scanf("%d", &num);
    printf("%d", (verifica(num)));

    return 0;
}
