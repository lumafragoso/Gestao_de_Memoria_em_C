#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNÇÃO QUE GERA VALORES ALEATÓRIOS
int rand_int_range(int min, int max){
   int range = max - min + 1;
   return min + rand()%range;
}
int* criarVetorAleatorio(int tam, int min, int max){
    int *v;
    int i=0;

    //ALOCAÇÃO DINÂMICA DO VETOR
    v = malloc(sizeof(int) * (tam+3));

    if(v != NULL){
        //TRES PRIMEIROS VALORES PRECISAM SER PREENCHIDOS COM TAM, MIN E MAX
        v[0] = tam;
        v[1] = min;
        v[2] = max;

        //VALORES RANDOM RESTANTES DO VETOR
        for (i = 3; i < (tam+3); i++){
            v[i] = rand_int_range(min, max);
        }
    }
    return v;
}
int* criarHistograma(int* val){
    int* histo;
    int i=0, j=0, aux=0, a=2;

    //ALOCAÇÃO DINÂMICA DO VETOR
    histo = malloc(sizeof(int) * (abs(val[2] - val[1])+3));

    if(histo != NULL){
        //MÍNIMO = VAL[1], MAX = VAL[2];
        //DOIS PRIMEIROS VALORES PRECISAM SER PREENCHIDOS COM MIN E MAX
        histo[0] = val[1];
        histo[1] = val[2];

        //COLOCAR NO VETOR HISTO A QUANTIDADE DE VEZES
        for (i = val[1]; i < val[2]+1; i++){
            //TAMANHO  = V[0] +3
            for (j = 3; j < (val[0] +3); j++){
                if(i == val[j]){
                    aux++;
                }
            }
            //COLOCAR NO VETOR HISTO A QUANTIDADE DE VEZES QUE O NÚMERO APARECEU
            histo[a] = aux;
            a++;

            //ATUALIZAÇÃO
            aux=0;
        }
    }
    return histo;
}
float* criarPorcentagens(int* quantidade){
    float* porcentagem;
    float total=0;
    int i=0, j=0, k=0, b=0;

    //ALOCAÇÃO DINÂMICA DO VETOR
    porcentagem = malloc(sizeof(int) * (abs(quantidade[1] - quantidade[0])+1));

    //CALCULAR O TOTAL DE NÚMEROS REPETIDOS
    for (k = 2; k < abs(quantidade[1]- quantidade[0])+3; k++){
        total += quantidade[k];
    }
    
    //COLOCAR AS PORCENTAGENS NO VETOR
    if(porcentagem != NULL){
        for (i = 2; i < abs(quantidade[1]- quantidade[0])+3; i++){
            porcentagem[b] = (quantidade[i] / total) * 100;
            b++;
        }
    }
    return porcentagem;
}

void imprimePorcentagens(float* por, int* his){
    int len=0, i=0, valor=his[0];

    //CALCULAR O TAMANHO DO INTERVALO
    len = abs(his[1] - his[0]) +1;

    //PRINTAR CABEÇALHO
    printf("Valor |Qtdade |Porcent\n");
    
    //PRINTAR AS INFORMAÇÕES
    for (i = 0; i < len; i++){
        printf("%d |%d |%.2f%\n", valor, his[i+2], por[i]);
        valor++;
    }
    
}

void liberar(int* valor, float* porcen, int* histo){
    
    free(valor);
    free(porcen);
    free(histo);
}

int main(){
    //VARIÁVEIS
   int tamanho, maximo, minimo;

   //TAMANHO DO VETOR
   scanf("%d", &tamanho);

   //VALORES DE MÍNIMO E MÁXIMO
   scanf("%d %d", &minimo, &maximo);

   //ALOCA NO PONTEIRO VALORES O VETOR COM [tamanho, minimo, maximo, n0, n2, ..., ntamanho-1]
   int *valores = criarVetorAleatorio(tamanho, minimo, maximo);

   //RECEBE O VETOR E RETORNA UM VETOR COM A QUANTIDADE DE VEZES QUE UM NÚMERO APARECE;
   int *histograma = criarHistograma(valores);

   //RECEBE O VETOR COM A QUANTIDADE DE CADA NÚMERO
   float *porcentagens = criarPorcentagens(histograma);

    //RECEBE O VETOR COM AS PORCENTAGENS E HISTOGRAMA E IMPRIME NA TELA
   imprimePorcentagens(porcentagens, histograma);

   //RECEBE OS VETORES PARA LIBERAR A MEMORIA ALOCADA NELE
   liberar(valores, porcentagens, histograma);

   return 0;
}