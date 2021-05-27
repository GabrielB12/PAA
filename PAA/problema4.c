// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

// ###################### Funcoes e Procedimentos do programa ##############

int potencia(int base, int exp) //funcao auxiliar para receber os valores das potencias de 2
{
    if (exp == 0)
    {
        return 1;
    }
    else
    {
        return (base * potencia(base, exp - 1));
    }
}

int moedas(int *vet, int valor)
{
    int teste, teste2;
    int i, atual, moedas = 0;
    while (valor != 0) //quando verar significa que encontramos a quantidade de moedas envolvidas na transacao
    {
        for (i = 0; i < 14; i++)
        {
            if (vet[i] == valor) //se for igual significa que existe uma potencia de 2 com esse valor
            {                    //logo, so precisa de uma moeda a mais para realizar a transacao
                teste = 999;
                teste2 = 998;
                break;
            }
            if (vet[i] > valor)              //roda o vetor ate chegar em uma potencia de 2 maior que o valor atual
            {                                //guarda o valor maior que o atual, e o menor tambem
                teste = vet[i] - valor;      //para gerar um numero positivo(pois valor é menor que o elemento do vetor)
                teste2 = valor - vet[i - 1]; //faz o inverso pois valor nesse caso é maior
                break;
            }
            if (valor > vet[13])
            {
                teste = valor - vet[13];
                teste2 = valor;
            }
        }

        moedas++; //vai incrementando 1 a cada laco do while

        if (teste == 999 && teste2 == 998) //caso seja potencia de 2 ja para o laco
        {
            break;
        }
        if (teste < teste2) //acha qual o que vale menos, o que significa que é o mais proximo dele(valor atual)
        {
            valor = teste;
        }
        else if (teste2 < teste)
        {
            valor = teste2;
        }
        else //se forem iguais tanto faz o valor a atribuir "valor"
        {
            valor = teste;
        }
    }
    return moedas;
}

// ############################ Principal ###################################

int main()
{
    int i, vetPot[14], valor, qnt; //vetor com 14 posicoes, pois o valor de 2 elevado a 13 é mais próximo de
                                   //10.000 do que 2 elevado a 14
    for (i = 0; i < 14; i++)       //preenche o vetor
    {
        vetPot[i] = potencia(2, i);
    }

    scanf("%d", &valor);

    printf("%d", moedas(vetPot, valor));

    return 0;
}
