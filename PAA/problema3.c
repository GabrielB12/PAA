// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>
#define saida 999
// ########################## TAD X.h ######################################

struct valores //estrutura para os elementos da lista encadeada
{
    int atual;            //valor de quem vai escolher
    int escolha;          //valor escolhido pelo "atual"
    struct valores *prox; //proximo elemento da lista
};
typedef struct valores Casais;

// ###################### Funcoes e Procedimentos do programa ##############

Casais *aloca(Casais *teste) //aloca para ponteiros do tipo Casais
{
    teste = malloc(sizeof(Casais));
    return teste;
}

void zeraVetor(int *final, int qnt) //zera o vetor final
{
    int i;
    for (i = 0; i < qnt; i++)
    {
        final[i] = 0;
    }
}

void imprime(int num, int *final)
{
    int i;
    for (i = 0; i < num; i++)
    {
        int valor = i + 1;
        if (final[i] != 1)
        {
            continue;
        }
        else if (final[i] != 0) //caso final[i] seja valido entao o numero faz parte do resultado final
        {
            printf("%d ", valor);
        }
    }
}

int *formaCasais(Casais *raiz, int qnt, int *final)
{
    int i, controle;
    Casais *estado, *anterior;
    estado = raiz; //comeca com a raiz

    controle = 0;         //variavel para checar se o vetor final ja esta pronto
    while (controle != 1) //se for 1 entao ja achamos o vetor resultante
    {
        anterior = NULL; //antes do no raiz nao tem nenhum elemento
        estado = raiz;
        for (i = 0; i < qnt; i++)
        {
            if (final[i] == saida)
            {
                continue;
            }
            else
            {
                final[i] = 0;
            }
        }

        while (estado != NULL) //preenche o vetor "final" com todas as escolhas por posicao
        {
            final[estado->escolha - 1] = final[estado->escolha - 1] + 1;
            estado = estado->prox; //vai pro proximo ate acabar a lista encadeada
        }

        controle = 1;
        for (i = 0; i < qnt; i++)
        {
            if (final[i] != 0) //se o valor na posicao final[i] for valido passa para o proximo valor do vetor
            {
                continue;
            }
            else //se algum esta errado a variavel de controle volta para 0, e o laco nao acaba
            {
                controle = 0;
                break;
            }
        }
        estado = raiz;
        Casais *teste;

        while (estado != NULL) //roda todos os elementos da lista
        {
            if (final[estado->atual - 1] == 0)    //se o valor é 0 o elemento deve ser removido
            {                                     //vide exercicio 2 da lista de exercicios 3
                final[estado->atual - 1] = saida; //recebe o "999", que no laço while mais acima pula na hora de
                teste = estado;                   //zerar
                if (anterior == NULL)             //se for null entao é a raiz
                {
                    raiz = estado->prox;
                }
                else if (anterior != NULL) //o proximo do elemento que vale 0
                {                          //o novo atual, que é o anterior->proximo recebe
                    anterior->prox = estado->prox;
                }
                estado = estado->prox; //vai para o proximo para continuar eliminando os invalidos
                free(teste);           //exclui/libera o "teste"
                continue;
            }
            anterior = estado;     //o elemento "anterior" recebe o valor do proximo elemento
            estado = estado->prox; //e estado recebe o proximo do proximo
        }
    }
    return final;
}

// ############################ Principal ###################################

int main()
{
    int num, i;
    Casais *raiz;
    raiz = aloca(raiz); //alocando o espaco para a raiz

    scanf("%d", &num); //le o numero e os seguintes

    //leitura dos valores da raiz
    raiz->prox = NULL; //no comeco ainda só tem a propria raiz
    scanf("%d", &raiz->atual);
    scanf("%d", &raiz->escolha);

    Casais *aux = raiz;       //ja recebe um elemento, no caso a raiz, com valores, preenchidos acima
    for (i = 1; i < num; i++) //i comeca em 1 pois ja foi lido um valor, no caso a raiz, entao serao lidos "num -1" elementos
    {
        Casais *novoElem;
        novoElem = aloca(novoElem);      //aloca espaco para o elemento a ser inserido na lista
        novoElem->prox = NULL;           //nao tem proximo
        scanf("%d", &novoElem->atual);   //valor de quem escolhe
        scanf("%d", &novoElem->escolha); //valor do escolhido

        aux->prox = novoElem;
        aux = novoElem; //atualiza o aux(que no inicio é a raiz) e volta para o loop
    }

    //vetor dinamico que armazena os casais resultantes depois de chamar a funcao "formaCasais"
    int *final;
    final = malloc(num * sizeof(int *));
    zeraVetor(final, num);                 //pra comecar zerado
    final = formaCasais(raiz, num, final); //final recebe o valor retornado pela funcao

    imprime(num, final);

    return 0;
}
