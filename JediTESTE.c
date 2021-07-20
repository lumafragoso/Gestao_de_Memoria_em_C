#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** separa(char* str, int* quantidadeTextos){
    char **textoSeparado;
    char *texto = strtok(str," ");
    int cont = 0;

    while(texto != NULL){
        //PRIMEIRO CASO
        if(cont == 0){
            textoSeparado= malloc(sizeof(char*));
        }
        //SEM SER O PRIMEIRO CASO PARA REALOCAR
        else{
            textoSeparado[cont] = realloc(textoSeparado, sizeof(char*) * (cont + 1));

        }
        textoSeparado[cont] = texto;

        //ATUALIZAÇÃO
        cont ++;

        //ANDAR NO VETOR
        texto = strtok(NULL," ");
    }
    //PASSAR O TAMANHO DO VETOR
    *quantidadeTextos = cont;

    return textoSeparado;
}

char* embaralha(char* T){
    const int S=5940;
    int k=0, *N=0, n=0, j=0, para=0, i=0, count=0;
    int l=1, p=0;
    char **E;

    N=malloc(sizeof(int));

    char **M= separa(T, N);

    //INICIALIZAR COM VALOR SEMENTE
    srand(S);
    
    //SORTEIO DO RANDOM E COLOCAR NA STRING
    do{
        //SORTEAR O NUMERO
        n = rand();

        //PREENCHER E[]
        if(k==0){
            E = malloc(sizeof(char*));
        }
        else{
            E = realloc(E, sizeof(char*) * (k + 1));
        }

        E[k] = NULL;

		E[k] =malloc(sizeof(char*)* (strlen(M[n % *N])+1));

		E[k] = M[n % *N];

        printf("E: %s\n", E[k]);

        for (i = 0; i < *N; i++){
            for (j = 0; j < k; j++){
                //JA FOI REPETIDO A PALAVRA
                if(para == 1){
                    j= k-1;
                }
                //A PALAVRA AINDA NÃO FOI REPETIDA
                else if(para==0){
                    //CASO AS PALAVRAS SEJAM IGUAIS
                    if(M[i] == E[j]){
                        count++; 
                        para = 1;
                    }
                }
            }
        }
        if(count == *N){
            p=1;
        }
        para=0;
        count=0;
        k++;
    }
    while(p==0);
}

int main(){
    char string[501]; //500 + \0

    fgets(string, 501, stdin);

    embaralha(string);

    return 0;
}