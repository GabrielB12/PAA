// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ########################## TAD X.h ######################################

// ###################### Funcoes e Procedimentos do programa ##############
int A(int a, int b)
{
    int x, x2;

    if (b == 0)
        return 1;
    else
    {
        x2 = A(a, floor(b / 2));
        x = x2 * x2;
        if (b % 2 == 1)
            x = x * a;
    }
    return x;
}

int B(int a, int b)
{
    int d;
    d = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            d = d * a;
        b = floor(b / 2);
        if (b > 0)
            a = a * a;
    }
    return d;
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int num_moedas(int N, int M, int *m)
{
    int dp[N + 1];

    // caso base
    dp[0] = 0;

    // sub-problemas
    for (int i = 1; i <= N; i++)
    {
        // é comum atribuir um valor alto, que concerteza
        // é maior que qualquer uma das próximas possibilidades,
        // sendo assim substituido
        dp[i] = 1000000;

        for (int j = 0; j < M; j++)
        {
            if (i - m[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - m[j]] + 1);
            }
        }
    }

    // solução
    return dp[N];
}
// ############################ Principal ###################################

int main()
{
    int vet[3] = {10, 12, 5};
    //printf("%d", A(3, 4)); //funcao "A" faz o numero elevado a outro

    //printf("%d", B(2, 10)); //funcao "B" faz a mesma coisa

    printf("%d", num_moedas(30, 3, vet));

    return 0;
}
